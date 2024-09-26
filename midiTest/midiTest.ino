#include <midi_serialization.h>
#include <usbmidi.h>
#include "MidiSpec.hpp"


MIDI::Basic basic;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
	//Handle USB communication
	USBMIDI.poll();

	while (USBMIDI.available()) {
		basic.mCommandByte = USBMIDI.read();
        int c = basic.getDataByteCount();
        if(c != -1) for (int i = 0; i < c; i++) {
            USBMIDI.poll();
            basic.mData[i] = USBMIDI.read();
        }

        if(basic.getCommand() != MIDI::ChannelAftertouch){
            Serial.print(basic.getCommandName());
            Serial.print(" ");
            Serial.println(basic.getChannel());
        }

	}

	// Flush the output.
	USBMIDI.flush();
}
