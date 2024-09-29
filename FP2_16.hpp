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
        return getFixed(lsb_msb[0], lsb_msb[1]);
    }
}