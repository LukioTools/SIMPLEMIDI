# SIMPLEMIDI for Arduino

MIDI library for Arduino

## Quick start

1. Clone this repository and put into arduino/libraries folder.

2. Add ```#inclide <SIMPLEMIDI.h>``` to your project.

3. Create an ``MIDI_USB`` instance.

4. Use the ``MIDI_USB::begin()`` methond in ``setup()``

5. Read using the ` T* MIDI_USB::read<T>() ` method, returns nullptr, if not enough data was available for the size of your structure. Read polls automaticly if needed, but doesnt block.

6. Write using the `size_t MIDI_USB::write<T>(const T&)` method or using the `MIDI::send*` group of functions

7. Profit

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
    //or
MIDI::sendNoteON(midi, ...); // MIDI::send* family of functions are also a great way of sending midi data
```
## Event

Event is a type that contains midi event data. Usually used for input, but can be used as output using the [MIDI_USB::Write](#write) method

#### Example

```c++
Event* event = midi.read<Event>();
Event& ev = *event;
```