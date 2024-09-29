# SIMPLEMIDI for Arduino

as the title says... simple MIDI library for Arduino. The library also has support for MCU (Mackie Control Universal protocol)

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
USBMIDI has major flaw: other USB libraries do not work at the same time on Windows. For example, ``<Keyboard.h>`` does not work. in other hand, MIDIUSB is over simplified and isn't able to give one byte at the time. But does support ``<Keyboard.h>`` on Windows. (both work on Linux)

SIMPLEMIDI is designed to work with other libraries unlike the USMIDI on both Windows and Linux. We don't know the situation on MAC. This library  has input buffer, so you can read or write in any size. `T t = read<T>()` and `write(T)` where T is your datatype. further information [here](#midi_usb).


## Supported Devices
The library  is implemented only for AVR board having native USB functionality (ATMEGA32u4, arduino leonardo, micro pro, and similar devices). Software USB isn't supported.

## Bugs & features
Feel free to open a new issue or do pull request. Fastest way to fix problem(s)/add feature(s) is pull request, as we are not committed on this project too much. Small changes or help can be done through issues.  



## License
Pluggable USB based implementations use BSD License

## MIDI_USB

### Functions available:
|function|params|explanation|
|--|--|--|
|`MIDI_USB::begin`||starts the USB communication|
|`MIDI_USB::poll`||receive data from USB and writes to buffer|
|[`MIDI_USB::read`](#read)||reads `typename T` from buffer|
|[`MIDI_USB::peek`](#peek)||reads `typename T` from buffer, doesnt increment pointer|
|`MIDI_USB::finalize`||is done automatically|
|[`MIDI_USB::write`](#write)|`typename T data`|writes data to USB|
|`MIDI_USB::flush`||flushes data|


### Read
Read is a nonblocking call, that polls new data to buffer, if nececcary. If enough data is in the buffer, returns a casted pointer to the begining of the buffer, otherwise returns nullptr.
<br>
Read is most commonly used with types like [`MIDI::Event`](#event) or byte.

#### Example
```c++
midi.poll(); // midi is a created MIDI_USB instance
while(Event* event = midi.read<Event>()){
    //use event
}
```

### Peek
Peek is the same as [`MIDI_USB::read()`](#read), but it doesn't move the read offset pointer.
This function is perfect when you need to be an indesicive ~~cunt~~.

#### Example
```c++
midi.poll(); // midi is a created MIDI_USB instance
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
midi.write(ev); // midi is a created MIDI_USB instance
    //or using pointer interface
char* data = ...;
size_t dataSize = ...;
midi.write(data, dataSize); // midi is a created MIDI_USB instance
    //MIDI::send* family of functions are also a great way of sending midi data
MIDI::sendNoteON(midi, ...);
```
## Event

Event is a type that contains midi event data. Usually used for input, but can be used as output using the [`MIDI_USB::Write`](#write) method

#### Example

```c++
Event* event = midi.read<Event>();
Event& ev = *event;
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
|MIDI|SystemMessage|tells what kinda of system message it is|


## Debugging
If you like to debug the midi events you have to define `MIDI_PRINT` before including the SIMPLEMIDI library.
#### example
```c++
#define MIDI_PRINT 1
#include <SIMPLEMIDI.h>
```

This will include add strings used in debugging and a method `Event::print(T printable)` (usually passed `Serial`) Be careful this will increase program memory usage a lot!  

#### example
```c++
    Event* event = midi.read<Event>();
    event->print(Serial);
```
```
==> NoteOFF[0]{ Note: REC1, Velocity: 0 }
```