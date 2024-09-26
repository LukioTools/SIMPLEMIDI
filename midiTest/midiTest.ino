#include <midi_serialization.h>
#include <usbmidi.h>
#include "MidiSpec.hpp"

MIDI::Basic basic;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}


void loop() {

    if(basic.read(USBMIDI)) return;
    if(basic.getCommand() == MIDI::PitchBendChange){
        Serial.print("Slider: ");
        Serial.print(basic.getChannel());
        Serial.print(" value: ");
        Serial.println(MIDI::getShort(basic.mData));
    }else if(basic.getCommand() == MIDI::ControlModeChange){
        Serial.print("Control mode change channel: ");
        Serial.print(basic.getChannel());
        Serial.print(" Device: ");
        Serial.print(basic.mData[0]);
        Serial.print(" Value: ");
        Serial.println(basic.mData[1]);
    }


    
    USBMIDI.flush();
}
