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

    CableByte(unsigned char _cableByte = 0);

    CableByte(CodeIndex _codeIndex, unsigned char _cableNumber = 0);

    unsigned char getCableNumber() const;

    CodeIndex getCodeIndex() const;

    void setCable(unsigned char _cable);

    void setCodeIndex(CodeIndex _codeIndex);

private:
    unsigned char getCable() const;
}; 