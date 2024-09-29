


#include "MIDIUSB.hpp"
#include "Keyboard.h"

#include "MidiSpec.hpp"


MIDI_USB MidiUSB;

#define PLAYBTN PD2 
MIDI::DeviceControl::NoteBtn<MIDI_USB> playBtn(MidiUSB, 0, MIDI::MCU::NoteMapping::STOP, 127);



void setup() {
    Serial.begin(115200);
    MidiUSB.begin();
    Keyboard.begin();

    pinMode(PLAYBTN, INPUT);
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

    playBtn.run(digitalRead(PLAYBTN));
}
