#include <midi_serialization.h>
#include <usbmidi.h>
#include "MidiSpec.hpp"


MIDI::Exclusive exclusive;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
	USBMIDI.poll();

    MIDI::Basic basic;
    basic.mCommandByte = USBMIDI.read();
    int c = basic.getDataByteCount();
    
    if(c != -1) { 
        for (int i = 0; i < c; i++) {
            USBMIDI.poll();
            basic.mData[i] = USBMIDI.read();
        }
    } else {
        MIDI::Exclusive exclusive;
        int counter = 0;
        while (true) {
            counter++;
        }
    }

    if(basic.getCommand() != MIDI::ChannelAftertouch){
        Serial.print(basic.getCommandName());
        Serial.print(" ");
        Serial.println(basic.getChannel());
    }

	USBMIDI.flush();
}
