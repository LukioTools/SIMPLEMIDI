#pragma once


#include <cstddef>
#include <iterator>
namespace MIDI {

    enum Command : unsigned char{
        NoteOFF,
        NoteON,
        PolyphonicAftertouch,
        ControlModeChange,
        ProgramChange,
        ChannelAftertouch,
        PitchBendChange,
        SystemMessage,
    };

    enum SystemMessages : unsigned char{
        SystemExclusive,
        MIDITimeCodeQtrFrame,
        SongPositionPointer,
        SongSelect,
        Undefined0, 
        Undefined1, 
        TuneRequest,
        EndOfSysEx,
        TimingClock,
        Undefined2, 
        Start, 
        Continue,
        Stop,
        Undefined3,
        ActiveSensing, 
        SystemReset, 
    };

    struct CommandByte{
        unsigned char mCommandByte;
        constexpr const char* getCommandName()const{
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

                        case MIDITimeCodeQtrFrame: return -1; //see spec

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
    };

    struct Basic : public CommandByte{
        unsigned char mData[3];

        unsigned char* begin(){
            return std::begin(mData);
        }
        unsigned char* end(){
            return std::end(mData);
        }
    };


    constexpr std::size_t ExclusiveMaxSize = 62;
    constexpr unsigned char EOX = 0b11110111;

    struct Exclusive : public CommandByte{
        unsigned char mSize = 0;
        unsigned char mData[ExclusiveMaxSize];

        unsigned char* begin(){
            return mData;
        }
        unsigned char* end(){
            return mData+mSize;
        }

        inline unsigned char size(){
            return mSize;
        }
        inline bool empty(){
            return mSize == 0;
        }

        inline void clear(){
            mSize = 0;
        }
            //returns 255? if error
        inline unsigned char pop(){
            if (mSize) {
                return mData[mSize--];
            }
            return -1;
        }

        // midi.push_back(MIDIUSB.read()) 
        inline void push_back(unsigned char c){
            if(mSize < ExclusiveMaxSize-1){
                mData[mSize++] = c;
            }
        }

        // midi.emplace() = MIDIUSB.read()
        inline unsigned char& emplace(){
            if(mSize < ExclusiveMaxSize-1){
                return mData[mSize++];
            }
            return mData[mSize];
        }
    };



    

}
