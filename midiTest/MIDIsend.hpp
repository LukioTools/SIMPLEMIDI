#pragma once

#include "MIDIcommandByte.hpp"
#include "MIDIenums.hpp"
#include "MIDIbasic.hpp"
#ifndef ARDUINO
#include <cstdint>
#endif

using fp_2_14 = unsigned short;
namespace MIDI {
    inline unsigned short getShort(unsigned char lsb, unsigned char msb){
        unsigned short s = msb;
        s<<=7;
        s|=lsb;
        return s;
    }

    inline unsigned short getShort(unsigned char* lsb_msb){
        unsigned short s = lsb_msb[1];
        s<<=7;
        s|=lsb_msb[0];
        return s;
    }


    inline unsigned char capData(unsigned char v){
        return v & 0b01111111;
    }


    template<typename T>
    inline bool sendNoteON(T& midi, unsigned char channel, MCU::NoteMapping note, unsigned char velocity){
        Basic b{CommandByte::make(Command::NoteON, channel), capData(note), capData(velocity), 0};
        b.print(Serial);
        midi.write(b);
        
    }

    template<typename T>
    inline bool sendNoteOFF(T& midi, unsigned char channel, MCU::NoteMapping note, unsigned char velocity){
        midi.write(Basic{CommandByte::make(Command::NoteOFF, channel), capData(note), capData(velocity), 0});
    }

    template<typename T>
    inline bool sendControl(T& midi, unsigned char channel, MCU::ControlMapping control, unsigned char value){
        midi.write(Basic{CommandByte::make(Command::ControlModeChange, channel), capData(control), capData(value), 0});
    }

    template<typename T>
    inline bool sendPitch(T& midi, MCU::PitchBendMapping pitch_channel, unsigned char lsb, unsigned char msb){
        midi.write(Basic{CommandByte::make(Command::PitchBendChange, pitch_channel), capData(lsb), capData(msb), 0});
    }

    template<typename T>
    inline bool sendPitch(T& midi, MCU::PitchBendMapping pitch_channel, fp_2_14 lsb_msb_14bit){
        midi.write(Basic{CommandByte::make(Command::PitchBendChange, pitch_channel), lsb_msb_14bit & 0b01111111, capData(lsb_msb_14bit >> 7), 0});
    }

    // represents 4 decimal places

    constexpr fp_2_14 max = 16384;
    constexpr size_t decimalPlaces = 4;
    char loadedNumber[7] = {'0','.','0','0','0','0', 0};
    const char* toString(fp_2_14 fp){
        loadedNumber[0] = '0'+(fp>>14);
            //trust me bro
        uint32_t fract = (uint32_t(fp&0b0011111111111111) * 10000)/max;
        for(size_t i = 0; i < decimalPlaces; i++){
            loadedNumber[sizeof(loadedNumber)-2 - i] = '0' + fract%10;
            fract/=10;
        }
        loadedNumber[sizeof(loadedNumber)-1] = 0;
        return loadedNumber;
    }
}