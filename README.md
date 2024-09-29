# SIMPLEMIDI for Arduino

MIDI library for Arduino

## Quick start

1. Clone this repository and put into arduino/libraries folder.

2. Add ```#inclide <SIMPLEMIDI.h>``` to your project.

3. profit!! create ``MIDI_USB`` object.

4. Use the ``begin`` methond in ``setup()``


## Functions available:
|function|params|explanation|
|--|--|--|
|``MIDI_USB::begin``||starts the USB communication|
|``MIDI_USB::poll``||receive data from USB and writes to buffer|
|``MIDI_USB::read``||reads ``Template T`` from buffer|
|``MIDI_USB::finalize``||is done automatically|
|``MIDI_USB::write``|``Typename T data``|writes data to USB|
|``MIDI_USB::flush``||flushes data|


## Benefits
This library has been inspired (copied) from MIDIUSB (made by arduino) and USBMIDI made by BlokasLabs. 
<br>
<br>
USBMIDI has major flaw: other usb libraries do not work at the same time on Windows. For example ``<Keyboard.h>`` does not work.
<br>
<br>
in other hand, MIDIUSB is over simplified and isn't able to give one byte at the time. But does support ``<Keyboard.h>`` on Windows. (both work on Linux)

SIMPLEMIDI is designed to support other USB libraries on both, Windows and Linux. We don't know the situation on MAC. This libary has input buffer, so you can read or write in any size. ``T t = read<T>()`` and ``write(T)`` where T is your datatype.  


## Supported Devices
The Libary is implemented only for AVR board having native USB functionality (ATMEGA32u4, arduino leonardo, micro pro, and similar devices). Software USB isn't supported.

## License
Pluggable USB based implementations use BSD License