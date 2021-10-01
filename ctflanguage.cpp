#include "defs.h"
#include "ctflanguage.h"

CTFLanguage::CTFLanguage(QObject *parent) : QObject(parent)
{

}

CTFLanguage * CTFLanguage::readCTFLanguage(QFile * cff, long baseAddress,  int32_t headerSize, QObject * parent)
{
    auto data = new CTFLanguage(parent);
    data->readCFFData(cff, baseAddress, headerSize);
    return data;
}

void CTFLanguage::readCFFData(QFile * cff, long baseAddress, int32_t headerSize)
{
    this->m_BaseAddress = baseAddress;
    cff->seek(this->m_BaseAddress);

    ushort tmp = 0;
    cff->read((char*)&tmp, 2);
    ulong languageEntryBitflags = tmp;

    this->setQualifier(CFFUtils::ReadBitflagString(languageEntryBitflags, cff, baseAddress));

    ushort LanguageIndex = ReadBitflag2Byte(LanguageIndex, languageEntryBitflags, cff);
    this->setLanguageIndex(LanguageIndex);

    this->m_StringPoolSize = ReadBitflag4Byte(this->m_StringPoolSize, languageEntryBitflags, cff);
    this->m_MaybeOffsetFromStringPoolBase = ReadBitflag4Byte(this->m_MaybeOffsetFromStringPoolBase, languageEntryBitflags, cff);
    this->m_StringCount = ReadBitflag4Byte(this->m_StringCount, languageEntryBitflags, cff);

    this->loadStrings(cff, headerSize);
}

void CTFLanguage::loadStrings(QFile * cff, int32_t headerSize)
{
    QStringList StringEntries;
    int caesarStringTableOffset = headerSize + 0x410 + 4; // header.CffHeaderSize; strange that this has to be manually computed
    for (int i = 0; i < this->m_StringCount; i++)
    {
        cff->seek(caesarStringTableOffset + (i * 4));
        int32_t stringOffset = 0;
        cff->read((char*)&stringOffset, 4);

        cff->seek(caesarStringTableOffset + stringOffset);
        auto result = CFFUtils::ReadString(cff);
        qDbg() << "String loaded: " << result;
        StringEntries.append(result);
    }
    this->setStringEntries(StringEntries);
}
