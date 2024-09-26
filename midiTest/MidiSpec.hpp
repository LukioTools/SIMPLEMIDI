#pragma once

#include "MIDIenums.hpp"
#include "MIDIsend.hpp"


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
            unsigned char channel;

            t& midi;
            NoteRotaryEncoder(){}
            NoteRotaryEncoder(t& _midi, unsigned char _channel) : midi(_midi),channel(_channel){}

            void setCounter(){}


            template<typename SerialT>
            bool run(SerialT& Serial, const bool& aState, const bool& bState){
                if(aState != lastState) return true;
                if(bState != aState) counter ++;
                else counter--;
                lastState = aState;

                
                if(counter < 0) {
                    counter = 0;
                }

                if(counter > 16384){
                    counter = 16384;
                }

                Serial.println(counter);
                sendPitch(midi, channel, counter);
                

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

            bool run(const char& _char){
                if(input != _char) return true;

                sendNoteON(midi, channel, note, velocity);
                midi.flush();

                return false;
            }
        };
    }

    
    

    
    
    
}
