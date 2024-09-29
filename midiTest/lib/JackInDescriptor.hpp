#pragma once
#include <stdint.h>

;
#pragma pack(push, 1)
struct MIDIJackinDescriptor {
	uint8_t len;		// 9
	uint8_t dtype;		// 4
	uint8_t dsubType;
	uint8_t jackType;
	uint8_t jackID;
	uint8_t jackStrIndex;
};
#pragma pack(pop)