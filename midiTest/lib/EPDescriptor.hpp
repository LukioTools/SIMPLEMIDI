#pragma once
#include <stdint.h>

#ifndef ARDUINO
#define USBCON
#define ARDUINO_ARCH_AVR
#endif
#if !defined(USBCON)
#error MIDIUSB can only be used with an USB MCU.
#endif

#if !defined(ARDUINO_ARCH_AVR)
#error MIDIUSB can only be used with AVR boards.
#endif


#if ARDUINO
#include "USBCore.h"
#include <avr/interrupt.h>


#include "USBAPI.h"
#include "PluggableUSB.h"
#include <Arduino.h>
#include <stdint.h>
#endif

;
#pragma pack(push, 1)


struct MIDI_EPDescriptor {
	EndpointDescriptor len;		// 9
	uint8_t refresh;		// 4
	uint8_t sync;
};
#pragma pack(pop)
