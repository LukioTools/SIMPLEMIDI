#pragma once


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
        inline const char* toString(NoteMapping n){
            switch (n) {
                case REC1: return "REC1";
                case REC2: return "REC2";
                case REC3: return "REC3";
                case REC4: return "REC4";
                case REC5: return "REC5";
                case REC6: return "REC6";
                case REC7: return "REC7";
                case REC8: return "REC8";
                case SOLO1: return "SOLO1";
                case SOLO2: return "SOLO2";
                case SOLO3: return "SOLO3";
                case SOLO4: return "SOLO4";
                case SOLO5: return "SOLO5";
                case SOLO6: return "SOLO6";
                case SOLO7: return "SOLO7";
                case SOLO8: return "SOLO8";
                case MUTE1: return "MUTE1";
                case MUTE2: return "MUTE2";
                case MUTE3: return "MUTE3";
                case MUTE4: return "MUTE4";
                case MUTE5: return "MUTE5";
                case MUTE6: return "MUTE6";
                case MUTE7: return "MUTE7";
                case MUTE8: return "MUTE8";
                case SELECT1: return "SELECT1";
                case SELECT2: return "SELECT2";
                case SELECT3: return "SELECT3";
                case SELECT4: return "SELECT4";
                case SELECT5: return "SELECT5";
                case SELECT6: return "SELECT6";
                case SELECT7: return "SELECT7";
                case SELECT8: return "SELECT8";
                case VPOT_SWITCH1: return "VPOT_SWITCH1";
                case VPOT_SWITCH2: return "VPOT_SWITCH2";
                case VPOT_SWITCH3: return "VPOT_SWITCH3";
                case VPOT_SWITCH4: return "VPOT_SWITCH4";
                case VPOT_SWITCH5: return "VPOT_SWITCH5";
                case VPOT_SWITCH6: return "VPOT_SWITCH6";
                case VPOT_SWITCH7: return "VPOT_SWITCH7";
                case VPOT_SWITCH8: return "VPOT_SWITCH8";
                case ASSIGN_TRACK: return "ASSIGN_TRACK";
                case ASSIGN_SEND: return "ASSIGN_SEND";
                case ASSIGN_PAN: return "ASSIGN_PAN";
                case ASSIGN_PLUG_IN: return "ASSIGN_PLUG_IN";
                case ASSIGN_EQ: return "ASSIGN_EQ";
                case ASSIGN_INSTRUMENT: return "ASSIGN_INSTRUMENT";
                case BANK_LEFT: return "BANK_LEFT";
                case BANK_RIGHT: return "BANK_RIGHT";
                case CHANNEL_LEFT: return "CHANNEL_LEFT";
                case CHANNEL_RIGHT: return "CHANNEL_RIGHT";
                case FLIP: return "FLIP";
                case GLOBAL: return "GLOBAL";
                case NAME_VALUE_BUTTON: return "NAME_VALUE_BUTTON";
                case SMPTE_BEATS_BUTTON: return "SMPTE_BEATS_BUTTON";
                case F1: return "F1";
                case F2: return "F2";
                case F3: return "F3";
                case F4: return "F4";
                case F5: return "F5";
                case F6: return "F6";
                case F7: return "F7";
                case F8: return "F8";
                case MIDI_TRACKS: return "MIDI_TRACKS";
                case INPUTS: return "INPUTS";
                case AUDIO_TRACKS: return "AUDIO_TRACKS";
                case AUDIO_INSTRUMENTS: return "AUDIO_INSTRUMENTS";
                case AUX: return "AUX";
                case BUSSES: return "BUSSES";
                case OUTPUTS: return "OUTPUTS";
                case USER: return "USER";
                case SHIFT: return "SHIFT";
                case OPTION: return "OPTION";
                case CONTROL: return "CONTROL";
                case ALT: return "ALT";
                case READ_OFF: return "READ_OFF";
                case WRITE: return "WRITE";
                case TRIM: return "TRIM";
                case TOUCH: return "TOUCH";
                case LATCH: return "LATCH";
                case GROUP: return "GROUP";
                case SAVE: return "SAVE";
                case UNDO: return "UNDO";
                case CANCEL: return "CANCEL";
                case ENTER: return "ENTER";
                case MARKERS: return "MARKERS";
                case NUDGE: return "NUDGE";
                case CYCLE: return "CYCLE";
                case DROP: return "DROP";
                case REPLACE: return "REPLACE";
                case CLICK: return "CLICK";
                case SOLO: return "SOLO";
                case REWIND: return "REWIND";
                case FORWARD: return "FORWARD";
                case STOP: return "STOP";
                case PLAY: return "PLAY";
                case RECORD: return "RECORD";
                case UP: return "UP";
                case DOWN: return "DOWN";
                case LEFT: return "LEFT";
                case RIGHT: return "RIGHT";
                case ZOOM: return "ZOOM";
                case SCRUB: return "SCRUB";
                case USER_SWITCH_1: return "USER_SWITCH_1";
                case USER_SWITCH_2: return "USER_SWITCH_2";
                case FADER_1_TOUCHED: return "FADER_1_TOUCHED";
                case FADER_2_TOUCHED: return "FADER_2_TOUCHED";
                case FADER_3_TOUCHED: return "FADER_3_TOUCHED";
                case FADER_4_TOUCHED: return "FADER_4_TOUCHED";
                case FADER_5_TOUCHED: return "FADER_5_TOUCHED";
                case FADER_6_TOUCHED: return "FADER_6_TOUCHED";
                case FADER_7_TOUCHED: return "FADER_7_TOUCHED";
                case FADER_8_TOUCHED: return "FADER_8_TOUCHED";
                case MASTER_FADER_TOUCHED: return "MASTER_FADER_TOUCHED";
                case SMPTE_LED: return "SMPTE_LED";
                case BEATS_LED: return "BEATS_LED";
                case RUDE_SOLO_LED: return "RUDE_SOLO_LED";
                case RELAY_CLICK0: return "RELAY_CLICK0";
                case RELAY_CLICK1: return "RELAY_CLICK1";
                case RELAY_CLICK2: return "RELAY_CLICK2";
                case RELAY_CLICK3: return "RELAY_CLICK3";
                default: return "UNKNOWN_KEY";
            }
        }

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

        inline const char* toString(ControlMapping n){
            switch (n) {
            case VPOT_ROTATION0: return "VPOT_ROTATION0";
            case VPOT_ROTATION1: return "VPOT_ROTATION1";
            case VPOT_ROTATION2: return "VPOT_ROTATION2";
            case VPOT_ROTATION3: return "VPOT_ROTATION3";
            case VPOT_ROTATION4: return "VPOT_ROTATION4";
            case VPOT_ROTATION5: return "VPOT_ROTATION5";
            case VPOT_ROTATION6: return "VPOT_ROTATION6";
            case VPOT_ROTATION7: return "VPOT_ROTATION7";
            case VPOT_ROTATION8: return "VPOT_ROTATION8";
            case EXTERNAL_CONTROL: return "EXTERNAL_CONTROL";
            case VPOT_LED_RING0: return "VPOT_LED_RING0";
            case VPOT_LED_RING1: return "VPOT_LED_RING1";
            case VPOT_LED_RING2: return "VPOT_LED_RING2";
            case VPOT_LED_RING3: return "VPOT_LED_RING3";
            case VPOT_LED_RING4: return "VPOT_LED_RING4";
            case VPOT_LED_RING5: return "VPOT_LED_RING5";
            case VPOT_LED_RING6: return "VPOT_LED_RING6";
            case VPOT_LED_RING7: return "VPOT_LED_RING7";
            case VPOT_LED_RING8: return "VPOT_LED_RING8";
            case JOG_WHEEL: return "JOG_WHEEL";
            case TIMECODE_DIGIT0: return "TIMECODE_DIGIT0";
            case TIMECODE_DIGIT1: return "TIMECODE_DIGIT1";
            case TIMECODE_DIGIT2: return "TIMECODE_DIGIT2";
            case TIMECODE_DIGIT3: return "TIMECODE_DIGIT3";
            case TIMECODE_DIGIT4: return "TIMECODE_DIGIT4";
            case TIMECODE_DIGIT5: return "TIMECODE_DIGIT5";
            case TIMECODE_DIGIT6: return "TIMECODE_DIGIT6";
            case TIMECODE_DIGIT7: return "TIMECODE_DIGIT7";
            case TIMECODE_DIGIT8: return "TIMECODE_DIGIT8";
            case TIMECODE_DIGIT9: return "TIMECODE_DIGIT9";
            case ASSIGNMENT_DIGIT1: return "ASSIGNMENT_DIGIT1";
            case ASSIGNMENT_DIGIT2: return "ASSIGNMENT_DIGIT2";
            default: return "UKNOWN_CONTROL_MAPPING";
            }
        }

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

        inline const char* toString(PitchBendMapping n){
            switch (n) {
                case FADER_POSITION0: return "FADER_POSITION0";
                case FADER_POSITION1: return "FADER_POSITION1";
                case FADER_POSITION2: return "FADER_POSITION2";
                case FADER_POSITION3: return "FADER_POSITION3";
                case FADER_POSITION4: return "FADER_POSITION4";
                case FADER_POSITION5: return "FADER_POSITION5";
                case FADER_POSITION6: return "FADER_POSITION6";
                case FADER_POSITION7: return "FADER_POSITION7";
                case FADER_POSITION_MASTER: return "FADER_POSITION_MASTER";
                default: return "UKNOWN_FADER";
            }
        }

        enum ChannelPressureMapping : unsigned char{
            METERING = 0,
        };
        inline const char* toString(ChannelPressureMapping n){
            switch (n) {
                case METERING: return "METERING";
                default: return "UKNOWN_PRESSURE";
            }
        }
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

    inline const char* toString(SystemMessages n){
        switch (n) {
            case SystemExclusive:  return "SystemExclusive";
            case MIDITimeCodeQtrFrame:  return "MIDITimeCodeQtrFrame";
            case SongPositionPointer:  return "SongPositionPointer";
            case SongSelect:  return "SongSelect";
            case Undefined0:  return "Undefined0";
            case Undefined1:  return "Undefined1";
            case TuneRequest:  return "TuneRequest";
            case EndOfSysEx:  return "EndOfSysEx";
            case TimingClock:  return "TimingClock";
            case Undefined2:  return "Undefined2";
            case Start:  return "Start";
            case Continue:  return "Continue";
            case Stop:  return "Stop";
            case Undefined3:  return "Undefined3";
            case ActiveSensing:  return "ActiveSensing";
            case SystemReset:  return "SystemReset";
            default: return "UNKNOWN_SYS_MSG";
        }
    }
}