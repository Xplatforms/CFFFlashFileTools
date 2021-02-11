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

<<<<<<< HEAD
QString CFFUtils::ReadString(QFile * cff)
=======
QString CFFUtils::ReadStringFromBinaryReader(QFile * cff)
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
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

<<<<<<< HEAD
QString CFFUtils::ReadBitflagString(ulong & bitFlags, QFile * cff, long virtualBase)
=======
QString CFFUtils::ReadBitflagStringWithReader(ulong & bitFlags, QFile * cff, long virtualBase)
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
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

<<<<<<< HEAD
        auto result = CFFUtils::ReadString(cff);
=======
        auto result = CFFUtils::ReadStringFromBinaryReader(cff);
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
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
<<<<<<< HEAD


=======
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
