


#include "MIDIUSB.hpp"
#include "Keyboard.h"

#include "MidiSpec.hpp"


MIDI_USB MidiUSB;

#define PLAYBTN PD2 
MIDI::DeviceControl::NoteBtn<MIDI_USB> playBtn(MidiUSB, 0, MIDI::MCU::NoteMapping::STOP, 127);

#define SLIDER1_CLK A0
#define SLIDER1_DT A1
MIDI::DeviceControl::NoteRotaryEncoder<MIDI_USB> slider1(MidiUSB, MIDI::MCU::PitchBendMapping::FADER_POSITION_MASTER, 100);


void setup() {
    Serial.begin(115200);
    MidiUSB.begin();
    Keyboard.begin();

    pinMode(PLAYBTN, INPUT);
    pinMode(SLIDER1_CLK, INPUT);
    pinMode(SLIDER1_DT, INPUT);
}

void loop() {
    
    while (byte* rx = MidiUSB.read<byte>()) {
        Serial.print("data ");
        Serial.println(*rx);
    }

    if(Serial.available()){
        char c = Serial.read();
        Keyboard.write(c+1);
    }

    //MidiUSB.write();
    //MidiUSB.flush();
    playBtn.run(digitalRead(PLAYBTN));
    slider1.run(Serial, digitalRead(SLIDER1_CLK), digitalRead(SLIDER1_DT));
}
