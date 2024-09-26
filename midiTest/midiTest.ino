#include <midi_serialization.h>
#include <usbmidi.h>
#include "MIDIenums.hpp"
/*
#define PLAY_PIN PD2
MIDI::DeviceControl::NoteBtn<USBMIDI_> playBtn(USBMIDI, 0, MIDI::MCU::PLAY, 127);

#define PAUSE_PIN PD3
MIDI::DeviceControl::NoteBtn<USBMIDI_> stopBtn(USBMIDI, 0, MIDI::MCU::STOP, 127);

#define ROTARY1_CLK D7
#define ROTARY1_DT D8
MIDI::DeviceControl::NoteRotaryEncoder<USBMIDI_> rotarty1(USBMIDI, 0, )

MIDI::SoftwareControl::NoteBtn<USBMIDI_> playBtnSoftware(USBMIDI, 0, MIDI::MCU::PLAY, 127, 'w');
MIDI::SoftwareControl::NoteBtn<USBMIDI_> stopBtnSoftware(USBMIDI, 0, MIDI::MCU::STOP, 127, 's');

MIDI::Basic basic;


void printPitch(MIDI::Basic& basic){
    Serial.print("Pitch bend change slider: ");
    Serial.print(basic.getChannel());
    Serial.print(" value: ");
    Serial.println(MIDI::getShort(basic.mData));
}

void printControlModeChange(MIDI::Basic& basic){
    Serial.print("Control mode change channel: ");
    Serial.print(basic.getChannel());
    Serial.print(" device: ");
    Serial.print(basic.mData[0]);
    Serial.print(" value: ");
    Serial.println(basic.mData[1]);
}
*/
void setup() {
    //pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    //pinMode(PLAY_PIN, INPUT);
    //pinMode(PAUSE_PIN, INPUT);
}
unsigned char i = 0;
void loop() {
    //Serial.println(MIDI::maxSize);
    Serial.println(MIDI::MCU::toString(static_cast<MIDI::MCU::NoteMapping>(i++)));
    if(119 < i)
      i = 0;
    delay(100);
    /*
    if(USBMIDI.available()){
        if(basic.read(USBMIDI)) return;
        if(basic.getCommand() == MIDI::PitchBendChange){
            printPitch(basic);
        }else if(basic.getCommand() == MIDI::ControlModeChange){
            printControlModeChange(basic);
        }
    }

    if(Serial.available()){
        byte b = Serial.read();
        playBtnSoftware.run(b);
        stopBtnSoftware.run(b);
    }

    playBtn.run(digitalRead(PLAY_PIN));
    stopBtn.run(digitalRead(PAUSE_PIN));
    delay(10);
    */
}
