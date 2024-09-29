#pragma once
#include <stdint.h>

;
#pragma pack(push, 1)



struct MIDI_EP_ACDescriptor {
	uint8_t len;		// 5
	uint8_t dtype;		// 0x24
	uint8_t subtype;
	uint8_t embJacks;
	uint8_t jackID;
};

#pragma pack(pop)
