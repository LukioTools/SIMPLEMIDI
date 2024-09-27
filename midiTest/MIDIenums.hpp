#pragma once


namespace MIDI {

#ifndef ARDUINO
#define PROGMEM 
using size_t = unsigned short;
void strcpy_P(const char*, const char*);
#endif


    namespace PROGMEM_STRINGS {
        constexpr const char REC1[]                     PROGMEM = "REC1";
        constexpr const char REC2[]                     PROGMEM = "REC2";
        constexpr const char REC3[]                     PROGMEM = "REC3";
        constexpr const char REC4[]                     PROGMEM = "REC4";
        constexpr const char REC5[]                     PROGMEM = "REC5";
        constexpr const char REC6[]                     PROGMEM = "REC6";
        constexpr const char REC7[]                     PROGMEM = "REC7";
        constexpr const char REC8[]                     PROGMEM = "REC8";
        constexpr const char SOLO1[]                    PROGMEM = "SOLO1";
        constexpr const char SOLO2[]                    PROGMEM = "SOLO2";
        constexpr const char SOLO3[]                    PROGMEM = "SOLO3";
        constexpr const char SOLO4[]                    PROGMEM = "SOLO4";
        constexpr const char SOLO5[]                    PROGMEM = "SOLO5";
        constexpr const char SOLO6[]                    PROGMEM = "SOLO6";
        constexpr const char SOLO7[]                    PROGMEM = "SOLO7";
        constexpr const char SOLO8[]                    PROGMEM = "SOLO8";
        constexpr const char MUTE1[]                    PROGMEM = "MUTE1";
        constexpr const char MUTE2[]                    PROGMEM = "MUTE2";
        constexpr const char MUTE3[]                    PROGMEM = "MUTE3";
        constexpr const char MUTE4[]                    PROGMEM = "MUTE4";
        constexpr const char MUTE5[]                    PROGMEM = "MUTE5";
        constexpr const char MUTE6[]                    PROGMEM = "MUTE6";
        constexpr const char MUTE7[]                    PROGMEM = "MUTE7";
        constexpr const char MUTE8[]                    PROGMEM = "MUTE8";
        constexpr const char SELECT1[]                  PROGMEM = "SELECT1";
        constexpr const char SELECT2[]                  PROGMEM = "SELECT2";
        constexpr const char SELECT3[]                  PROGMEM = "SELECT3";
        constexpr const char SELECT4[]                  PROGMEM = "SELECT4";
        constexpr const char SELECT5[]                  PROGMEM = "SELECT5";
        constexpr const char SELECT6[]                  PROGMEM = "SELECT6";
        constexpr const char SELECT7[]                  PROGMEM = "SELECT7";
        constexpr const char SELECT8[]                  PROGMEM = "SELECT8";
        constexpr const char VPOT_SWITCH1[]             PROGMEM = "VPOT_SWITCH1";
        constexpr const char VPOT_SWITCH2[]             PROGMEM = "VPOT_SWITCH2";
        constexpr const char VPOT_SWITCH3[]             PROGMEM = "VPOT_SWITCH3";
        constexpr const char VPOT_SWITCH4[]             PROGMEM = "VPOT_SWITCH4";
        constexpr const char VPOT_SWITCH5[]             PROGMEM = "VPOT_SWITCH5";
        constexpr const char VPOT_SWITCH6[]             PROGMEM = "VPOT_SWITCH6";
        constexpr const char VPOT_SWITCH7[]             PROGMEM = "VPOT_SWITCH7";
        constexpr const char VPOT_SWITCH8[]             PROGMEM = "VPOT_SWITCH8";
        constexpr const char ASSIGN_TRACK[]             PROGMEM = "ASSIGN_TRACK";
        constexpr const char ASSIGN_SEND[]              PROGMEM = "ASSIGN_SEND";
        constexpr const char ASSIGN_PAN[]               PROGMEM = "ASSIGN_PAN";
        constexpr const char ASSIGN_PLUG_IN[]           PROGMEM = "ASSIGN_PLUG_IN";
        constexpr const char ASSIGN_EQ[]                PROGMEM = "ASSIGN_EQ";
        constexpr const char ASSIGN_INSTRUMENT[]        PROGMEM = "ASSIGN_INSTRUMENT";
        constexpr const char BANK_LEFT[]                PROGMEM = "BANK_LEFT";
        constexpr const char BANK_RIGHT[]               PROGMEM = "BANK_RIGHT";
        constexpr const char CHANNEL_LEFT[]             PROGMEM = "CHANNEL_LEFT";
        constexpr const char CHANNEL_RIGHT[]            PROGMEM = "CHANNEL_RIGHT";
        constexpr const char FLIP[]                     PROGMEM = "FLIP";
        constexpr const char GLOBAL[]                   PROGMEM = "GLOBAL";
        constexpr const char NAME_VALUE_BUTTON[]        PROGMEM = "NAME_VALUE_BUTTON";
        constexpr const char SMPTE_BEATS_BUTTON[]       PROGMEM = "SMPTE_BEATS_BUTTON";
        constexpr const char F1[]                       PROGMEM = "F1";
        constexpr const char F2[]                       PROGMEM = "F2";
        constexpr const char F3[]                       PROGMEM = "F3";
        constexpr const char F4[]                       PROGMEM = "F4";
        constexpr const char F5[]                       PROGMEM = "F5";
        constexpr const char F6[]                       PROGMEM = "F6";
        constexpr const char F7[]                       PROGMEM = "F7";
        constexpr const char F8[]                       PROGMEM = "F8";
        constexpr const char MIDI_TRACKS[]              PROGMEM = "MIDI_TRACKS";
        constexpr const char INPUTS[]                   PROGMEM = "INPUTS";
        constexpr const char AUDIO_TRACKS[]             PROGMEM = "AUDIO_TRACKS";
        constexpr const char AUDIO_INSTRUMENTS[]        PROGMEM = "AUDIO_INSTRUMENTS";
        constexpr const char AUX[]                      PROGMEM = "AUX";
        constexpr const char BUSSES[]                   PROGMEM = "BUSSES";
        constexpr const char OUTPUTS[]                  PROGMEM = "OUTPUTS";
        constexpr const char USER[]                     PROGMEM = "USER";
        constexpr const char SHIFT[]                    PROGMEM = "SHIFT";
        constexpr const char OPTION[]                   PROGMEM = "OPTION";
        constexpr const char CONTROL[]                  PROGMEM = "CONTROL";
        constexpr const char ALT[]                      PROGMEM = "ALT";
        constexpr const char READ_OFF[]                 PROGMEM = "READ_OFF";
        constexpr const char WRITE[]                    PROGMEM = "WRITE";
        constexpr const char TRIM[]                     PROGMEM = "TRIM";
        constexpr const char TOUCH[]                    PROGMEM = "TOUCH";
        constexpr const char LATCH[]                    PROGMEM = "LATCH";
        constexpr const char GROUP[]                    PROGMEM = "GROUP";
        constexpr const char SAVE[]                     PROGMEM = "SAVE";
        constexpr const char UNDO[]                     PROGMEM = "UNDO";
        constexpr const char CANCEL[]                   PROGMEM = "CANCEL";
        constexpr const char ENTER[]                    PROGMEM = "ENTER";
        constexpr const char MARKERS[]                  PROGMEM = "MARKERS";
        constexpr const char NUDGE[]                    PROGMEM = "NUDGE";
        constexpr const char CYCLE[]                    PROGMEM = "CYCLE";
        constexpr const char DROP[]                     PROGMEM = "DROP";
        constexpr const char REPLACE[]                  PROGMEM = "REPLACE";
        constexpr const char CLICK[]                    PROGMEM = "CLICK";
        constexpr const char SOLO[]                     PROGMEM = "SOLO";
        constexpr const char REWIND[]                   PROGMEM = "REWIND";
        constexpr const char FORWARD[]                  PROGMEM = "FORWARD";
        constexpr const char STOP[]                     PROGMEM = "STOP";
        constexpr const char PLAY[]                     PROGMEM = "PLAY";
        constexpr const char RECORD[]                   PROGMEM = "RECORD";
        constexpr const char UP[]                       PROGMEM = "UP";
        constexpr const char DOWN[]                     PROGMEM = "DOWN";
        constexpr const char LEFT[]                     PROGMEM = "LEFT";
        constexpr const char RIGHT[]                    PROGMEM = "RIGHT";
        constexpr const char ZOOM[]                     PROGMEM = "ZOOM";
        constexpr const char SCRUB[]                    PROGMEM = "SCRUB";
        constexpr const char USER_SWITCH_1[]            PROGMEM = "USER_SWITCH_1";
        constexpr const char USER_SWITCH_2[]            PROGMEM = "USER_SWITCH_2";
        constexpr const char FADER_1_TOUCHED[]          PROGMEM = "FADER_1_TOUCHED";
        constexpr const char FADER_2_TOUCHED[]          PROGMEM = "FADER_2_TOUCHED";
        constexpr const char FADER_3_TOUCHED[]          PROGMEM = "FADER_3_TOUCHED";
        constexpr const char FADER_4_TOUCHED[]          PROGMEM = "FADER_4_TOUCHED";
        constexpr const char FADER_5_TOUCHED[]          PROGMEM = "FADER_5_TOUCHED";
        constexpr const char FADER_6_TOUCHED[]          PROGMEM = "FADER_6_TOUCHED";
        constexpr const char FADER_7_TOUCHED[]          PROGMEM = "FADER_7_TOUCHED";
        constexpr const char FADER_8_TOUCHED[]          PROGMEM = "FADER_8_TOUCHED";
        constexpr const char MASTER_FADER_TOUCHED[]     PROGMEM = "MASTER_FADER_TOUCHED";
        constexpr const char SMPTE_LED[]                PROGMEM = "SMPTE_LED";
        constexpr const char BEATS_LED[]                PROGMEM = "BEATS_LED";
        constexpr const char RUDE_SOLO_LED[]            PROGMEM = "RUDE_SOLO_LED";
        constexpr const char RELAY_CLICK0[]             PROGMEM = "RELAY_CLICK0";
        constexpr const char RELAY_CLICK1[]             PROGMEM = "RELAY_CLICK1";
        constexpr const char RELAY_CLICK2[]             PROGMEM = "RELAY_CLICK2";
        constexpr const char RELAY_CLICK3[]             PROGMEM = "RELAY_CLICK3";
        constexpr const char KEY_DEFAULT[]              PROGMEM    = "UNKNOWN_KEY";

        constexpr const char VPOT_ROTATION0[]           PROGMEM =    "VPOT_ROTATION0";
        constexpr const char VPOT_ROTATION1[]           PROGMEM =    "VPOT_ROTATION1";
        constexpr const char VPOT_ROTATION2[]           PROGMEM =    "VPOT_ROTATION2";
        constexpr const char VPOT_ROTATION3[]           PROGMEM =    "VPOT_ROTATION3";
        constexpr const char VPOT_ROTATION4[]           PROGMEM =    "VPOT_ROTATION4";
        constexpr const char VPOT_ROTATION5[]           PROGMEM =    "VPOT_ROTATION5";
        constexpr const char VPOT_ROTATION6[]           PROGMEM =    "VPOT_ROTATION6";
        constexpr const char VPOT_ROTATION7[]           PROGMEM =    "VPOT_ROTATION7";
        constexpr const char VPOT_ROTATION8[]           PROGMEM =    "VPOT_ROTATION8";
        constexpr const char EXTERNAL_CONTROL[]         PROGMEM =    "EXTERNAL_CONTROL";
        constexpr const char VPOT_LED_RING0[]           PROGMEM =    "VPOT_LED_RING0";
        constexpr const char VPOT_LED_RING1[]           PROGMEM =    "VPOT_LED_RING1";
        constexpr const char VPOT_LED_RING2[]           PROGMEM =    "VPOT_LED_RING2";
        constexpr const char VPOT_LED_RING3[]           PROGMEM =    "VPOT_LED_RING3";
        constexpr const char VPOT_LED_RING4[]           PROGMEM =    "VPOT_LED_RING4";
        constexpr const char VPOT_LED_RING5[]           PROGMEM =    "VPOT_LED_RING5";
        constexpr const char VPOT_LED_RING6[]           PROGMEM =    "VPOT_LED_RING6";
        constexpr const char VPOT_LED_RING7[]           PROGMEM =    "VPOT_LED_RING7";
        constexpr const char VPOT_LED_RING8[]           PROGMEM =    "VPOT_LED_RING8";
        constexpr const char JOG_WHEEL[]                PROGMEM =    "JOG_WHEEL";
        constexpr const char TIMECODE_DIGIT0[]          PROGMEM =    "TIMECODE_DIGIT0";
        constexpr const char TIMECODE_DIGIT1[]          PROGMEM =    "TIMECODE_DIGIT1";
        constexpr const char TIMECODE_DIGIT2[]          PROGMEM =    "TIMECODE_DIGIT2";
        constexpr const char TIMECODE_DIGIT3[]          PROGMEM =    "TIMECODE_DIGIT3";
        constexpr const char TIMECODE_DIGIT4[]          PROGMEM =    "TIMECODE_DIGIT4";
        constexpr const char TIMECODE_DIGIT5[]          PROGMEM =    "TIMECODE_DIGIT5";
        constexpr const char TIMECODE_DIGIT6[]          PROGMEM =    "TIMECODE_DIGIT6";
        constexpr const char TIMECODE_DIGIT7[]          PROGMEM =    "TIMECODE_DIGIT7";
        constexpr const char TIMECODE_DIGIT8[]          PROGMEM =    "TIMECODE_DIGIT8";
        constexpr const char TIMECODE_DIGIT9[]          PROGMEM =    "TIMECODE_DIGIT9";
        constexpr const char ASSIGNMENT_DIGIT1[]        PROGMEM =    "ASSIGNMENT_DIGIT1";
        constexpr const char ASSIGNMENT_DIGIT2[]        PROGMEM =    "ASSIGNMENT_DIGIT2";
        constexpr const char CONTROL_DEFAULT[]          PROGMEM =    "UKNOWN_CONTROL_MAPPING";


        constexpr const char FADER_POSITION0[]          PROGMEM =  "FADER_POSITION0";
        constexpr const char FADER_POSITION1[]          PROGMEM =  "FADER_POSITION1";
        constexpr const char FADER_POSITION2[]          PROGMEM =  "FADER_POSITION2";
        constexpr const char FADER_POSITION3[]          PROGMEM =  "FADER_POSITION3";
        constexpr const char FADER_POSITION4[]          PROGMEM =  "FADER_POSITION4";
        constexpr const char FADER_POSITION5[]          PROGMEM =  "FADER_POSITION5";
        constexpr const char FADER_POSITION6[]          PROGMEM =  "FADER_POSITION6";
        constexpr const char FADER_POSITION7[]          PROGMEM =  "FADER_POSITION7";
        constexpr const char FADER_POSITION_MASTER[]    PROGMEM =  "FADER_POSITION_MASTER";
        constexpr const char FADER_DEFAULT[]            PROGMEM =  "UKNOWN_FADER";

        constexpr const char METERING[]                 PROGMEM = "METERING";
        constexpr const char METERING_DEFAULT[]         PROGMEM = "UNKNOWN_METERING";

        constexpr const char NoteOFF[]                  PROGMEM = "NoteOFF";
        constexpr const char NoteON[]                   PROGMEM = "NoteON";
        constexpr const char PolyphonicAftertouch[]     PROGMEM = "PolyphonicAftertouch";
        constexpr const char ControlModeChange[]        PROGMEM = "ControlModeChange";
        constexpr const char ProgramChange[]            PROGMEM = "ProgramChange";
        constexpr const char ChannelAftertouch[]        PROGMEM = "ChannelAftertouch";
        constexpr const char PitchBendChange[]          PROGMEM = "PitchBendChange";
        constexpr const char SystemMessage[]            PROGMEM = "SystemMessage";
        constexpr const char COMMAND_DEFAULT[]          PROGMEM = "UNKNOWN_COMMAND";

        constexpr const char SystemExclusive[]          PROGMEM = "SystemExclusive";
        constexpr const char MIDITimeCodeQtrFrame[]     PROGMEM = "MIDITimeCodeQtrFrame";
        constexpr const char SongPositionPointer[]      PROGMEM = "SongPositionPointer";
        constexpr const char SongSelect[]               PROGMEM = "SongSelect";
        constexpr const char Undefined0[]               PROGMEM = "Undefined0";
        constexpr const char Undefined1[]               PROGMEM = "Undefined1";
        constexpr const char TuneRequest[]              PROGMEM = "TuneRequest";
        constexpr const char EndOfSysEx[]               PROGMEM = "EndOfSysEx";
        constexpr const char TimingClock[]              PROGMEM = "TimingClock";
        constexpr const char Undefined2[]               PROGMEM = "Undefined2";
        constexpr const char Start[]                    PROGMEM = "Start";
        constexpr const char Continue[]                 PROGMEM = "Continue";
        constexpr const char Stop[]                     PROGMEM = "Stop";
        constexpr const char Undefined3[]               PROGMEM = "Undefined3";
        constexpr const char ActiveSensing[]            PROGMEM = "ActiveSensing";
        constexpr const char SystemReset[]              PROGMEM = "SystemReset";
        constexpr const char SYSMSG_DEFAULT[]             PROGMEM = "UNKNOWN_SYS_MSG";
    }  


    /*
    

    // Compile-time string length function (like strlen but constexpr)
    constexpr size_t str_len(const char* str, size_t count = 0) {
      return (str[count] == '\0') ? count : str_len(str, count + 1);
    }
    */
    // Function to calculate string length at compile time
    constexpr size_t str_len(const char* str, size_t count = 0) {
      return (str[count] == '\0') ? count : (str[count+1] == '\0') ? count+1 : str_len(str, count + 2);
    }
    // Base case for variadic template: single string
    constexpr size_t str_len_max(const char* str) {
        return str_len(str);
    }
    // Base case for variadic template: single string
    constexpr size_t str_len_max(){
        return 0;
    }
    // Recursive variadic template function to get the maximum length of multiple strings
    template <typename... Args>
    constexpr size_t str_len_max(const char* first, Args... args) {
        return (str_len(first) < str_len_max(args...) ? str_len_max(args...) : str_len(first));
    }

    #ifdef ARDUINO
    constexpr size_t maxSize = str_len_max(
        PROGMEM_STRINGS::REC1,
        PROGMEM_STRINGS::REC2,
        PROGMEM_STRINGS::REC3,
        PROGMEM_STRINGS::REC4,
        PROGMEM_STRINGS::REC5,
        PROGMEM_STRINGS::REC6,
        PROGMEM_STRINGS::REC7,
        PROGMEM_STRINGS::REC8,
        PROGMEM_STRINGS::SOLO1,
        PROGMEM_STRINGS::SOLO2,
        PROGMEM_STRINGS::SOLO3,
        PROGMEM_STRINGS::SOLO4,
        PROGMEM_STRINGS::SOLO5,
        PROGMEM_STRINGS::SOLO6,
        PROGMEM_STRINGS::SOLO7,
        PROGMEM_STRINGS::SOLO8,
        PROGMEM_STRINGS::MUTE1,
        PROGMEM_STRINGS::MUTE2,
        PROGMEM_STRINGS::MUTE3,
        PROGMEM_STRINGS::MUTE4,
        PROGMEM_STRINGS::MUTE5,
        PROGMEM_STRINGS::MUTE6,
        PROGMEM_STRINGS::MUTE7,
        PROGMEM_STRINGS::MUTE8,
        PROGMEM_STRINGS::SELECT1,
        PROGMEM_STRINGS::SELECT2,
        PROGMEM_STRINGS::SELECT3,
        PROGMEM_STRINGS::SELECT4,
        PROGMEM_STRINGS::SELECT5,
        PROGMEM_STRINGS::SELECT6,
        PROGMEM_STRINGS::SELECT7,
        PROGMEM_STRINGS::SELECT8,
        PROGMEM_STRINGS::VPOT_SWITCH1,
        PROGMEM_STRINGS::VPOT_SWITCH2,
        PROGMEM_STRINGS::VPOT_SWITCH3,
        PROGMEM_STRINGS::VPOT_SWITCH4,
        PROGMEM_STRINGS::VPOT_SWITCH5,
        PROGMEM_STRINGS::VPOT_SWITCH6,
        PROGMEM_STRINGS::VPOT_SWITCH7,
        PROGMEM_STRINGS::VPOT_SWITCH8,
        PROGMEM_STRINGS::ASSIGN_TRACK,
        PROGMEM_STRINGS::ASSIGN_SEND,
        PROGMEM_STRINGS::ASSIGN_PAN,
        PROGMEM_STRINGS::ASSIGN_PLUG_IN,
        PROGMEM_STRINGS::ASSIGN_EQ,
        PROGMEM_STRINGS::ASSIGN_INSTRUMENT,
        PROGMEM_STRINGS::BANK_LEFT,
        PROGMEM_STRINGS::BANK_RIGHT,
        PROGMEM_STRINGS::CHANNEL_LEFT,
        PROGMEM_STRINGS::CHANNEL_RIGHT,
        PROGMEM_STRINGS::FLIP,
        PROGMEM_STRINGS::GLOBAL,
        PROGMEM_STRINGS::NAME_VALUE_BUTTON,
        PROGMEM_STRINGS::SMPTE_BEATS_BUTTON,
        PROGMEM_STRINGS::F1,
        PROGMEM_STRINGS::F2,
        PROGMEM_STRINGS::F3,
        PROGMEM_STRINGS::F4,
        PROGMEM_STRINGS::F5,
        PROGMEM_STRINGS::F6,
        PROGMEM_STRINGS::F7,
        PROGMEM_STRINGS::F8,
        PROGMEM_STRINGS::MIDI_TRACKS,
        PROGMEM_STRINGS::INPUTS,
        PROGMEM_STRINGS::AUDIO_TRACKS,
        PROGMEM_STRINGS::AUDIO_INSTRUMENTS,
        PROGMEM_STRINGS::AUX,
        PROGMEM_STRINGS::BUSSES,
        PROGMEM_STRINGS::OUTPUTS,
        PROGMEM_STRINGS::USER,
        PROGMEM_STRINGS::SHIFT,
        PROGMEM_STRINGS::OPTION,
        PROGMEM_STRINGS::CONTROL,
        PROGMEM_STRINGS::ALT,
        PROGMEM_STRINGS::READ_OFF,
        PROGMEM_STRINGS::WRITE,
        PROGMEM_STRINGS::TRIM,
        PROGMEM_STRINGS::TOUCH,
        PROGMEM_STRINGS::LATCH,
        PROGMEM_STRINGS::GROUP,
        PROGMEM_STRINGS::SAVE,
        PROGMEM_STRINGS::UNDO,
        PROGMEM_STRINGS::CANCEL,
        PROGMEM_STRINGS::ENTER,
        PROGMEM_STRINGS::MARKERS,
        PROGMEM_STRINGS::NUDGE,
        PROGMEM_STRINGS::CYCLE,
        PROGMEM_STRINGS::DROP,
        PROGMEM_STRINGS::REPLACE,
        PROGMEM_STRINGS::CLICK,
        PROGMEM_STRINGS::SOLO,
        PROGMEM_STRINGS::REWIND,
        PROGMEM_STRINGS::FORWARD,
        PROGMEM_STRINGS::STOP,
        PROGMEM_STRINGS::PLAY,
        PROGMEM_STRINGS::RECORD,
        PROGMEM_STRINGS::UP,
        PROGMEM_STRINGS::DOWN,
        PROGMEM_STRINGS::LEFT,
        PROGMEM_STRINGS::RIGHT,
        PROGMEM_STRINGS::ZOOM,
        PROGMEM_STRINGS::SCRUB,
        PROGMEM_STRINGS::USER_SWITCH_1,
        PROGMEM_STRINGS::USER_SWITCH_2,
        PROGMEM_STRINGS::FADER_1_TOUCHED,
        PROGMEM_STRINGS::FADER_2_TOUCHED,
        PROGMEM_STRINGS::FADER_3_TOUCHED,
        PROGMEM_STRINGS::FADER_4_TOUCHED,
        PROGMEM_STRINGS::FADER_5_TOUCHED,
        PROGMEM_STRINGS::FADER_6_TOUCHED,
        PROGMEM_STRINGS::FADER_7_TOUCHED,
        PROGMEM_STRINGS::FADER_8_TOUCHED,
        PROGMEM_STRINGS::MASTER_FADER_TOUCHED,
        PROGMEM_STRINGS::SMPTE_LED,
        PROGMEM_STRINGS::BEATS_LED,
        PROGMEM_STRINGS::RUDE_SOLO_LED,
        PROGMEM_STRINGS::RELAY_CLICK0,
        PROGMEM_STRINGS::RELAY_CLICK1,
        PROGMEM_STRINGS::RELAY_CLICK2,
        PROGMEM_STRINGS::RELAY_CLICK3,
        PROGMEM_STRINGS::KEY_DEFAULT
    );
    #else
    constexpr size_t maxSize = 20;
    #endif
    inline char loadedString[maxSize + 1] = {0}; 


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
                case REC1:                 strcpy_P(loadedString, PROGMEM_STRINGS::REC1); return loadedString;
                case REC2:                 strcpy_P(loadedString, PROGMEM_STRINGS::REC2); return loadedString;
                case REC3:                 strcpy_P(loadedString, PROGMEM_STRINGS::REC3); return loadedString;
                case REC4:                 strcpy_P(loadedString, PROGMEM_STRINGS::REC4); return loadedString;
                case REC5:                 strcpy_P(loadedString, PROGMEM_STRINGS::REC5); return loadedString;
                case REC6:                 strcpy_P(loadedString, PROGMEM_STRINGS::REC6); return loadedString;
                case REC7:                 strcpy_P(loadedString, PROGMEM_STRINGS::REC7); return loadedString;
                case REC8:                 strcpy_P(loadedString, PROGMEM_STRINGS::REC8); return loadedString;
                case SOLO1:                strcpy_P(loadedString, PROGMEM_STRINGS::SOLO1); return loadedString;
                case SOLO2:                strcpy_P(loadedString, PROGMEM_STRINGS::SOLO2); return loadedString;
                case SOLO3:                strcpy_P(loadedString, PROGMEM_STRINGS::SOLO3); return loadedString;
                case SOLO4:                strcpy_P(loadedString, PROGMEM_STRINGS::SOLO4); return loadedString;
                case SOLO5:                strcpy_P(loadedString, PROGMEM_STRINGS::SOLO5); return loadedString;
                case SOLO6:                strcpy_P(loadedString, PROGMEM_STRINGS::SOLO6); return loadedString;
                case SOLO7:                strcpy_P(loadedString, PROGMEM_STRINGS::SOLO7); return loadedString;
                case SOLO8:                strcpy_P(loadedString, PROGMEM_STRINGS::SOLO8); return loadedString;
                case MUTE1:                strcpy_P(loadedString, PROGMEM_STRINGS::MUTE1); return loadedString;
                case MUTE2:                strcpy_P(loadedString, PROGMEM_STRINGS::MUTE2); return loadedString;
                case MUTE3:                strcpy_P(loadedString, PROGMEM_STRINGS::MUTE3); return loadedString;
                case MUTE4:                strcpy_P(loadedString, PROGMEM_STRINGS::MUTE4); return loadedString;
                case MUTE5:                strcpy_P(loadedString, PROGMEM_STRINGS::MUTE5); return loadedString;
                case MUTE6:                strcpy_P(loadedString, PROGMEM_STRINGS::MUTE6); return loadedString;
                case MUTE7:                strcpy_P(loadedString, PROGMEM_STRINGS::MUTE7); return loadedString;
                case MUTE8:                strcpy_P(loadedString, PROGMEM_STRINGS::MUTE8); return loadedString;
                case SELECT1:              strcpy_P(loadedString, PROGMEM_STRINGS::SELECT1); return loadedString;
                case SELECT2:              strcpy_P(loadedString, PROGMEM_STRINGS::SELECT2); return loadedString;
                case SELECT3:              strcpy_P(loadedString, PROGMEM_STRINGS::SELECT3); return loadedString;
                case SELECT4:              strcpy_P(loadedString, PROGMEM_STRINGS::SELECT4); return loadedString;
                case SELECT5:              strcpy_P(loadedString, PROGMEM_STRINGS::SELECT5); return loadedString;
                case SELECT6:              strcpy_P(loadedString, PROGMEM_STRINGS::SELECT6); return loadedString;
                case SELECT7:              strcpy_P(loadedString, PROGMEM_STRINGS::SELECT7); return loadedString;
                case SELECT8:              strcpy_P(loadedString, PROGMEM_STRINGS::SELECT8); return loadedString;
                case VPOT_SWITCH1:         strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_SWITCH1); return loadedString;
                case VPOT_SWITCH2:         strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_SWITCH2); return loadedString;
                case VPOT_SWITCH3:         strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_SWITCH3); return loadedString;
                case VPOT_SWITCH4:         strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_SWITCH4); return loadedString;
                case VPOT_SWITCH5:         strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_SWITCH5); return loadedString;
                case VPOT_SWITCH6:         strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_SWITCH6); return loadedString;
                case VPOT_SWITCH7:         strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_SWITCH7); return loadedString;
                case VPOT_SWITCH8:         strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_SWITCH8); return loadedString;
                case ASSIGN_TRACK:         strcpy_P(loadedString, PROGMEM_STRINGS::ASSIGN_TRACK); return loadedString;
                case ASSIGN_SEND:          strcpy_P(loadedString, PROGMEM_STRINGS::ASSIGN_SEND); return loadedString;
                case ASSIGN_PAN:           strcpy_P(loadedString, PROGMEM_STRINGS::ASSIGN_PAN); return loadedString;
                case ASSIGN_PLUG_IN:       strcpy_P(loadedString, PROGMEM_STRINGS::ASSIGN_PLUG_IN); return loadedString;
                case ASSIGN_EQ:            strcpy_P(loadedString, PROGMEM_STRINGS::ASSIGN_EQ); return loadedString;
                case ASSIGN_INSTRUMENT:    strcpy_P(loadedString, PROGMEM_STRINGS::ASSIGN_INSTRUMENT); return loadedString;
                case BANK_LEFT:            strcpy_P(loadedString, PROGMEM_STRINGS::BANK_LEFT); return loadedString;
                case BANK_RIGHT:           strcpy_P(loadedString, PROGMEM_STRINGS::BANK_RIGHT); return loadedString;
                case CHANNEL_LEFT:         strcpy_P(loadedString, PROGMEM_STRINGS::CHANNEL_LEFT); return loadedString;
                case CHANNEL_RIGHT:        strcpy_P(loadedString, PROGMEM_STRINGS::CHANNEL_RIGHT); return loadedString;
                case FLIP:                 strcpy_P(loadedString, PROGMEM_STRINGS::FLIP); return loadedString;
                case GLOBAL:               strcpy_P(loadedString, PROGMEM_STRINGS::GLOBAL); return loadedString;
                case NAME_VALUE_BUTTON:    strcpy_P(loadedString, PROGMEM_STRINGS::NAME_VALUE_BUTTON); return loadedString;
                case SMPTE_BEATS_BUTTON:   strcpy_P(loadedString, PROGMEM_STRINGS::SMPTE_BEATS_BUTTON); return loadedString;
                case F1:                   strcpy_P(loadedString, PROGMEM_STRINGS::F1); return loadedString;
                case F2:                   strcpy_P(loadedString, PROGMEM_STRINGS::F2); return loadedString;
                case F3:                   strcpy_P(loadedString, PROGMEM_STRINGS::F3); return loadedString;
                case F4:                   strcpy_P(loadedString, PROGMEM_STRINGS::F4); return loadedString;
                case F5:                   strcpy_P(loadedString, PROGMEM_STRINGS::F5); return loadedString;
                case F6:                   strcpy_P(loadedString, PROGMEM_STRINGS::F6); return loadedString;
                case F7:                   strcpy_P(loadedString, PROGMEM_STRINGS::F7); return loadedString;
                case F8:                   strcpy_P(loadedString, PROGMEM_STRINGS::F8); return loadedString;
                case MIDI_TRACKS:          strcpy_P(loadedString, PROGMEM_STRINGS::MIDI_TRACKS); return loadedString;
                case INPUTS:               strcpy_P(loadedString, PROGMEM_STRINGS::INPUTS); return loadedString;
                case AUDIO_TRACKS:         strcpy_P(loadedString, PROGMEM_STRINGS::AUDIO_TRACKS); return loadedString;
                case AUDIO_INSTRUMENTS:    strcpy_P(loadedString, PROGMEM_STRINGS::AUDIO_INSTRUMENTS); return loadedString;
                case AUX:                  strcpy_P(loadedString, PROGMEM_STRINGS::AUX); return loadedString;
                case BUSSES:               strcpy_P(loadedString, PROGMEM_STRINGS::BUSSES); return loadedString;
                case OUTPUTS:              strcpy_P(loadedString, PROGMEM_STRINGS::OUTPUTS); return loadedString;
                case USER:                 strcpy_P(loadedString, PROGMEM_STRINGS::USER); return loadedString;
                case SHIFT:                strcpy_P(loadedString, PROGMEM_STRINGS::SHIFT); return loadedString;
                case OPTION:               strcpy_P(loadedString, PROGMEM_STRINGS::OPTION); return loadedString;
                case CONTROL:              strcpy_P(loadedString, PROGMEM_STRINGS::CONTROL); return loadedString;
                case ALT:                  strcpy_P(loadedString, PROGMEM_STRINGS::ALT); return loadedString;
                case READ_OFF:             strcpy_P(loadedString, PROGMEM_STRINGS::READ_OFF); return loadedString;
                case WRITE:                strcpy_P(loadedString, PROGMEM_STRINGS::WRITE); return loadedString;
                case TRIM:                 strcpy_P(loadedString, PROGMEM_STRINGS::TRIM); return loadedString;
                case TOUCH:                strcpy_P(loadedString, PROGMEM_STRINGS::TOUCH); return loadedString;
                case LATCH:                strcpy_P(loadedString, PROGMEM_STRINGS::LATCH); return loadedString;
                case GROUP:                strcpy_P(loadedString, PROGMEM_STRINGS::GROUP); return loadedString;
                case SAVE:                 strcpy_P(loadedString, PROGMEM_STRINGS::SAVE); return loadedString;
                case UNDO:                 strcpy_P(loadedString, PROGMEM_STRINGS::UNDO); return loadedString;
                case CANCEL:               strcpy_P(loadedString, PROGMEM_STRINGS::CANCEL); return loadedString;
                case ENTER:                strcpy_P(loadedString, PROGMEM_STRINGS::ENTER); return loadedString;
                case MARKERS:              strcpy_P(loadedString, PROGMEM_STRINGS::MARKERS); return loadedString;
                case NUDGE:                strcpy_P(loadedString, PROGMEM_STRINGS::NUDGE); return loadedString;
                case CYCLE:                strcpy_P(loadedString, PROGMEM_STRINGS::CYCLE); return loadedString;
                case DROP:                 strcpy_P(loadedString, PROGMEM_STRINGS::DROP); return loadedString;
                case REPLACE:              strcpy_P(loadedString, PROGMEM_STRINGS::REPLACE); return loadedString;
                case CLICK:                strcpy_P(loadedString, PROGMEM_STRINGS::CLICK); return loadedString;
                case SOLO:                 strcpy_P(loadedString, PROGMEM_STRINGS::SOLO); return loadedString;
                case REWIND:               strcpy_P(loadedString, PROGMEM_STRINGS::REWIND); return loadedString;
                case FORWARD:              strcpy_P(loadedString, PROGMEM_STRINGS::FORWARD); return loadedString;
                case STOP:                 strcpy_P(loadedString, PROGMEM_STRINGS::STOP); return loadedString;
                case PLAY:                 strcpy_P(loadedString, PROGMEM_STRINGS::PLAY); return loadedString;
                case RECORD:               strcpy_P(loadedString, PROGMEM_STRINGS::RECORD); return loadedString;
                case UP:                   strcpy_P(loadedString, PROGMEM_STRINGS::UP); return loadedString;
                case DOWN:                 strcpy_P(loadedString, PROGMEM_STRINGS::DOWN); return loadedString;
                case LEFT:                 strcpy_P(loadedString, PROGMEM_STRINGS::LEFT); return loadedString;
                case RIGHT:                strcpy_P(loadedString, PROGMEM_STRINGS::RIGHT); return loadedString;
                case ZOOM:                 strcpy_P(loadedString, PROGMEM_STRINGS::ZOOM); return loadedString;
                case SCRUB:                strcpy_P(loadedString, PROGMEM_STRINGS::SCRUB); return loadedString;
                case USER_SWITCH_1:        strcpy_P(loadedString, PROGMEM_STRINGS::USER_SWITCH_1); return loadedString;
                case USER_SWITCH_2:        strcpy_P(loadedString, PROGMEM_STRINGS::USER_SWITCH_2); return loadedString;
                case FADER_1_TOUCHED:      strcpy_P(loadedString, PROGMEM_STRINGS::FADER_1_TOUCHED); return loadedString;
                case FADER_2_TOUCHED:      strcpy_P(loadedString, PROGMEM_STRINGS::FADER_2_TOUCHED); return loadedString;
                case FADER_3_TOUCHED:      strcpy_P(loadedString, PROGMEM_STRINGS::FADER_3_TOUCHED); return loadedString;
                case FADER_4_TOUCHED:      strcpy_P(loadedString, PROGMEM_STRINGS::FADER_4_TOUCHED); return loadedString;
                case FADER_5_TOUCHED:      strcpy_P(loadedString, PROGMEM_STRINGS::FADER_5_TOUCHED); return loadedString;
                case FADER_6_TOUCHED:      strcpy_P(loadedString, PROGMEM_STRINGS::FADER_6_TOUCHED); return loadedString;
                case FADER_7_TOUCHED:      strcpy_P(loadedString, PROGMEM_STRINGS::FADER_7_TOUCHED); return loadedString;
                case FADER_8_TOUCHED:      strcpy_P(loadedString, PROGMEM_STRINGS::FADER_8_TOUCHED); return loadedString;
                case MASTER_FADER_TOUCHED: strcpy_P(loadedString, PROGMEM_STRINGS::MASTER_FADER_TOUCHED); return loadedString;
                case SMPTE_LED:            strcpy_P(loadedString, PROGMEM_STRINGS::SMPTE_LED); return loadedString;
                case BEATS_LED:            strcpy_P(loadedString, PROGMEM_STRINGS::BEATS_LED); return loadedString;
                case RUDE_SOLO_LED:        strcpy_P(loadedString, PROGMEM_STRINGS::RUDE_SOLO_LED); return loadedString;
                case RELAY_CLICK0:         strcpy_P(loadedString, PROGMEM_STRINGS::RELAY_CLICK0); return loadedString;
                case RELAY_CLICK1:         strcpy_P(loadedString, PROGMEM_STRINGS::RELAY_CLICK1); return loadedString;
                case RELAY_CLICK2:         strcpy_P(loadedString, PROGMEM_STRINGS::RELAY_CLICK2); return loadedString;
                case RELAY_CLICK3:         strcpy_P(loadedString, PROGMEM_STRINGS::RELAY_CLICK3); return loadedString;
                default:                   strcpy_P(loadedString, PROGMEM_STRINGS::KEY_DEFAULT); return loadedString;
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
                case VPOT_ROTATION0:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_ROTATION0);     return loadedString;
                case VPOT_ROTATION1:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_ROTATION1);     return loadedString;
                case VPOT_ROTATION2:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_ROTATION2);     return loadedString;
                case VPOT_ROTATION3:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_ROTATION3);     return loadedString;
                case VPOT_ROTATION4:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_ROTATION4);     return loadedString;
                case VPOT_ROTATION5:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_ROTATION5);     return loadedString;
                case VPOT_ROTATION6:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_ROTATION6);     return loadedString;
                case VPOT_ROTATION7:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_ROTATION7);     return loadedString;
                case VPOT_ROTATION8:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_ROTATION8);     return loadedString;
                case EXTERNAL_CONTROL:     strcpy_P(loadedString, PROGMEM_STRINGS::EXTERNAL_CONTROL);   return loadedString;
                case VPOT_LED_RING0:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_LED_RING0);     return loadedString;
                case VPOT_LED_RING1:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_LED_RING1);     return loadedString;
                case VPOT_LED_RING2:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_LED_RING2);     return loadedString;
                case VPOT_LED_RING3:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_LED_RING3);     return loadedString;
                case VPOT_LED_RING4:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_LED_RING4);     return loadedString;
                case VPOT_LED_RING5:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_LED_RING5);     return loadedString;
                case VPOT_LED_RING6:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_LED_RING6);     return loadedString;
                case VPOT_LED_RING7:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_LED_RING7);     return loadedString;
                case VPOT_LED_RING8:       strcpy_P(loadedString, PROGMEM_STRINGS::VPOT_LED_RING8);     return loadedString;
                case JOG_WHEEL:            strcpy_P(loadedString, PROGMEM_STRINGS::JOG_WHEEL);          return loadedString;
                case TIMECODE_DIGIT0:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT0);    return loadedString;
                case TIMECODE_DIGIT1:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT1);    return loadedString;
                case TIMECODE_DIGIT2:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT2);    return loadedString;
                case TIMECODE_DIGIT3:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT3);    return loadedString;
                case TIMECODE_DIGIT4:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT4);    return loadedString;
                case TIMECODE_DIGIT5:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT5);    return loadedString;
                case TIMECODE_DIGIT6:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT6);    return loadedString;
                case TIMECODE_DIGIT7:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT7);    return loadedString;
                case TIMECODE_DIGIT8:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT8);    return loadedString;
                case TIMECODE_DIGIT9:      strcpy_P(loadedString, PROGMEM_STRINGS::TIMECODE_DIGIT9);    return loadedString;
                case ASSIGNMENT_DIGIT1:    strcpy_P(loadedString, PROGMEM_STRINGS::ASSIGNMENT_DIGIT1);  return loadedString;
                case ASSIGNMENT_DIGIT2:    strcpy_P(loadedString, PROGMEM_STRINGS::ASSIGNMENT_DIGIT2);  return loadedString;
                default: strcpy_P(loadedString, PROGMEM_STRINGS::CONTROL_DEFAULT);                      return loadedString;
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
                case FADER_POSITION0:           strcpy_P(loadedString, PROGMEM_STRINGS::FADER_POSITION0); return loadedString;
                case FADER_POSITION1:           strcpy_P(loadedString, PROGMEM_STRINGS::FADER_POSITION1); return loadedString;
                case FADER_POSITION2:           strcpy_P(loadedString, PROGMEM_STRINGS::FADER_POSITION2); return loadedString;
                case FADER_POSITION3:           strcpy_P(loadedString, PROGMEM_STRINGS::FADER_POSITION3); return loadedString;
                case FADER_POSITION4:           strcpy_P(loadedString, PROGMEM_STRINGS::FADER_POSITION4); return loadedString;
                case FADER_POSITION5:           strcpy_P(loadedString, PROGMEM_STRINGS::FADER_POSITION5); return loadedString;
                case FADER_POSITION6:           strcpy_P(loadedString, PROGMEM_STRINGS::FADER_POSITION6); return loadedString;
                case FADER_POSITION7:           strcpy_P(loadedString, PROGMEM_STRINGS::FADER_POSITION7); return loadedString;
                case FADER_POSITION_MASTER:     strcpy_P(loadedString, PROGMEM_STRINGS::FADER_POSITION_MASTER); return loadedString;
                default:                        strcpy_P(loadedString, PROGMEM_STRINGS::FADER_DEFAULT); return loadedString;
            }
        }

        enum ChannelPressureMapping : unsigned char{
            METERING = 0,
        };
        inline const char* toString(ChannelPressureMapping n){
            switch (n) {
                case METERING:                  strcpy_P(loadedString, PROGMEM_STRINGS::METERING);          return loadedString;
                default:                        strcpy_P(loadedString, PROGMEM_STRINGS::METERING_DEFAULT);  return loadedString;
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

    const char* toString(Command n){
        switch (n) {
            case NoteOFF:              strcpy_P(loadedString, PROGMEM_STRINGS::NoteOFF); return loadedString; 
            case NoteON:               strcpy_P(loadedString, PROGMEM_STRINGS::NoteON); return loadedString; 
            case PolyphonicAftertouch: strcpy_P(loadedString, PROGMEM_STRINGS::PolyphonicAftertouch); return loadedString; 
            case ControlModeChange:    strcpy_P(loadedString, PROGMEM_STRINGS::ControlModeChange); return loadedString; 
            case ProgramChange:        strcpy_P(loadedString, PROGMEM_STRINGS::ProgramChange); return loadedString; 
            case ChannelAftertouch:    strcpy_P(loadedString, PROGMEM_STRINGS::ChannelAftertouch); return loadedString; 
            case PitchBendChange:      strcpy_P(loadedString, PROGMEM_STRINGS::PitchBendChange); return loadedString; 
            case SystemMessage:        strcpy_P(loadedString, PROGMEM_STRINGS::SystemMessage); return loadedString; 
            default:                    strcpy_P(loadedString, PROGMEM_STRINGS::COMMAND_DEFAULT); return loadedString; 

        }
    }

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
            case SystemExclusive:         strcpy_P(loadedString, PROGMEM_STRINGS::SystemExclusive);         return loadedString;
            case MIDITimeCodeQtrFrame:    strcpy_P(loadedString, PROGMEM_STRINGS::MIDITimeCodeQtrFrame);    return loadedString;
            case SongPositionPointer:     strcpy_P(loadedString, PROGMEM_STRINGS::SongPositionPointer);     return loadedString;
            case SongSelect:              strcpy_P(loadedString, PROGMEM_STRINGS::SongSelect);              return loadedString;
            case Undefined0:              strcpy_P(loadedString, PROGMEM_STRINGS::Undefined0);              return loadedString;
            case Undefined1:              strcpy_P(loadedString, PROGMEM_STRINGS::Undefined1);              return loadedString;
            case TuneRequest:             strcpy_P(loadedString, PROGMEM_STRINGS::TuneRequest);             return loadedString;
            case EndOfSysEx:              strcpy_P(loadedString, PROGMEM_STRINGS::EndOfSysEx);              return loadedString;
            case TimingClock:             strcpy_P(loadedString, PROGMEM_STRINGS::TimingClock);             return loadedString;
            case Undefined2:              strcpy_P(loadedString, PROGMEM_STRINGS::Undefined2);              return loadedString;
            case Start:                   strcpy_P(loadedString, PROGMEM_STRINGS::Start);                   return loadedString;
            case Continue:                strcpy_P(loadedString, PROGMEM_STRINGS::Continue);                return loadedString;
            case Stop:                    strcpy_P(loadedString, PROGMEM_STRINGS::Stop);                    return loadedString;
            case Undefined3:              strcpy_P(loadedString, PROGMEM_STRINGS::Undefined3);              return loadedString;
            case ActiveSensing:           strcpy_P(loadedString, PROGMEM_STRINGS::ActiveSensing);           return loadedString;
            case SystemReset:             strcpy_P(loadedString, PROGMEM_STRINGS::SystemReset);             return loadedString;
            default:                      strcpy_P(loadedString, PROGMEM_STRINGS::SYSMSG_DEFAULT);          return loadedString;;
        }
    }
}