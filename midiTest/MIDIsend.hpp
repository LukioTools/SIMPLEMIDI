#pragma once

#include "MIDIcommandByte.hpp"
#include "MIDIenums.hpp"
#include "MIDIbasic.hpp"
#ifndef ARDUINO
#include <cstdint>
#endif


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

    typedef struct
    {
        uint8_t header;
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
    } eee;


    template<typename T>
    inline bool sendNoteON(T& midi, unsigned char channel, MCU::NoteMapping note, unsigned char velocity){
        //eee b{CommandByte::make(Command::NoteON, channel).mCommandByte,(CommandByte::make(Command::NoteON, channel).mCommandByte << 4) | channel, capData(note), capData(velocity)};
        eee b{(Command::PitchBendChange<<4) | 128 | 2, 127, 127, 0x08};
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


}