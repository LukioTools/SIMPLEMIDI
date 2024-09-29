#pragma once
#include "../lib/USBBuffer.hpp"
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

#ifndef  USB_EP_SIZE
#define USB_EP_SIZE 64
#endif



template <int Tsize>
uint8_t USBBuffer<Tsize>::size(){return mEnd - mBegin;}

template <int Tsize>
uint8_t* USBBuffer<Tsize>::begin(){
    return event+mBegin;
}

template <int Tsize>
uint8_t* USBBuffer<Tsize>::end(){
    return event+mEnd;
}

template <int Tsize>
void USBBuffer<Tsize>::increase(uint8_t s) { mEnd+=s; }
    
template <int Tsize>
template<typename T>
T* USBBuffer<Tsize>::read(){
    auto p = peek<T>();
    if(p)
        mBegin+=sizeof(T);
    return p;
}

template <int Tsize>
template<typename T>
T* USBBuffer<Tsize>::read(uint8_t usb_endpoint){
    auto p = peek<T>(usb_endpoint);
    if(p)
        mBegin+=sizeof(T);
    return p;
}

template <int Tsize>
template<typename T>
T* USBBuffer<Tsize>::peek(){
    if(sizeof(T) > size()) return nullptr;
    T* t = reinterpret_cast<T*>(begin());
    return t;
}

template <int Tsize>
template<typename T>
T* USBBuffer<Tsize>::peek(uint8_t usb_endpoint){
    if(sizeof(T) > size()){
        readUSB(usb_endpoint);
        
        if(sizeof(T) > size()) 
            return nullptr;
    } 
    T* t = reinterpret_cast<T*>(begin());
    return t;
}

template <int Tsize>
void USBBuffer<Tsize>::finalize(){
    if(mBegin == 0) return;

    uint8_t s = size();
    for (int i = 0; i < s; i++) {
        event[i] = event[mBegin+i];
    }
    mBegin = 0;
    mEnd = s;
}

template <int Tsize>
int USBBuffer<Tsize>::available(){
    return USB_EP_SIZE - mEnd;
}

    
template <int Tsize>
int USBBuffer<Tsize>::readUSB(uint8_t usb_endpoint){
    finalize();
    if(!USB_Available(usb_endpoint)) {
        return 0;
    }

    int c = USB_Recv(usb_endpoint, end(), available());
    if(c > 0)
        increase(c);
    
    return c;
}

