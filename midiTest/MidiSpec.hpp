#pragma once


#include <cstddef>
namespace MIDI {

    namespace MCU {
        enum NoteMapping : unsigned char{
            REC1,
            REC2,
            REC3,
            REC4,
            REC5,
            REC6,
            REC7,
            REC8,

            SOLO1,
            SOLO2,
            SOLO3,
            SOLO4,
            SOLO5,
            SOLO6,
            SOLO7,
            SOLO8,

            MUTE1,
            MUTE2,
            MUTE3,
            MUTE4,
            MUTE5,
            MUTE6,
            MUTE7,
            MUTE8,

            SELECT1,
            SELECT2,
            SELECT3,
            SELECT4,
            SELECT5,
            SELECT6,
            SELECT7,
            SELECT8,

            VPOT_SWITCH1,
            VPOT_SWITCH2,
            VPOT_SWITCH3,
            VPOT_SWITCH4,
            VPOT_SWITCH5,
            VPOT_SWITCH6,
            VPOT_SWITCH7,
            VPOT_SWITCH8,

            ASSIGN_TRACK,
            ASSIGN_SEND,
            ASSIGN_PAN,
            ASSIGN_PLUG_IN,
            ASSIGN_EQ,
            ASSIGN_INSTRUMENT,
            
            BANK_LEFT,
            BANK_RIGHT,
            CHANNEL_LEFT,
            CHANNEL_RIGHT,

            FLIP,
            GLOBAL,

            NAME_VALUE_BUTTON,
            SMPTE_BEATS_BUTTON,

            F1,
            F2,
            F3,
            F4,
            F5,
            F6,
            F7,
            F8,

            MIDI_TRACKS,
            INPUTS,
            AUDIO_TRACKS,
            AUDIO_INSTRUMENTS,
            AUX,
            BUSSES,
            OUTPUTS,
            USER,
            SHIFT,
            OPTION,
            CONTROL,
            ALT,

            READ_OFF,
            WRITE,
            TRIM,
            TOUCH,
            LATCH,
            GROUP,

            SAVE,
            UNDO,
            CANCEL,
            ENTER,

            MARKERS,
            NUDGE,
            CYCLE,
            DROP,
            REPLACE,
            CLICK,
            SOLO,

            REWIND,
            FORWARD,
            STOP,
            PLAY,
            RECORD,

            UP,
            DOWN,
            LEFT,
            RIGHT,
            ZOOM,
            SCRUB,

            USER_SWITCH_1,
            USER_SWITCH_2,
            
            FADER_1_TOUCHED,
            FADER_2_TOUCHED,
            FADER_3_TOUCHED,
            FADER_4_TOUCHED,
            FADER_5_TOUCHED,
            FADER_6_TOUCHED,
            FADER_7_TOUCHED,
            FADER_8_TOUCHED,

            MASTER_FADER_TOUCHED,
            SMPTE_LED,
            BEATS_LED,
            RUDE_SOLO_LED,

            RELAY_CLICK0,
            RELAY_CLICK1,
            RELAY_CLICK2,
            RELAY_CLICK3,
        };

        enum ControlMapping : unsigned char{
            VPOT_ROTATION0 = 16,
            VPOT_ROTATION1,
            VPOT_ROTATION2,
            VPOT_ROTATION3,
            VPOT_ROTATION4,
            VPOT_ROTATION5,
            VPOT_ROTATION6,
            VPOT_ROTATION7,
            VPOT_ROTATION8,

            EXTERNAL_CONTROL = 46,

            VPOT_LED_RING0 = 48,
            VPOT_LED_RING1,
            VPOT_LED_RING2,
            VPOT_LED_RING3,
            VPOT_LED_RING4,
            VPOT_LED_RING5,
            VPOT_LED_RING6,
            VPOT_LED_RING7,
            VPOT_LED_RING8,

            JOG_WHEEL = 60,

            TIMECODE_DIGIT0 = 64,
            TIMECODE_DIGIT1,
            TIMECODE_DIGIT2,
            TIMECODE_DIGIT3,
            TIMECODE_DIGIT4,
            TIMECODE_DIGIT5,
            TIMECODE_DIGIT6,
            TIMECODE_DIGIT7,
            TIMECODE_DIGIT8,
            TIMECODE_DIGIT9,

            ASSIGNMENT_DIGIT1= 74,
            ASSIGNMENT_DIGIT2= 75,
            
        };


            //channel
        enum PitchBendMapping : unsigned char{
            FADER_POSITION0 = 0,
            FADER_POSITION1,
            FADER_POSITION2,
            FADER_POSITION3,
            FADER_POSITION4,
            FADER_POSITION5,
            FADER_POSITION6,
            FADER_POSITION7,

            FADER_POSITION_MASTER = 8,
        };

        enum ChannelPressureMapping : unsigned char{
            METERING = 0,
        };
    }

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
    };

    struct Basic : public CommandByte{
        unsigned char mData[3];

        unsigned char* begin(){
            return mData;
        }
        unsigned char* end(){
            return mData+3;
        }

        template<typename t>
        bool read(t& midi){
            do{ 
                midi.poll();
                mCommandByte = midi.read();
            } while(mCommandByte < 128);
            
            unsigned char byteCount = getDataByteCount();
            
            if(byteCount == static_cast<unsigned char>(-1)) return true;

            for (int i = 0; i < byteCount; i++) {
                midi.poll();
                mData[i] = midi.read();
            }

            return false;
        }
    };

    

    constexpr size_t ExclusiveMaxSize = 62;
    constexpr unsigned char EOX = 0b11110111;

    struct Exclusive : public CommandByte{
        unsigned char mData[ExclusiveMaxSize];
        unsigned char mSize = 0;

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
    
    inline unsigned short getShort(unsigned char lsb, unsigned char msb){
        unsigned short s = msb;
        s<<=7;
        s|=lsb;
        return s;
    }

    inline unsigned short getShort(unsigned char* lsb_msb){
        unsigned short s = lsb_msb[1];
        s<<=7;
        s|=lsb_msb[0];
        return s;
    }



    template<typename T>
    inline bool sendKey(T& midi, unsigned char channel, MCU::NoteMapping note, unsigned char velocity){
        midi.write(CommandByte::make(Command::NoteON, channel).mCommandByte);
        midi.write(note & 0b01111111);      //ensures that it is max 127
        midi.write(velocity & 0b01111111);  //ensures that it is max 127
    }

    template<typename T>
    inline bool sendControl(T& midi, unsigned char channel, MCU::ControlMapping control, unsigned char value){
        midi.write(CommandByte::make(Command::ControlModeChange, channel).mCommandByte);
        midi.write(control & 0b01111111);      //ensures that it is max 127
        midi.write(value & 0b01111111);  //ensures that it is max 127
    }

    template<typename T>
    inline bool sendPitch(T& midi, MCU::PitchBendMapping pitch_channel, unsigned char lsb, unsigned char msb){
        midi.write(CommandByte::make(Command::ControlModeChange, pitch_channel).mCommandByte);
        midi.write(lsb & 0b01111111);  //ensures that it is max 127
        midi.write(msb & 0b01111111);  //ensures that it is max 127
    }

    template<typename T>
    inline bool sendPitch(T& midi, MCU::PitchBendMapping pitch_channel, unsigned short lsb_msb_14bit){
        midi.write(CommandByte::make(Command::ControlModeChange, pitch_channel).mCommandByte);
        midi.write(lsb_msb_14bit & 0b01111111);  //ensures that it is max 127
        midi.write(lsb_msb_14bit >> 7);  //ensures that it is max 127
    }
}
