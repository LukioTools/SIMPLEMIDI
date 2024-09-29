#pragma once
#include <stdint.h>
#include "ACInterfaceDescriptor.hpp"
#include "ASInterfaceDescriptor.hpp"
#include "JackInDescriptor.hpp"
#include "JackOutDescriptor.hpp"
#include "EPDescriptor.hpp"
#include "EP_ACDescriptor.hpp"

#ifndef ARDUINO
#define USBCON
#define ARDUINO_ARCH_AVR
#endif
#if !defined(USBCON)
#error MIDIUSB can only be used with an USB MCU.
#endif

#if !defined(ARDUINO_ARCH_AVR)
#error MIDIUSB can only be used with AVR boards.
#endif


#if ARDUINO
#include "USBCore.h"
#include <avr/interrupt.h>


#include "USBAPI.h"
#include "PluggableUSB.h"
#include <Arduino.h>
#include <stdint.h>
#endif

;
#pragma pack(push, 1)


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

    // yeah... dont ask me...
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
#pragma pack(pop)
