#include <stdint.h>
#include "MIDIenums.hpp"
#pragma once
#include "MIDIcommandByte.hpp"

using fp_2_14 = unsigned short;

namespace MIDI {

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

    struct Basic : public CommandByte{

        Basic(){ }

        Basic(Command _command, unsigned char _channel){
            makeCommandByte(_command, _channel);
        }

        Basic(CommandByte _command, uint8_t byte1, uint8_t byte2, uint8_t byte3) : CommandByte(_command) {
            mData[0] = byte1;
            mData[1] = byte2;
            mData[2] = byte3;
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
                    return;
                }
                case ProgramChange: {
                    printable.print("ProgramChange[");
                    printable.print(getChannel());
                    printable.print("]{ Program: ");
                    printable.print(mData[0]);
                    printable.println(" }");
                    return;
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
                    printable.print(toString(getShort(mData[0], mData[1])));
                    printable.println(" }");
                    return;
                }
                case SystemMessage: {
                    printable.print("SystemMessage[");
                    printable.print(getChannel());
                    printable.print("]{ Message: ");
                    printable.print(toString(static_cast<SystemMessages>(getChannel())));
                    //printable.print(" Value: ");
                    //printable.print(mData[0]);
                    printable.println(" }");
                    return;
                }
            }
        }
    };

}