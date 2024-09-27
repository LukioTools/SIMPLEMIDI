#pragma once
#include "MIDIcommandByte.hpp"

namespace MIDI {
    struct Basic : public CommandByte{

        Basic(){ }

        Basic(Command _command, unsigned char _channel){
            makeCommandByte(_command, _channel);
        }

        unsigned char mData[3];

        unsigned char* begin(){
            return mData;
        }
        unsigned char* end(){
            return mData+3;
        }

        template<typename t>
        bool read(t& midi){
            do{ 
                midi.poll();
                mCommandByte = midi.read();
            } while(mCommandByte < 128);
            
            unsigned char byteCount = getDataByteCount();
            
            if(byteCount == static_cast<unsigned char>(-1)) return true;

            for (int i = 0; i < byteCount; i++) {
                midi.poll();
                mData[i] = midi.read();
            }

            return false;
        }
        template<typename T>
        void print(T& printable){
            switch (getCommand()) {
                case NoteOFF: {
                    printable.print("NoteOFF[");
                    printable.print(getChannel());
                    printable.print("]{ Note: ");
                    printable.print(MCU::toString(static_cast<MCU::NoteMapping>(mData[0])));
                    printable.print(", Velocity: ");
                    printable.print(mData[1]);
                    printable.println(" }");
                    return;
                }
                case NoteON: {
                    printable.print("NoteON[");
                    printable.print(getChannel());
                    printable.print("]{ Note: ");
                    printable.print(MCU::toString(static_cast<MCU::NoteMapping>(mData[0])));
                    printable.print(", Velocity: ");
                    printable.print(mData[1]);
                    printable.println(" }");
                    return;
                }
                case PolyphonicAftertouch: {
                    printable.print("PolyphonicAftertouch[");
                    printable.print(getChannel());
                    printable.print("]{ Note: ");
                    printable.print(MCU::toString(static_cast<MCU::NoteMapping>(mData[0])));
                    printable.print(", Pressure: ");
                    printable.print(mData[1]);
                    printable.println(" }");
                    return;
                }
                case ControlModeChange: {
                    printable.print("ControlModeChange[");
                    printable.print(getChannel());
                    printable.print("]{ Device[");
                    printable.print(mData[0]);
                    printable.print("]: ");
                    printable.print(MCU::toString(static_cast<MCU::ControlMapping>(mData[0])));
                    printable.print(", Value: ");
                    printable.print(mData[1]);
                    printable.println(" }");
                }
                case ProgramChange: {
                    printable.print("ProgramChange[");
                    printable.print(getChannel());
                    printable.print("]{ Program: ");
                    printable.print(mData[0]);
                    printable.println(" }");
                }
                case ChannelAftertouch: {
                    printable.print("ChannelAftertouch[");
                    printable.print(getChannel());
                    printable.print("]{ Pressure: ");
                    printable.print(mData[1]);
                    printable.println(" }");
                    return;
                }
                case PitchBendChange: {
                    printable.print("PitchBendChange[");
                    printable.print(getChannel());
                    printable.print("]{ FaderName: ");
                    printable.print(MCU::toString(static_cast<MCU::PitchBendMapping>(getChannel())));
                    printable.print(" Value: ");
                    printable.print(getShort(mData[0], mData[1]));
                    printable.println(" }");
                }
                case SystemMessage: {
                    printable.print("SystemMessage[");
                    printable.print(getChannel());
                    printable.print("]{ Message: ");
                    printable.print(toString(static_cast<SystemMessages>(getChannel())));
                    //printable.print(" Value: ");
                    //printable.print(mData[0]);
                    printable.println(" }");
                }
            }
        }
    };

}