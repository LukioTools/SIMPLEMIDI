#pragma once

#include "MIDIenums.hpp"

namespace MIDI {


    struct CommandByte{

        static inline CommandByte make(Command c, unsigned char channel){
            return {static_cast<unsigned char>(0b10000000 | (c<<4) | (channel & 0xF))};
        }

        unsigned char mCommandByte;
        const char* getCommandName()const{
            switch (getCommand()) {
                case NoteOFF:                           return "NoteOFF";
                case NoteON:                            return "NoteON";
                case PolyphonicAftertouch:              return "PolyphonicAftertouch";
                case PitchBendChange:                   return "PitchBendChange";
                case ProgramChange:                     return "ProgramChange";
                case ChannelAftertouch:                 return "ChannelAftertouch";
                case ControlModeChange:                 return "ControlModeChange";

                case SystemMessage: switch (getChannel()) {
                        case SystemExclusive:           return "SystemMessage::SystemExclusive";
                        case SongSelect:                return "SystemMessage::SongSelect";
                        case SongPositionPointer:       return "SystemMessage::SongPositionPointer";
                        case TuneRequest:               return "SystemMessage::TuneRequest";
                        case EndOfSysEx:                return "SystemMessage::EndOfSysEx";
                        case TimingClock:               return "SystemMessage::TimingClock";
                        case Start:                     return "SystemMessage::Start";
                        case Continue:                  return "SystemMessage::Continue";
                        case Stop:                      return "SystemMessage::Stop";
                        case ActiveSensing:             return "SystemMessage::ActiveSensing";
                        case SystemReset:               return "SystemMessage::SystemReset";
                        case MIDITimeCodeQtrFrame:      return "SystemMessage::MIDITimeCodeQtrFrame"; 
                        case Undefined0: 
                        case Undefined1: 
                        case Undefined2:   
                        case Undefined3:                return "SystemMessage::UNDEFINED";  
                        default:
                            break;
                    }
                default:
                    return "UNKNOWN";
            }
            return "UNKNWON";
        }

        Command getCommand() const{
            return static_cast<Command>((mCommandByte>>4) & 0b111);
        }
        unsigned char getChannel() const{
            return mCommandByte & 0xF;
        }
        unsigned char getDataByteCount() const{
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
        static Command getCommand(unsigned char mCommandByte){
            return static_cast<Command>((mCommandByte>>4) & 0b111);
        }
        static unsigned char getChannel(unsigned char mCommandByte){
            return mCommandByte & 0xF;
        }

        static unsigned char makeCommandByte(Command c, unsigned char channel){
            return 0b10000000 | (c<<4) | (channel & 0xF);
        }
    };

}