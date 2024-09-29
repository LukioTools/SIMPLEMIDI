#pragma once
#include <stdint.h>

#ifndef ARDUINO
#define PROGMEM 
using size_t = unsigned short;
#endif

#define FP_2_14_MAX 16384
#define FP_2_14_TO_STRING_DECIMAL_PLACES 4


using fp_2_14 = uint16_t;
namespace MIDI {

    
    char loadedNumber[7] = {'0','.','0','0','0','0', 0};

    inline const char* toString(fp_2_14 fp){
        loadedNumber[0] = '0'+(fp>>14);
            //trust me bro
        uint32_t fract = (uint32_t(fp&0b0011111111111111) * 10000)/FP_2_14_MAX;
        for(size_t i = 0; i < FP_2_14_TO_STRING_DECIMAL_PLACES; i++){
            loadedNumber[sizeof(loadedNumber)-2 - i] = '0' + fract%10;
            fract/=10;
        }
        loadedNumber[sizeof(loadedNumber)-1] = 0;
        return loadedNumber;
    }

    inline fp_2_14 getFixed(unsigned char lsb, unsigned char msb){
        unsigned short s = msb;
        s<<=7;
        s|=lsb;
        return s;
    }

    inline fp_2_14 getFixed(unsigned char* lsb_msb){
        unsigned short s = lsb_msb[1];
        s<<=7;
        s|=lsb_msb[0];
        return s;
    }
}