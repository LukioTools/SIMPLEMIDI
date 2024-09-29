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
#include "FP2_16.hpp"
#include "Send.hpp"
#include "Event.hpp"

namespace MIDI {

    namespace DeviceControl {
        template<typename MIDI_API, MCU::NoteMapping Note, unsigned char Channel = 0, unsigned char Velocity = 127>
        struct NoteBtn{
            MIDI_API& mMidi;
            bool mLastState = false;

            NoteBtn(){}
            NoteBtn(MIDI_API& _midi) : mMidi(_midi){}

            void run(const bool& _currentState){
                if(_currentState == true && mLastState == false){
                    sendNoteON(mMidi, Channel, Note, Velocity);
                    mMidi.flush();
                    mLastState = true;
                }else if(_currentState == false && mLastState == true){
                    mLastState = false;
                }
            }
        };

        template<typename MIDI_API, MCU::PitchBendMapping Channel>
        struct PitchRotaryEncoder{
            MIDI_API& mMidi;

            bool mLastState = false;
            fp_2_14 mCounter;
            int mLastCounter;

            int mResolution;

            PitchRotaryEncoder(){}
            PitchRotaryEncoder(MIDI_API& _midi, int _resolution) : mMidi(_midi), mResolution(_resolution){}

            void setCounter(fp_2_14 count){
                if (count < 0) {
                    mCounter = 0;
                }else if (count > FP_2_14_MAX) {
                    mCounter = FP_2_14_MAX;
                }else{
                    mCounter = count;
                }
            }


            bool run(const bool& clockState, const bool& dataState){

                if(clockState != mLastState && clockState == 1){
                
                    if(dataState != clockState){
                        if (mCounter < mResolution) {
                            mCounter = 0;
                        }else mCounter -= mResolution;
                    }else{
                        if (mCounter + mResolution > FP_2_14_MAX) {
                            mCounter = FP_2_14_MAX;
                        } else mCounter += mResolution;
                    }

                    sendPitch(mMidi, Channel, mCounter);
                    mMidi.flush();
                }

                mLastState = clockState;
            }

            void updateValue(Event& basic){
                if(basic.getCommand() == Command::PitchBendChange && basic.getChannel() == Channel)
                    mCounter = basic.dataToFixed();
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
