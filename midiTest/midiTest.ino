
#include "MIDI.h"
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

MIDI::Basic basic;

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
    
}
