# SIMPLEMIDI for Arduino

MIDI library for Arduino

## Quick start

1. Clone this repository and put into arduino/libraries folder.

2. Add ```#inclide <SIMPLEMIDI.h>``` to your project.

3. Create an ``MIDI_USB`` instance.

4. Use the ``begin`` methond in ``setup()``

4. Use the ``MIDI_USB::begin()`` methond in ``setup()``

5. Read using the ` T* MIDI_USB::read<T>() ` method, returns nullptr, if not enough data was available for the size of your structure. Read polls automaticly if needed, but doesnt block.

6. Write using the `size_t MIDI_USB::write<T>(const T&)` method or using the `MIDI::send*` group of functions

7. Profit

## Benefits
This library has been inspired (copied) from MIDIUSB (made by arduino) and USBMIDI made by BlokasLabs. 
<br>
<br>
USBMIDI has major flaw: other usb libraries do not work at the same time on Windows. For example ``<Keyboard.h>`` does not work. in other hand, MIDIUSB is over simplified and isn't able to give one byte at the time. But does support ``<Keyboard.h>`` on Windows. (both work on Linux)

SIMPLEMIDI is designed to work with other libraries unlike the USMIDI on both Windows and Linux. We don't know the situation on MAC. This libary has input buffer, so you can read or write in any size. ``T t = read<T>()`` and ``write(T)`` where T is your datatype. further information [here](#midi_usb).


## Supported Devices
The Libary is implemented only for AVR board having native USB functionality (ATMEGA32u4, arduino leonardo, micro pro, and similar devices). Software USB isn't supported.

## Functions available:
|function|params|explanation|
|--|--|--|
|``MIDI_USB::begin``||starts the USB communication|
|``MIDI_USB::poll``||receive data from USB and writes to buffer|
|``MIDI_USB::read``||reads ``Template T`` from buffer|
|``MIDI_USB::finalize``||is done automatically|
|``MIDI_USB::write``|``Typename T data``|writes data to USB|
|``MIDI_USB::flush``||flushes data|


## License
Pluggable USB based implementations use BSD License

## MIDI_USB

### Read
Read is a nonblocking call, that polls new data to buffer, if nececcary. If enough data is in the buffer, returns a casted pointer to the begining of the buffer, otherwise returns nullptr.
<br>
Read is most commonly used with types like [MIDI::Event](#event) or byte.

#### Example
```c++
midi.poll(); // midi is a created MIDI_USB instance
while(Event* event = midi.read<Event>()){
    //use event
}
```


### Write
Write is an unbuffered call to write specified data to the usb buffer. 
<br>
Write is most commonly used with types like [MIDI::Event](#event). Normally write is unnececcary due to the precence of `MIDI::send*` group of functions

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

Event is a type that contains midi event data. Usually used for input, but can be used as output using the [MIDI_USB::Write](#write) method

#### Example

```c++
Event* event = midi.read<Event>();
Event& ev = *event;
```
