#include "../lib/CommandByte.hpp"



static inline CommandByte make(Command c, unsigned char channel){
    return {static_cast<unsigned char>(0b10000000 | (c<<4) | (channel & 0xF))};
}

unsigned char mCommandByte;

Command CommandByte::getCommand() const{
    return static_cast<Command>((mCommandByte>>4) & 0b111);
}
unsigned char CommandByte::getChannel() const{
    return mCommandByte & 0xF;
}
unsigned char CommandByte::getDataByteCount() const{
    switch (getCommand()) {
        case NoteOFF: 
        case NoteON: 
        case PolyphonicAftertouch:  
        case PitchBendChange: return 2;

        case ProgramChange: 
        case ChannelAftertouch: return 1;

        case ControlModeChange: return 2; // see spec

        case SystemMessage: switch (getChannel()) {
                case SystemExclusive: return -1; // Variable
                case SongSelect:    return 1;
                case SongPositionPointer: return 2;
                case TuneRequest:  
                case EndOfSysEx:   
                case TimingClock:  
                case Start:        
                case Continue:     
                case Stop:         
                case ActiveSensing:
                case SystemReset:   return 0;

                case MIDITimeCodeQtrFrame: return 2; //see spec

                case Undefined0: 
                case Undefined1: 
                case Undefined2:   
                case Undefined3: return  -1;  
            }
        default:
            return -1;
    }
}
