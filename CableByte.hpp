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

#include "Enums.hpp"
namespace MIDI {

    struct CableByte{
        unsigned char mCableByte;

        CableByte(unsigned char _cableByte = 0) : mCableByte(_cableByte) {}

        CableByte(CodeIndex _codeIndex, unsigned char _cableNumber = 0) : mCableByte((_codeIndex & 0b00001111) | (_cableNumber << 4)) {}

        unsigned char getCableNumber() const{
            return getCable() >> 4;
        }

        CodeIndex getCodeIndex() const{
            return static_cast<CodeIndex>(mCableByte & 0b00001111);
        }

        void setCable(unsigned char _cable){
            mCableByte = getCodeIndex() | (_cable << 4);
        } 

        void setCodeIndex(CodeIndex _codeIndex){
            mCableByte = getCable() | ( _codeIndex & 0b00001111);
        }

    private:
        unsigned char getCable() const{
            return (mCableByte & 0b11110000);
        }
    }; 
}