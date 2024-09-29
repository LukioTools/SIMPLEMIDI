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


#pragma once

#include <stdint.h>
#if !defined(USBCON)
//#error MIDIUSB can only be used with an USB MCU.
#endif

#if !defined(ARDUINO_ARCH_AVR)
//#error MIDIUSB can only be used with AVR boards.
#endif

#ifndef ARDUINO
int USB_Available(int);
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
        return Tsize - mEnd;
    }

    
    int readUSB(uint8_t usb_endpoint){
        finalize();
        if(!USB_Available(usb_endpoint)) {
            return 0;
        }

        int c = USB_Recv(usb_endpoint, end(), available());
        if(c > 0)
            increase(c);
        
        return c;
    }

};