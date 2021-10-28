#include "defs.h"
#include "cffflashsegment.h"


CFFFlashSegment::CFFFlashSegment(QObject *parent) : QObject(parent)
{

}


CFFFlashSegment * CFFFlashSegment::readFlashSegment(QFile * cff, long baseAddress, long flash_offset, QObject * parent)
{
    auto cff_flash_segment = new CFFFlashSegment(parent);
    cff_flash_segment->p_cff_file = cff;
    cff_flash_segment->m_BaseAddress = baseAddress;
    cff_flash_segment->m_flash_offset = flash_offset;
    cff_flash_segment->readCFFData();
    return cff_flash_segment;
}


void CFFFlashSegment::readCFFData()
{
    this->p_cff_file->seek(this->BaseAddress());

    ushort tmp = 0;
    this->p_cff_file->read((char*)&tmp, 2);
    ulong bitFlags = tmp;

    uint32_t FromAddress = ReadBitflag4Byte(FromAddress, bitFlags, this->p_cff_file);
    qDbg() << "FromAddr uint " << QString::number(FromAddress, 16) << sizeof(uint32_t);
    this->setFromAdress(FromAddress);
    uint32_t SegmentLength = ReadBitflag4Byte(SegmentLength, bitFlags, this->p_cff_file);
    this->setSegmentLength(SegmentLength);
    uint32_t Unk3 = ReadBitflag4Byte(Unk3, bitFlags, this->p_cff_file);
    this->setUnk3(Unk3);

    this->setSegmentName(CFFUtils::ReadBitflagString(bitFlags, this->p_cff_file, this->BaseAddress()));

    uint32_t Unk5 = ReadBitflag4Byte(Unk5, bitFlags, this->p_cff_file);
    this->setUnk5(Unk5);
    uint32_t Unk6 = ReadBitflag4Byte(Unk6, bitFlags, this->p_cff_file);
    this->setUnk6(Unk6);
    uint32_t Unk7 = ReadBitflag4Byte(Unk7, bitFlags, this->p_cff_file);
    this->setUnk7(Unk7);

    qDbg() << "SegmentName " << this->SegmentName();
    qDbg() << "SegmentLength " << this->SegmentLength();
    qDbg() << "FromAddress " << this->FromAdress() << QString::number(this->FromAdress(), 16);

    qDbg() << "Unks " << Unk3 << Unk5 << Unk6 << Unk7;
}


QByteArray CFFFlashSegment::readFlashSegment()
{
    QByteArray data;
    if(this->FromAdress() <= 0 && this->SegmentLength() <= 0)
    {
        qDbg() << "FlashSegment not read or no flashsegment data";
        return data;
    }

    this->p_cff_file->seek(this->m_flash_offset);

    char * buff = new char[this->SegmentLength()];
    auto rlen = this->p_cff_file->read(buff, this->SegmentLength());
    if(rlen != this->SegmentLength())
    {
        qDbg() << "Warning: Segment data not complete!";
    }
    data = QByteArray::fromRawData(buff, this->SegmentLength());

    return data;
}

void CFFFlashSegment::saveToFile(QString fpath)
{
    QFile seg_file(fpath);
    if(seg_file.open(QIODevice::WriteOnly))
    {
        seg_file.write(this->readFlashSegment());
        seg_file.close();
    }
}
