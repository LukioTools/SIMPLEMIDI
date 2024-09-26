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
        Serial.print("Pitch bend change slider: ");
        Serial.print(basic.getChannel());
        Serial.print(" value: ");
        Serial.println(MIDI::getShort(basic.mData));
    }else if(basic.getCommand() == MIDI::ControlModeChange){
        Serial.print("Control mode change channel: ");
        Serial.print(basic.getChannel());
        Serial.print(" device: ");
        Serial.print(basic.mData[0]);
        Serial.print(" value: ");
        Serial.println(basic.mData[1]);
    }


    if(Serial.available()){
        byte b = Serial.read();
        if(b == 'w'){
            Serial.println("-----------------------");
            delay(1000);
            MIDI::sendKey(USBMIDI, 0, MIDI::MCU::PLAY, 127);
            Serial.println("done");
            delay(1000);

        }
    }


    
}
