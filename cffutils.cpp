#include "defs.h"

CFFUtils::CFFUtils(QObject *parent) : QObject(parent)
{

}


bool CFFUtils::CheckAndAdvanceBitflag(ulong & bitFlag)
{
    bool flagIsSet = (bitFlag & 1) > 0;
    bitFlag >>= 1;
    return flagIsSet;
}

QString CFFUtils::ReadString(QFile * cff)
{
    // read out a string, stopping at the first null terminator
    QByteArray writer;

    while (true)
    {
        char nextByte = 0;
        cff->read(&nextByte, 1);
        if (nextByte == 0)
        {
            auto stringRaw = QString(writer);
            return stringRaw;
        }
        else
        {
            writer.append(nextByte);
        }
    }

    return QString(writer);
}

QString CFFUtils::ReadBitflagString(ulong & bitFlags, QFile * cff, long virtualBase)
{
    if (CheckAndAdvanceBitflag(bitFlags))
    {
        // read the string's offset relative to our current block
        int stringOffset = 0;
        cff->read((char*)&stringOffset, sizeof(int32_t)); //sizeof = 4
        // save our reading cursor
        long readerPosition = cff->pos();
        // seek to the specified offset, then read out the string
        cff->seek(stringOffset + virtualBase);

        auto result = CFFUtils::ReadString(cff);
        // restore our reading cursor
        cff->seek(readerPosition);
        return result;
    }
    else
    {
        // Console.WriteLine("Bitflag was off for string");
        return "(flag disabled)";
    }
}


