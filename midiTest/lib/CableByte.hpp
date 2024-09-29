#include "Enums.hpp"

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