#ifndef ARDUINO
#define USBCON
#define ARDUINO_ARCH_AVR
#include <cstdint>
#endif

#include <string.h>
#pragma once

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


template <int Tsize>
struct USBBuffer{
    uint8_t event[Tsize];
    // [0,0,0,0,0]
    //  |
    //  

    uint8_t mBegin = 0;
    uint8_t mEnd = 0;

    uint8_t size(){
        return mEnd - mBegin;
    }

    uint8_t* begin(){
        return event+mBegin;
    }

    uint8_t* end(){
        return event+mEnd;
    }

    void increase(uint8_t s) { mEnd+=s; }
    
    template<typename T>
    T* read(){
        auto p = peek<T>();
        if(p)
            mBegin+=sizeof(T);
        return p;
    }

    template<typename T>
    T* read(uint8_t usb_endpoint){
        auto p = peek<T>(usb_endpoint);
        if(p)
            mBegin+=sizeof(T);
        return p;
    }

    template<typename T>
    T* peek(){
        if(sizeof(T) > size()) return nullptr;
        T* t = reinterpret_cast<T*>(begin());
        return t;
    }

    template<typename T>
    T* peek(uint8_t usb_endpoint){
        if(sizeof(T) > size()){
            readUSB(usb_endpoint);
            
            if(sizeof(T) > size()) 
                return nullptr;
        } 
        T* t = reinterpret_cast<T*>(begin());
        return t;
    }

    void finalize(){
        if(mBegin == 0) return;

        uint8_t s = size();
        for (int i = 0; i < s; i++) {
            event[i] = event[mBegin+i];
        }
        mBegin = 0;
        mEnd = s;
    }

    int available(){
        return USB_EP_SIZE - mEnd;
    }

    
    int readUSB(uint8_t usb_endpoint){
        finalize();
        if(!USB_Available(usb_endpoint)) {
            return 0;
        }

        midipacket midiEvent;
        int c = USB_Recv(usb_endpoint, end(), available());
        if(c > 0)
            increase(c);
        
        return c;
    }

};




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

extern MIDI_USB MidiUSB;