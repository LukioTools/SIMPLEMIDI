#pragma once

#include "MIDIcommandByte.hpp"

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
        midi.write(CommandByte::make(Command::NoteON, channel).mCommandByte);
        midi.write(capData(note));      //ensures that it is max 127
        midi.write(capData(velocity));  //ensures that it is max 127
    }

    template<typename T>
    inline bool sendNoteOFF(T& midi, unsigned char channel, MCU::NoteMapping note, unsigned char velocity){
        midi.write(CommandByte::make(Command::NoteOFF, channel).mCommandByte);
        midi.write(capData(note));      //ensures that it is max 127
        midi.write(capData(velocity));  //ensures that it is max 127
    }

    template<typename T>
    inline bool sendControl(T& midi, unsigned char channel, MCU::ControlMapping control, unsigned char value){
        midi.write(CommandByte::make(Command::ControlModeChange, channel).mCommandByte);
        midi.write(capData(control));   //ensures that it is max 127
        midi.write(capData(value));     //ensures that it is max 127
    }

    template<typename T>
    inline bool sendPitch(T& midi, MCU::PitchBendMapping pitch_channel, unsigned char lsb, unsigned char msb){
        midi.write(CommandByte::make(Command::PitchBendChange, pitch_channel).mCommandByte);
        midi.write(capData(lsb));   //ensures that it is max 127
        midi.write(capData(msb));     //ensures that it is max 127
    }

    template<typename T>
    inline bool sendPitch(T& midi, MCU::PitchBendMapping pitch_channel, unsigned short lsb_msb_14bit){
        midi.write(CommandByte::make(Command::PitchBendChange, pitch_channel).mCommandByte);
        midi.write(lsb_msb_14bit & 0b01111111);     //ensures that it is max 127
        midi.write(capData(lsb_msb_14bit >> 7));             //ensures that it is max 127
    }
}