#include <midi_serialization.h>
#include <usbmidi.h>

// See midictrl.png in the example folder for the wiring diagram,
// as well as README.md.

u8 skipUntill(){
    while (true){
        u8 b = read(); 
        if(b & 0b10000000)
            return b;
    }
}


void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600);
}

enum Commands{
    SystemExclusive,
    Timecode,
    Position,
    Select,
    Tune,
    Timing,
    Start,
    Stop,
    Sensing,
    SystemReset,
}


constexpr byte dataBytes(Commands c){
    if(c >= Tune) return 0;
    switch (c) {
    case SystemExclusive: return -1; // Variable
    case Timecode: return 1;    // monta kertaa lukea lisää
    case Position: return 2;    // monta kertaa lukea lisää
    case Select: return 1;      // monta kertaa lukea lisää
    }
} 


struct MidiData{
    u8 command_channel;
    u8 data0;
    u8 data1;
    u8 data2;

    u8 getCommand(){
        return (command_channel >> 4) & 0b111;
    }
    
    u8 getChannel(){
        return command_channel & 0b1111;
    }

    void print(){
        Serial.println("command");
        Serial.println(getCommand());
        Serial.println("channel");
        Serial.println(getChannel());
    }
};

void loop() {
	//Handle USB communication
	USBMIDI.poll();

	while (USBMIDI.available()) {
        MidiData data;

		data.command_channel = USBMIDI.read();
		data.data0 = USBMIDI.read();
		data.data1 = USBMIDI.read();
		data.data2 = USBMIDI.read();
        if(data.getChannel() != 0)
            data.print();

	}

	// Flush the output.
	USBMIDI.flush();
}
