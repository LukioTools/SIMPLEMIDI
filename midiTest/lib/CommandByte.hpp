#pragma once
#include "Enums.hpp"

struct CommandByte{

    static inline CommandByte make(Command c, unsigned char channel);

    unsigned char mCommandByte;

    Command getCommand() const;

    unsigned char getChannel() const;

    unsigned char getDataByteCount() const;

    static Command getCommand(unsigned char mCommandByte){
        return static_cast<Command>((mCommandByte>>4) & 0b111);
    }
    static unsigned char getChannel(unsigned char mCommandByte){
        return mCommandByte & 0xF;
    }
};