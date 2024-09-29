#include "Enums.hpp"
#include "Event.hpp"
#include "FP_2_14.hpp"

namespace DeviceControl {
    template<typename MIDI_API, MCU::NoteMapping Note, unsigned char Channel = 0, unsigned char Velocity = 127>
    struct NoteBtn{
        MIDI_API& mMidi;
        bool mLastState = false;

        NoteBtn();
        NoteBtn(MIDI_API& _midi);

        void run(const bool& _currentState);
    };

    template<typename MIDI_API, MCU::PitchBendMapping Channel>
    struct PitchRotaryEncoder{
        MIDI_API& mMidi;

        bool mLastState = false;
        fp_2_14 mCounter;
        int mLastCounter;

        int mResolution;

        PitchRotaryEncoder();
        PitchRotaryEncoder(MIDI_API& _midi, int _resolution);

        void setCounter(fp_2_14 count);

        void updateValue(Event& basic);


        bool run(const bool& clockState, const bool& dataState);
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

        NoteBtn();
        NoteBtn(t& _midi, unsigned char _channel, MCU::NoteMapping _note, unsigned char _velocity, unsigned char _input) : midi(_midi),channel(_channel),  note(_note), velocity(_velocity), input(_input){}

        virtual bool run(const char& _char);
    };
}
