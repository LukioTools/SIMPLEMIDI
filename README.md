<p align="center">
<img src="Images/logo.svg" width="">
</p>

# SIMPLEMIDI for Arduino 

As the title says... simple MIDI library for Arduino. The library primarily supports MCU (Mackie Control Universal) protocol, but other protocolls may be rawdogged.

## Quick start

1. Clone this repository and put into `arduino/libraries` folder.

2. Add `#include <SIMPLEMIDI.h>` to your project.

3. Create an `MIDI_USB` instance.

4. Use the `begin` method in `setup()`

4. Use the `MIDI_USB::begin()` method in `setup()`

5. Read using the ` T* MIDI_USB::read<T>() ` method. Returns nullptr, if not enough data was available for the size of your structure. Read polls automatically if needed, but doesn't block.

6. Write using the `size_t MIDI_USB::write<T>(const T&)` method or using the `MIDI::send*` group of functions

7. Profit

## Benefits
This library has been inspired (copied) from MIDIUSB (made by Arduino) and USBMIDI made by BlokasLabs. 
<br>
USBMIDI has major flaw: other USB libraries do not work at the same time on Windows. For example, ``<Keyboard.h>`` does not work. In other hand, MIDIUSB is over simplified and isn't able to give one byte at the time. But does support ``<Keyboard.h>`` on Windows. (both work on Linux)

SIMPLEMIDI is designed to work with other libraries unlike the USMIDI, on both Windows and Linux. We don't know the situation on MAC. This library  has input buffer, so you can read or write in any size. `T t = read<T>()` and `write(T)` where T is your datatype. further information [here](#midi_usb).


## Supported Devices
The library  is implemented only for AVR board having native USB functionality (ATMEGA32u4, arduino leonardo, micro pro, and similar devices). Software USB isn't supported.

## Bugs & features
Feel free to open a new issue or do pull request. Fastest way to fix problem(s)/add feature(s) is pull request, as we are not committed on this project too much. Small changes or help can be done through issues.  

## MIDI_USB

Instance creation.
```c++ 
MIDI_USB midi;
```


### Functions available:
|function|params|explanation|
|--|--|--|
|[`MIDI_USB::begin`](#begin)||starts the USB communication|
|[`MIDI_USB::poll`](#poll)||does receive data from USB and writes to buffer|
|[`MIDI_USB::read`](#read)||reads `typename T` from buffer|
|[`MIDI_USB::peek`](#peek)||reads `typename T` from buffer, doesnt increment pointer|
|[`MIDI_USB::finalize`](#finalize)||is done automatically|
|[`MIDI_USB::write`](#write)|`typename T data`|writes data to USB|
|[`MIDI_USB::flush`](#flush)||flushes data|

### Begin
Calling `MIDI_USB::begin` starts MIDI communication between arduino and a computer. After this you can read [`MIDI_USB::write`](#write) and send [`MIDI_USB::read`](#read)  messages 

#### example
```c++
void setup(){
    ...
    // midi is a created MIDI_USB instance
    midi.begin();
    ...
}
```


### Poll
Poll is used to receive bytes from USB. The data is stored into a buffer. You can read the buffer using [`MIDI_USB::peek`](#peek) or [`MIDI_USB::read`](#read) methods. You have to poll before reading as this is not done automatically.

#### example
```c++
void loop(){
    ...
    // midi is a created MIDI_USB instance
    midi.poll();
    ...
}
```

### Read
Read is a nonblocking call, that polls new data to buffer, if nececcary. If enough data is in the buffer, returns a casted pointer to the begining of the buffer, otherwise returns nullptr.
<br>
Read is most commonly used with types like [`MIDI::Event`](#event) or byte.

#### Example
```c++
// midi is a created MIDI_USB instance
midi.poll(); 
while(Event* event = midi.read<Event>()){
    //use event
}
```

### Peek
Peek is the same as [`MIDI_USB::read()`](#read), but it doesn't move the read offset pointer.
This function is perfect when you need to be an indesicive ~~cunt~~.

#### Example
```c++
// midi is a created MIDI_USB instance
midi.poll(); 
if(byte* data = midi.peek<byte>() && data == 20){
    auto e = midi.read<Event>();
    ...
}else{
    auto e = midi.read<unsigned int>();
    ...
}
```

### Write
Write is an unbuffered call to write specified data to the usb buffer. 
<br>
Write is most commonly used with types like [`MIDI::Event`](#event). Normally write is unnececcary due to the precence of `MIDI::send*` group of functions

#### Example
```c++
Event ev(...); 
// midi is a created MIDI_USB instance
midi.write(ev); 
    //or using pointer interface
midi.flush();

// or

char* data = ...;
size_t dataSize = ...;
// midi is a created MIDI_USB instance
midi.write(data, dataSize); 
    //MIDI::send* family of functions are also a great way of sending midi data
MIDI::sendNoteON(midi, ...);
midi.flush();
```

### Finalize
Cleans up the input buffer by copying unread bytes to the begining of the buffer. Finalze is used automatically before [poll](#poll).

#### example

```c++
// midi is a created MIDI_USB instance
midi.poll();
while(Event* e = midi.read<Event>())
    ...

midi.finalize();
``` 

### Flush
Sends written messages to computer. Same as any other flush command. Use after [`MIDI_USB::write`](#write) and after `MIDI::send*` functions.

#### example
```c++
// midi is a created MIDI_USB instance
Event ev(...);
midi.write(ev);
midi.flush();

// or

MIDI::sendNoteON(midi ...);
midi.flush()
```


## Event

Event is a type that contains midi event data. Usually used for input, but can be used as output using the [`MIDI_USB::Write`](#write) method

#### Example

```c++
Event* event = midi.read<Event>();
Event& ev = *event;
```

## Send*
Send* is a group of functions used to send midi events.
-   send<`CodeIndex`, `Command`>([MIDI_USB](#midi_usb), dataByte1, dataByte2, channel = 0, cable = 0)
-   sendNoteON ([MIDI_USB](#midi_usb), channel, note, velocity)
-   sendNoteOFF ([MIDI_USB](#midi_usb), channel, note, velocity)
-   sendControl ([MIDI_USB](#midi_usb), channel, control, value)
-   sendPitch ([MIDI_USB](#midi_usb), channel, lsb (least significant byte), msb (most significant byte))
-   sendPitch ([MIDI_USB](#midi_usb), channel, 14bitValue) value between (0-16384)

#### example
```c++
MIDI::send<MIDI::CodeIndex::NOTE_ON, MIDI::Command::NoteON>(midi, 0, 0);

MIDI::sendNoteON(midi, 0, MCU::NoteMapping::PLAY, 127); // 0 = false and 127 = true

MIDI::sendNoteOFF(midi, 0, MCU::NoteMapping::PLAY, 0);  // (isn't required)

MIDI::sendControl(midi, 0, MCU::ControlMapping::VPOT_ROTATION0, 43);

MIDI::sendPitch(midi, MIDI::MCU::PitchBendMapping::FADER_POSITION_MASTER, 45, 123); // lsb and msb are between 0-127

MIDI::sendPitch(midi, MIDI::MCU::PitchBendMapping::FADER_POSITION_MASTER, 10000); // between 0-16384
```

## DeviceControl
The library has few "Controllers" for devies like button and rotart encoder. It also includes software versions.
<br>
You have to create instance for every device.

#### example
```c++
MIDI::DeviceControl::NoteBtn<MIDI_USB, MIDI::MCU::NoteMapping::PLAY> playBtn(midi);
MIDI::DeviceControl::PitchRotaryEncoder<MIDI_USB, MIDI::MCU::FADER_POSITION_MASTER> rotaryEncoder(midi, 100);

```
In code you have to update the state of the device.
```c++
playBtn.run(digitalRead(BUTTON_PIN));
rotaryEncoder.run(digitalRead(CLK), digitalRead(DT)) // this has to be updated frequently
```

You can update the rotary encoder status based on the midi status.
```c++
while(Event* event = midi.read<Event>()){
    // updateValue will automatically find the correct midi packet and update based on it.
    rotaryEncoder.updateValue(event); 
}
```

## Enums
Referenced from https://github.com/NicoG60/TouchMCU/blob/main/doc/mackie_control_protocol.md
|namespace|Enum|Explanation|
|--|--|--|
|MIDI::MCU|NoteMapping|Note mapping (used for MCU commands) (play, pause, etc)|
|MIDI::MCU|PitchBendMapping| PitchBend mapping (used for MCU commands) (sliders, etc.)|
|MIDI::MCU|ControlMapping| Control mapping (used for MCU commands) (potentiometer and led ring)|
|MIDI::MCU|ChannelpressureMapping| no clue|
|MIDI|Command| command (Note off, etc)|
|MIDI|SystemMessage|tells what kinda of message it is|
|MIDI|CodeIndex|Some shenanigans (https://www.usb.org/sites/default/files/midi10.pdf )|


## Debugging
If you want to debug the midi events verbosely, you can define `MIDI_PRINT` before including the SIMPLEMIDI library.
#### example
```c++
#define MIDI_PRINT 1
#include <SIMPLEMIDI.h>
```

This will include add PROGMEM strings, toString functionality for most of the enums and a method `Event::print(T printable)` (usually passed `Serial`) 
<br>
**Be carefull, inclusion of PROGMEM strings will increase program memory drastically!**

#### example
```c++
Event* event = midi.read<Event>();
event->print(Serial); // Serial is the Serial interface used for printing, or other similiar Class.
// Expected response: NoteOFF[0]{ Note: REC1, Velocity: 0 }
```

## In the Case of an Emergency
You may find these links helpful <br>
https://midi.org/summary-of-midi-1-0-messages 
<br>
https://midi.org/expanded-midi-1-0-messages-list
<br>
https://github.com/NicoG60/TouchMCU/blob/main/doc/mackie_control_protocol.md
<br>
https://www.usb.org/sites/default/files/midi10.pdf

## Something else
### About the protocol:
Midi events via USB are sent in 4 bytes.
<br>
|Byte 0|Byte 1|Byte 2|Byte 3|
|--|--|--|--|
|Cable number \| Code Index Number (CableByte)|MIDI_0 (CommandByte)|MIDI_1 (Data1)|MIDI_2 (Data2)| 
This was figured out from MIDI v1 spec, links mentioned in [In the case of an ***Emergency***](#in-the-case-of-an-emergency) section and physical observation (With [Reaper](https://www.reaper.fm/) and with [MIDI-OX](http://www.midiox.com/))

Please refer to https://www.usb.org/sites/default/files/midi10.pdf section ***4 USB-MIDI Event Packets***


## License
GPLv2