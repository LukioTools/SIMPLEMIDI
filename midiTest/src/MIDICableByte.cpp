#pragma once

#include "../lib/CableByte.hpp"


CableByte::CableByte(unsigned char _cableByte) : mCableByte(_cableByte) {}

CableByte::CableByte(CodeIndex _codeIndex, unsigned char _cableNumber) : mCableByte((_codeIndex & 0b00001111) | (_cableNumber << 4)) {}

unsigned char CableByte::getCableNumber() const{
    return getCable() >> 4;
}

CodeIndex CableByte::getCodeIndex() const{
    return static_cast<CodeIndex>(mCableByte & 0b00001111);
}

void CableByte::setCable(unsigned char _cable){
    mCableByte = getCodeIndex() | (_cable << 4);
} 

void CableByte::setCodeIndex(CodeIndex _codeIndex){
    mCableByte = getCable() | ( _codeIndex & 0b00001111);
}

unsigned char CableByte::getCable() const{
    return (mCableByte & 0b11110000);
}