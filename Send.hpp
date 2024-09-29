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

#include "CommandByte.hpp"
#include "Enums.hpp"
#include "CableByte.hpp"
#include "Event.hpp"
#include "FP2_16.hpp"

#ifndef ARDUINO
#include <cstdint>
#endif


namespace MIDI {
    inline unsigned char capData(unsigned char v){
        return v & 0b01111111;
    }



    template<CodeIndex cin, Command cmd, typename MIDI_API>
    inline bool send(MIDI_API& midi, unsigned char dataByte1, unsigned char dataByte2, unsigned char channel = 0, unsigned char cable = 0){
        return midi.write(Event{
            CableByte(cin, cable),
            CommandByte::make(cmd, channel),
            capData(dataByte1),
            capData(dataByte2),
        });
    }

    template<typename T>
    inline bool sendNoteON(T& midi, unsigned char channel, MCU::NoteMapping note, unsigned char velocity){
        send<CodeIndex::NOTE_ON, Command::NoteON>(midi, note, velocity, channel);
        /*
        midi.write(Output {  
            CableByte(CodeIndex::NOTE_ON).mCableByte, 
            CommandByte::make(Command::NoteON, channel).mCommandByte, 
            capData(note), 
            capData(velocity)
        });
        */
    }

    template<typename T>
    inline bool sendNoteOFF(T& midi, unsigned char channel, MCU::NoteMapping note, unsigned char velocity){
        send<CodeIndex::NOTE_OFF, Command::NoteOFF>(midi, note, velocity, channel);
        /*
        midi.write(Output{
            CableByte(CodeIndex::NOTE_OFF).mCableByte,
            CommandByte::make(Command::NoteOFF, channel).mCommandByte,
            capData(note), 
            capData(velocity)
        });
        */
    }

    template<typename T>
    inline bool sendControl(T& midi, unsigned char channel, MCU::ControlMapping control, unsigned char value){
        send<CodeIndex::CTRL_CHANGE, Command::ControlModeChange>(midi, control, value, channel);
        /*
        midi.write(Output{
            CableByte(CodeIndex::CTRL_CHANGE).mCableByte, 
            CommandByte::make(Command::ControlModeChange, channel).mCommandByte, 
            capData(control), 
            capData(value)
        });
        */
    }

    template<typename T>
    inline bool sendPitch(T& midi, MCU::PitchBendMapping channel, unsigned char lsb, unsigned char msb){
        send<CodeIndex::PITCH_CHANGE, Command::PitchBendChange>(midi, lsb, msb, channel);
        /*
        midi.write(Output{
            CableByte(CodeIndex::PITCH_CHANGE).mCableByte, 
            CommandByte::make(Command::PitchBendChange, channel).mCommandByte, 
            capData(lsb), 
            capData(msb)
        });
        */
    }

    template<typename T>
    inline bool sendPitch(T& midi, MCU::PitchBendMapping channel, fp_2_14 lsb_msb_14bit){
        send<CodeIndex::PITCH_CHANGE, Command::PitchBendChange>(midi, static_cast<uint8_t>(lsb_msb_14bit & 0b01111111), lsb_msb_14bit >> 7, channel);
        /*
        midi.write(Output{
            CableByte(CodeIndex::PITCH_CHANGE).mCableByte, 
            CommandByte::make(Command::PitchBendChange, channel).mCommandByte, 
            static_cast<uint8_t>(lsb_msb_14bit & 0b01111111), 
            capData(lsb_msb_14bit >> 7),
        });
        */
    }


}