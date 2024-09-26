#pragma once

#include "MIDIcommandByte.hpp"
namespace MIDI {

    constexpr size_t ExclusiveMaxSize = 62;
    constexpr unsigned char EOX = 0b11110111;

    struct Exclusive : public CommandByte{
        unsigned char mData[ExclusiveMaxSize];
        unsigned char mSize = 0;

        unsigned char* begin(){
            return mData;
        }
        unsigned char* end(){
            return mData+mSize;
        }

        inline unsigned char size(){
            return mSize;
        }
        inline bool empty(){
            return mSize == 0;
        }

        inline void clear(){
            mSize = 0;
        }
            //returns 255? if error
        inline unsigned char pop(){
            if (mSize) {
                return mData[mSize--];
            }
            return -1;
        }

        // midi.push_back(MIDIUSB.read()) 
        inline void push_back(unsigned char c){
            if(mSize < ExclusiveMaxSize-1){
                mData[mSize++] = c;
            }
        }

        // midi.emplace() = MIDIUSB.read()
        inline unsigned char& emplace(){
            if(mSize < ExclusiveMaxSize-1){
                return mData[mSize++];
            }
            return mData[mSize];
        }
    };
}