#pragma once

namespace MIDI {

    enum CodeIndex : unsigned char{
        MISC,
        CABLE_EVENT,
        SYSMSG_2,
        SYSMSG_3,
        SYSEX,
        SYSMSG_SYSEND_1,
        SYSEND_2,
        SYSEND_3,
        NOTE_OFF,
        NOTE_ON,
        POLY_KEY,
        CTRL_CHANGE,
        PROG_CHANGE,
        CHAN_PRESS,
        PITCH_CHANGE,
        BYTE_1,

    };

    struct CableByte{
        unsigned char mCableByte;

        CableByte(unsigned char _cableByte = 0) : mCableByte(_cableByte) {}

        CableByte(CodeIndex _codeIndex, unsigned char _cableNumber = 0) : mCableByte((_codeIndex & 0b00001111) | (_cableNumber << 4)) {}

        unsigned char getCableNumber() const{
            return getCable() >> 4;
        }

        CodeIndex getCodeIndex() const{
            return mCableByte & 0b00001111;
        }

        void setCable(unsigned char _cable){
            mCableByte = getCodeIndex() | (_cable << 4);
        } 

        void setCodeIndex(CodeIndex _codeIndex){
            mCableByte = getCable() | ( _codeIndex & 0b00001111);
        }

    private:
        unsigned char getCable() const{
            return (mCableByte & 0b11110000);
        }
    }; 
}