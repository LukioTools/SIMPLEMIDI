#pragma once

struct Command{};

struct CommandByte{

    static inline CommandByte make(Command c, unsigned char channel);

    unsigned char mCommandByte;

    Command getCommand() const;

    unsigned char getChannel() const;

    unsigned char getDataByteCount() const;

    static Command getCommand(unsigned char mCommandByte);

    static unsigned char getChannel(unsigned char mCommandByte);
};