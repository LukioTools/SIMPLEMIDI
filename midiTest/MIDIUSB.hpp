#pragma once

#include "USBAPI.h"
#include "PluggableUSB.h"
#include <Arduino.h>
#include <stdint.h>

#ifndef ARDUINO
#include <cstdint>
#endif

#define MIDI_ENDPOINT_OUT	pluggedEndpoint
#define MIDI_ENDPOINT_IN	((uint8_t)(pluggedEndpoint+1))

#define MIDI_RX MIDI_ENDPOINT_OUT
#define MIDI_TX MIDI_ENDPOINT_IN

#define EP_TYPE_BULK_IN_MIDI 		EP_TYPE_BULK_IN
#define EP_TYPE_BULK_OUT_MIDI 		EP_TYPE_BULK_OUT

using epTypeT = uint8_t;

struct midiEventPacket_t
{
	uint8_t header;
	uint8_t byte1;
	uint8_t byte2;
	uint8_t byte3;
};

class MIDI_USB : public PluggableUSBModule{
    epTypeT epType[2] = {EP_TYPE_BULK_OUT_MIDI, EP_TYPE_BULK_IN_MIDI};
    MIDI_USB() : PluggableUSBModule(2,2, epType){
        PluggableUSB().plug(this);
    }
};


//MIDI_::MIDI_(void) : PluggableUSBModule(2, 2, epType)
//{
//	epType[0] = EP_TYPE_BULK_OUT_MIDI;	// MIDI_ENDPOINT_OUT
//	epType[1] = EP_TYPE_BULK_IN_MIDI;		// MIDI_ENDPOINT_IN
//	PluggableUSB().plug(this);
//}