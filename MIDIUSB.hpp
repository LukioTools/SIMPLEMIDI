/*
** Copyright (c) 2024, Albert Laine (and Vili kervinen)
** Permission to use, copy, modify, and/or distribute this software for
** any purpose with or without fee is hereby granted, provided that the
** above copyright notice and this permission notice appear in all copies.
**
** THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
** WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR
** BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES
** OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
** WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
** ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
** SOFTWARE.
*/



#include <string.h>
#pragma once

#if !defined(USBCON)
#error MIDIUSB can only be used with an USB MCU.
#endif

#if !defined(ARDUINO_ARCH_AVR)
#error MIDIUSB can only be used with AVR boards.
#endif

#include "USBCore.h"
#include <avr/interrupt.h>


#include "USBAPI.h"
#include "PluggableUSB.h"
#include <Arduino.h>
#include <stdint.h>

#ifndef ARDUINO
#include <cstdint>
#endif

#include "USBBuffer.hpp"


#define MIDI_AC_INTERFACE 	pluggedInterface	// MIDI AC Interface
#define MIDI_INTERFACE 		((uint8_t)(pluggedInterface+1))
#define MIDI_FIRST_ENDPOINT pluggedEndpoint
#define MIDI_ENDPOINT_OUT	pluggedEndpoint
#define MIDI_ENDPOINT_IN	((uint8_t)(pluggedEndpoint+1))



#define MIDI_RX MIDI_ENDPOINT_OUT
#define MIDI_TX MIDI_ENDPOINT_IN

#define is_write_enabled(x)			(1)

#define EP_TYPE_BULK_IN_MIDI 		EP_TYPE_BULK_IN
#define EP_TYPE_BULK_OUT_MIDI 		EP_TYPE_BULK_OUT



#define MIDI_AUDIO								0x01    //(USB interface: Audio)    https://developerhelp.microchip.com/xwiki/bin/view/applications/usb/how-it-works/device-classes/
#define MIDI_AUDIO_CONTROL						0x01 	//(USB interface: Audio)    https://developerhelp.microchip.com/xwiki/bin/view/applications/usb/how-it-works/device-classes/

#define MIDI_CS_INTERFACE						0x24 	// https://warrantyvoids.github.io/ModSynth/modules/midi2cv/midi-descriptor
#define MIDI_CS_ENDPOINT						0x25 	// https://warrantyvoids.github.io/ModSynth/modules/midi2cv/midi-descriptor

#define MIDI_STREAMING							0x3 	// https://www.usb.org/sites/default/files/USB%20MIDI%20v2_0.pdf
#define MIDI_JACK_EMD							0x01  	// https://www.usb.org/sites/default/files/USB%20MIDI%20v2_0.pdf
#define MIDI_JACK_EXT							0X02 	// https://www.usb.org/sites/default/files/USB%20MIDI%20v2_0.pdf


#define D_AC_INTERFACE(_streamingInterfaces, _MIDIInterface) \
	{9, MIDI_CS_INTERFACE, 0x1, 0x0100, 0x0009, _streamingInterfaces, (uint8_t)(_MIDIInterface) }

#define D_AS_INTERFACE \
	{ 0x7, MIDI_CS_INTERFACE, 0x01,0x0100, 0x0041}

#define D_MIDI_INJACK(jackProp, _jackID) \
	{ 0x06, MIDI_CS_INTERFACE, 0x02, jackProp, _jackID, 0  }

#define D_MIDI_OUTJACK(jackProp, _jackID, _nPins, _srcID, _srcPin) \
	{ 0x09, MIDI_CS_INTERFACE, 0x3, jackProp, _jackID, _nPins, _srcID, _srcPin, 0  }

#define D_MIDI_JACK_EP(_addr,_attr,_packetSize) \
	{ 9, 5, _addr,_attr,_packetSize, 0, 0, 0}

#define D_MIDI_AC_JACK_EP(_nMIDI, _iDMIDI) \
	{ 5, MIDI_CS_ENDPOINT, 0x1, _nMIDI, _iDMIDI}

#define D_CDCCS(_subtype,_d0,_d1)	{ 5, 0x24, _subtype, _d0, _d1 }
#define D_CDCCS4(_subtype,_d0)		{ 4, 0x24, _subtype, _d0 }


using epTypeT = uint8_t;

struct midiEventPacket_t {
	uint8_t header;
	uint8_t byte1;
	uint8_t byte2;
	uint8_t byte3;
};



_Pragma("pack(1)")
struct MIDI_ACInterfaceDescriptor {
	uint8_t len;		// 9
	uint8_t dtype;		// 4
	uint8_t dsubType;
	uint16_t bcdADc;
	uint16_t wTotalLength;
	uint8_t bInCollection;
	uint8_t interfaceNumbers;
};

struct MIDI_ASInterfaceDescriptor {
	uint8_t len;		// 9
	uint8_t dtype;		// 4
	uint8_t dsubType;
	uint16_t bcdADc;
	uint16_t wTotalLength;
};

struct MIDIJackinDescriptor {
	uint8_t len;		// 9
	uint8_t dtype;		// 4
	uint8_t dsubType;
	uint8_t jackType;
	uint8_t jackID;
	uint8_t jackStrIndex;
};

struct MIDIJackOutDescriptor {
	uint8_t len;		// 9
	uint8_t dtype;		// 4
	uint8_t dsubType;
	uint8_t jackType;
	uint8_t jackID;
	uint8_t nPins;
	uint8_t srcJackID;
	uint8_t srcPinID;
	uint8_t jackStrIndex;
};

struct MIDI_EPDescriptor {
	EndpointDescriptor len;		// 9
	uint8_t refresh;		// 4
	uint8_t sync;
};

struct MIDI_EP_ACDescriptor {
	uint8_t len;		// 5
	uint8_t dtype;		// 0x24
	uint8_t subtype;
	uint8_t embJacks;
	uint8_t jackID;
};

struct MIDIDescriptor {
	//	IAD
	IADDescriptor                      iad;
	// MIDI Audio Control Interface
	InterfaceDescriptor                Audio_ControlInterface;
	MIDI_ACInterfaceDescriptor         Audio_ControlInterface_SPC;

	// MIDI Audio Streaming Interface
	InterfaceDescriptor                Audio_StreamInterface;
	MIDI_ASInterfaceDescriptor         Audio_StreamInterface_SPC;

	MIDIJackinDescriptor               MIDI_In_Jack_Emb;
	MIDIJackinDescriptor               MIDI_In_Jack_Ext;
	MIDIJackOutDescriptor              MIDI_Out_Jack_Emb;
	MIDIJackOutDescriptor              MIDI_Out_Jack_Ext;

	MIDI_EPDescriptor                  MIDI_In_Jack_Endpoint;
	MIDI_EP_ACDescriptor               MIDI_In_Jack_Endpoint_SPC;
	MIDI_EPDescriptor                  MIDI_Out_Jack_Endpoint;
	MIDI_EP_ACDescriptor               MIDI_Out_Jack_Endpoint_SPC;
};


USBBuffer<USB_EP_SIZE> midi_rx_buffer;


class MIDI_USB : public PluggableUSBModule{
    epTypeT epType[2] = {EP_TYPE_BULK_OUT_MIDI, EP_TYPE_BULK_IN_MIDI};


protected:
    int getInterface(uint8_t* interfaceNum) override {
        *interfaceNum += 2;	// uses 2 interfaces
        MIDIDescriptor _midiInterface =
        {
            D_IAD(MIDI_AC_INTERFACE, 2, MIDI_AUDIO, MIDI_AUDIO_CONTROL, 0),
            D_INTERFACE(MIDI_AC_INTERFACE,0,MIDI_AUDIO,MIDI_AUDIO_CONTROL,0),
            D_AC_INTERFACE(0x1, MIDI_INTERFACE),
            D_INTERFACE(MIDI_INTERFACE,2, MIDI_AUDIO,MIDI_STREAMING,0),
            D_AS_INTERFACE,
            D_MIDI_INJACK(MIDI_JACK_EMD, 0x1),
            D_MIDI_INJACK(MIDI_JACK_EXT, 0x2),
            D_MIDI_OUTJACK(MIDI_JACK_EMD, 0x3, 1, 2, 1),
            D_MIDI_OUTJACK(MIDI_JACK_EXT, 0x4, 1, 1, 1),
            D_MIDI_JACK_EP(USB_ENDPOINT_OUT(MIDI_ENDPOINT_OUT),USB_ENDPOINT_TYPE_BULK,USB_EP_SIZE),
            D_MIDI_AC_JACK_EP(1, 1),
            D_MIDI_JACK_EP(USB_ENDPOINT_IN(MIDI_ENDPOINT_IN),USB_ENDPOINT_TYPE_BULK,USB_EP_SIZE),
            D_MIDI_AC_JACK_EP (1, 3)
        };
        return USB_SendControl(0, &_midiInterface, sizeof(_midiInterface));
    }

    int getDescriptor(USBSetup& setup __attribute__((unused)) ) override {return 0;}

    bool setup(USBSetup& setup __attribute__((unused)) ) override {return false;}


    uint8_t getShortName(char* name) override {
        memcpy(name, "MIDI", 4);
        return 4;
    }
    

public:
    MIDI_USB() : PluggableUSBModule(2,2, epType){
        epType[0] = EP_TYPE_BULK_OUT_MIDI;
        epType[1] = EP_TYPE_BULK_IN_MIDI;
    }

    void begin(){
        PluggableUSB().plug(this);
    }

    void poll(){
        midi_rx_buffer.readUSB(MIDI_RX);
    }

    void finalize(){
        midi_rx_buffer.finalize();
    }

    template<typename T>
    T* read() {
        return midi_rx_buffer.read<T>(MIDI_RX);
    }

    void flush(){
        USB_Flush(MIDI_TX);
    }

    template<typename T>
    size_t write(const T& data){
        if(!is_write_enabled(MIDI_TX)) return 0;        // in case no one is listening we are just going to drop packets, USB_Send might freeze in case no one listens.
        int  r = USB_Send(MIDI_TX, &data, sizeof(data));       // return amount sent.

        return r;
    }

};