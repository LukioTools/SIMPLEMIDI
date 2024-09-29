#pragma once

#include <stdint.h>
#include "CableByte.hpp"
#include "CommandByte.hpp"
#include "FP2_16.hpp"



namespace MIDI {

    // represents 4 decimal places
    struct Event : public CableByte, public CommandByte{

        Event(const CableByte cableByte = {}, const CommandByte commandByte = {}, const uint8_t byte1 = 0, const uint8_t byte2 = 0): 
            CableByte{cableByte}, 
            CommandByte{commandByte}, 
            mData{byte1, byte2} {
                static_assert(sizeof(*this) == 4, "Out of spec");
            }

        unsigned char mData[2];

        fp_2_14 dataToFixed(){
            return getFixed(mData);
        }

        unsigned char* begin(){
            return reinterpret_cast<unsigned char*>(this);
        }
        unsigned char* end(){
            return reinterpret_cast<unsigned char*>(this) + sizeof(*this);
        }

#ifdef MIDI_PRINT
#include "Enums.hpp"

            //does not print cable byte
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
                    printable.print(toString(getFixed(mData[0], mData[1])));
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
#endif

        template<typename T>
        void printRaw(T& printable){
            printable.print("{ ");
            printable.print(mCableByte);
            printable.print(", ");
            printable.print(mCommandByte);
            printable.print(", ");
            printable.print(mData[0]);
            printable.print(", ");
            printable.print(mData[1]);
            printable.println(" }");
        }

        bool valid(){
            return mCommandByte & 0b10000000;
        }

    };

}