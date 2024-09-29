#pragma once

#include "../lib/Control.hpp"

namespace DeviceControl {

    template<typename MIDI_API, MCU::NoteMapping Note, unsigned char Channel, unsigned char Velocity>
    NoteBtn<MIDI_API, Note, Channel, Velocity>::NoteBtn(){}

    template<typename MIDI_API, MCU::NoteMapping Note, unsigned char Channel, unsigned char Velocity>
    NoteBtn<MIDI_API, Note, Channel, Velocity>::NoteBtn(MIDI_API& _midi) : mMidi(_midi){}

    template<typename MIDI_API, MCU::NoteMapping Note, unsigned char Channel, unsigned char Velocity>
    void NoteBtn<MIDI_API, Note, Channel, Velocity>::run(const bool& _currentState){
        if(_currentState == true && mLastState == false){
            sendNoteON(mMidi, Channel, Note, Velocity);
            mMidi.flush();
            mLastState = true;
        }else if(_currentState == false && mLastState == true){
            mLastState = false;
        }
    }

    template<typename MIDI_API, MCU::PitchBendMapping Channel>
    PitchRotaryEncoder<MIDI_API, Channel>::PitchRotaryEncoder(){}

    template<typename MIDI_API, MCU::PitchBendMapping Channel>
    PitchRotaryEncoder<MIDI_API, Channel>::PitchRotaryEncoder(MIDI_API& _midi, int _resolution) : mMidi(_midi), mResolution(_resolution){}

    template<typename MIDI_API, MCU::PitchBendMapping Channel>
    void PitchRotaryEncoder<MIDI_API, Channel>::setCounter(fp_2_14 count){
        if (count < 0) {
            mCounter = 0;
        }else if (count > FP_2_14_MAX) {
            mCounter = FP_2_14_MAX;
        }else{
            mCounter = count;
        }
    }

    template<typename MIDI_API, MCU::PitchBendMapping Channel>
    bool PitchRotaryEncoder<MIDI_API, Channel>::run(const bool& clockState, const bool& dataState){

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

    template<typename MIDI_API, MCU::PitchBendMapping Channel>
    void PitchRotaryEncoder<MIDI_API, Channel>::updateValue(Event& basic){
        if(basic.getCommand() == Command::PitchBendChange && basic.getChannel() == Channel)
            mCounter = basic.dataToFixed();
    }
}

namespace SoftwareControl {

    template<typename T>
    NoteBtn<T>::NoteBtn(){}
    NoteBtn(t& _midi, unsigned char _channel, MCU::NoteMapping _note, unsigned char _velocity, unsigned char _input) : midi(_midi),channel(_channel),  note(_note), velocity(_velocity), input(_input){}

    virtual bool run(const char& _char){
        if(input != _char) return true;

        sendNoteON(midi, channel, note, velocity);
        midi.flush();

        return false;
    }
}






