#pragma once
;#pragma pack(push, 1)

struct MIDI_ACInterfaceDescriptor {
	uint8_t len;		// 9
	uint8_t dtype;		// 4
	uint8_t dsubType;
	uint16_t bcdADc;
	uint16_t wTotalLength;
	uint8_t bInCollection;
	uint8_t interfaceNumbers;
};

#pragma pack(pop)
