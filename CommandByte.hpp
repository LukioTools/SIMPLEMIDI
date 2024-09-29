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


    struct CommandByte{

        static inline CommandByte make(Command c, unsigned char channel){
            return {static_cast<unsigned char>(0b10000000 | (c<<4) | (channel & 0xF))};
        }

        unsigned char mCommandByte;

        Command getCommand() const{
            return static_cast<Command>((mCommandByte>>4) & 0b111);
        }
        unsigned char getChannel() const{
            return mCommandByte & 0xF;
        }
        unsigned char getDataByteCount() const{
            switch (getCommand()) {
                case NoteOFF: 
                case NoteON: 
                case PolyphonicAftertouch:  
                case PitchBendChange: return 2;

                case ProgramChange: 
                case ChannelAftertouch: return 1;

                case ControlModeChange: return 2; // see spec

                case SystemMessage: switch (getChannel()) {
                        case SystemExclusive: return -1; // Variable
                        case SongSelect:    return 1;
                        case SongPositionPointer: return 2;
                        case TuneRequest:  
                        case EndOfSysEx:   
                        case TimingClock:  
                        case Start:        
                        case Continue:     
                        case Stop:         
                        case ActiveSensing:
                        case SystemReset:   return 0;

                        case MIDITimeCodeQtrFrame: return 2; //see spec

                        case Undefined0: 
                        case Undefined1: 
                        case Undefined2:   
                        case Undefined3: return  -1;  
                    }
                default:
                    return -1;
            }
        }
        static Command getCommand(unsigned char mCommandByte){
            return static_cast<Command>((mCommandByte>>4) & 0b111);
        }
        static unsigned char getChannel(unsigned char mCommandByte){
            return mCommandByte & 0xF;
        }
    };

}