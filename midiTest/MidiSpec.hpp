#pragma once

#include "MIDIenums.hpp"
#include "MIDIsend.hpp"
#include "MIDIbasic.hpp"

namespace MIDI {

    namespace DeviceControl {
        template<typename t>
        struct NoteBtn{
            bool lastState = false;
            unsigned char channel;
            MCU::NoteMapping note;
            char velocity;
            t& midi;
            NoteBtn(){}
            NoteBtn(t& _midi, unsigned char _channel, MCU::NoteMapping _note, unsigned char _velocity) : midi(_midi),channel(_channel),  note(_note), velocity(_velocity){}

            bool run(const bool& _currentState){
                if(_currentState == true && lastState == false){
                    sendNoteON(midi, channel, note, velocity);
                    midi.flush();
                    lastState = true;
                }else if(_currentState == false && lastState == true){
                    lastState = false;
                }

                return false;
            }
        };

        template<typename t>
        struct NoteRotaryEncoder{
            bool lastState = false;
            int counter;
            int lastCounter;
            MCU::PitchBendMapping channel;

            int resolution;

            t& midi;
            NoteRotaryEncoder(){}
            NoteRotaryEncoder(t& _midi, MCU::PitchBendMapping _channel, int _resolution) : midi(_midi),channel(_channel), resolution(_resolution){}

            void setCounter(){}


            template<typename SerialT>
            bool run(SerialT& Serial, const bool& aState, const bool& bState){

                if(aState != lastState && aState == 1){
                
                    if(bState != aState){
                        counter -= resolution;
                    }else {
                        counter += resolution;
                    }

                    if(counter < 0) counter = 0;
                    if(counter > 16384) counter = 16384;

                    Serial.print("channel ");
                    Serial.print(channel);
                    Serial.print(" counter ");
                    Serial.println(counter);
                    sendPitch(midi, channel, counter);
                    midi.flush();
                }

                lastState = aState;
                

            }

            void updateValue(Basic& basic){
                if(basic.getCommand() == Command::PitchBendChange && basic.getChannel() == channel)
                    counter = getShort(basic.mData[0], basic.mData[1]);
            }
        };
    }

    namespace SoftwareControl {
        template<typename t>
        struct NoteBtn{
            unsigned char input;
            unsigned char channel;
            MCU::NoteMapping note;
            char velocity;

            t& midi;

            NoteBtn(){}
            NoteBtn(t& _midi, unsigned char _channel, MCU::NoteMapping _note, unsigned char _velocity, unsigned char _input) : midi(_midi),channel(_channel),  note(_note), velocity(_velocity), input(_input){}

            virtual bool run(const char& _char){
                if(input != _char) return true;

                sendNoteON(midi, channel, note, velocity);
                midi.flush();

                return false;
            }
        };
    }

    
    

    
    
    
}
