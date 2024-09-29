#pragma once
#include <cstdint>


template <int Tsize>
struct USBBuffer{
    uint8_t event[Tsize];

    uint8_t mBegin = 0;
    uint8_t mEnd = 0;

    uint8_t size();

    uint8_t* begin();

    uint8_t* end();

    void increase(uint8_t s);
    
    template<typename T>
    T* read();

    template<typename T>
    T* read(uint8_t usb_endpoint);

    template<typename T>
    T* peek();

    template<typename T>
    T* peek(uint8_t usb_endpoint);

    void finalize();

    int available();
    
    int readUSB(uint8_t usb_endpoint);

};

