#include "defs.h"
#include "ctfheader.h"

CTFHeader::CTFHeader(QObject *parent) : QObject(parent)
{

}

CTFHeader * CTFHeader::readCTFHeader(QFile * cff, long baseAddress, int32_t headerSize,  QObject * parent)
{
    auto data = new CTFHeader(parent);
    data->readCFFData(cff, baseAddress, headerSize);
    return data;
}

void CTFHeader::readCFFData(QFile * cff, long baseAddress, int32_t headerSize)
{
    this->m_BaseAddress = baseAddress;
    cff->seek(this->m_BaseAddress);

    ushort tmp = 0;
    cff->read((char*)&tmp, 2);
    ulong ctfBitflags = tmp;

    int32_t CtfUnk1 = ReadBitflag4Byte(CtfUnk1, ctfBitflags, cff);
    this->setCtfUnk1(CtfUnk1);

    this->setQualifier(CFFUtils::ReadBitflagString(ctfBitflags, cff, baseAddress));

    ushort CtfUnk3 = ReadBitflag2Byte(CtfUnk3, ctfBitflags, cff);
    this->setCtfUnk3(CtfUnk3);

    int32_t CtfUnk4 = ReadBitflag4Byte(CtfUnk4, ctfBitflags, cff);
    this->setCtfUnk4(CtfUnk4);

    qDbg() << "Qualifier" << this->Qualifier();

    this->m_CtfLanguageCount = ReadBitflag4Byte(this->m_CtfLanguageCount, ctfBitflags, cff);
    this->m_CtfLanguageTableOffset = ReadBitflag4Byte(this->m_CtfLanguageTableOffset, ctfBitflags, cff);
    this->setCtfUnkString(CFFUtils::ReadBitflagString(ctfBitflags, cff, baseAddress));

    qDbg() << " Lang count: " << this->m_CtfLanguageCount;
    qDbg() << "CtfUnkString "  << this->CtfUnkString();

    long ctfLanguageTableOffsetRelativeToDefintions = this->m_CtfLanguageTableOffset + this->m_BaseAddress;

    // parse every language record
    auto CtfLanguages = QList<CTFLanguage *>();
    for (int languageEntry = 0; languageEntry < this->m_CtfLanguageCount; languageEntry++)
    {
        long languageTableEntryOffset = ctfLanguageTableOffsetRelativeToDefintions + (languageEntry * 4);

        cff->seek(languageTableEntryOffset);

        int32_t pos = 0;
        cff->read((char*)&pos, 4);

        long realLanguageEntryAddress = pos + ctfLanguageTableOffsetRelativeToDefintions;
        auto language = CTFLanguage::readCTFLanguage(cff, realLanguageEntryAddress, headerSize);
        CtfLanguages.append(language);
    }
    this->setCtfLanguages(CtfLanguages);
}
