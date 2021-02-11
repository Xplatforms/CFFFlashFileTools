#include "defs.h"
#include "cffflashsegment.h"


CFFFlashSegment::CFFFlashSegment(QObject *parent) : QObject(parent)
{

}


CFFFlashSegment * CFFFlashSegment::readFlashSegment(QFile * cff, long baseAddress, QObject * parent)
{
    auto cff_flash_segment = new CFFFlashSegment(parent);
    cff_flash_segment->readCFFData(cff, baseAddress);
    return cff_flash_segment;
}


void CFFFlashSegment::readCFFData(QFile * cff, long baseAddress)
{
    this->setBaseAddress(baseAddress);
    cff->seek(baseAddress);

    ushort tmp = 0;
    cff->read((char*)&tmp, 2);
    ulong bitFlags = tmp;

    // start reading

    int32_t FromAddress = ReadBitflag4Byte(FromAddress, bitFlags, cff);
    this->setFromAdress(FromAddress);
    int32_t SegmentLength = ReadBitflag4Byte(SegmentLength, bitFlags, cff);
    this->setSegmentLength(SegmentLength);
    int32_t Unk3 = ReadBitflag4Byte(Unk3, bitFlags, cff);
    this->setUnk3(Unk3);

    this->setSegmentName(CFFUtils::ReadBitflagString(bitFlags, cff, this->BaseAddress()));

    int32_t Unk5 = ReadBitflag4Byte(Unk5, bitFlags, cff);
    this->setUnk5(Unk5);
    int32_t Unk6 = ReadBitflag4Byte(Unk6, bitFlags, cff);
    this->setUnk6(Unk6);
    int32_t Unk7 = ReadBitflag4Byte(Unk7, bitFlags, cff);
    this->setUnk7(Unk7);

    qDbg() << "SegmentName " << this->SegmentName();
    qDbg() << "SegmentLength " << this->SegmentLength();
    qDbg() << "FromAddress " << this->FromAdress();

    qDbg() << "Unks " << Unk3 << Unk5 << Unk6 << Unk7;
}
