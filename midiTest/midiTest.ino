


#include "MIDIUSB.hpp"

MIDI_USB MidiUSB;

void setup() {
    Serial.begin(9600);
    MidiUSB.begin();
}

void loop() {
    //MidiUSB.poll();
    Serial.println("data: ");
    while (byte* rx = MidiUSB.read<byte>()) {
        Serial.println(*rx);
    }

    MidiUSB.finalize();
}
