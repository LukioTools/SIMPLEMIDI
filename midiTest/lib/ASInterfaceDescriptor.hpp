#pragma once
#include <stdint.h>
;
#pragma pack(push, 1)


struct MIDI_ASInterfaceDescriptor {
	uint8_t len;		// 9
	uint8_t dtype;		// 4
	uint8_t dsubType;
	uint16_t bcdADc;
	uint16_t wTotalLength;
};

#pragma pack(pop)
