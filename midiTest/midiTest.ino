#include <midi_serialization.h>
#include <usbmidi.h>
#include "MIDIenums.hpp"
#include "MidiSpec.hpp"
#include "MIDIbasic.hpp"

#define PLAY_PIN PD2
MIDI::DeviceControl::NoteBtn<USBMIDI_> playBtn(USBMIDI, 0, MIDI::MCU::PLAY, 127);

#define PAUSE_PIN PD3
MIDI::DeviceControl::NoteBtn<USBMIDI_> stopBtn(USBMIDI, 0, MIDI::MCU::STOP, 127);

#define ROTARY1_CLK A0
#define ROTARY1_DT A1
MIDI::DeviceControl::NoteRotaryEncoder<USBMIDI_> rotarty1(USBMIDI, MIDI::MCU::PitchBendMapping::FADER_POSITION_MASTER, 100);

MIDI::SoftwareControl::NoteBtn<USBMIDI_> playBtnSoftware(USBMIDI, 0, MIDI::MCU::PLAY, 127, 'w');
MIDI::SoftwareControl::NoteBtn<USBMIDI_> stopBtnSoftware(USBMIDI, 0, MIDI::MCU::STOP, 127, 's');

MIDI::Exclusive exclusive;

void setup() {
    //pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    pinMode(PLAY_PIN, INPUT);
    pinMode(PAUSE_PIN, INPUT);

    pinMode(ROTARY1_CLK, INPUT);
    pinMode(ROTARY1_DT, INPUT);

}
unsigned char i = 0;
void loop() {
<<<<<<< HEAD
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
=======
    //Serial.println(MIDI::maxSize);
    //Serial.println(MIDI::MCU::toString(static_cast<MIDI::MCU::NoteMapping>(i++)));
    //if(119 < i)
    //  i = 0;
    //delay(100);
    
    if(USBMIDI.available()){
        if(!basic.read(USBMIDI)){
            rotarty1.updateValue(basic);
        };
    }

    if(Serial.available()){
        byte b = Serial.read();
        playBtnSoftware.run(b);
        stopBtnSoftware.run(b);
    }

    playBtn.run(digitalRead(PLAY_PIN));
    stopBtn.run(digitalRead(PAUSE_PIN));

    rotarty1.run(Serial, digitalRead(ROTARY1_CLK),digitalRead(ROTARY1_DT));

    delay(1);
    
>>>>>>> b16341e5f40f0e47262fba7e9130b2858f1fbea1
}
