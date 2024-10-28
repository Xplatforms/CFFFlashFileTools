#include "defs.h"
#include "cffflashdatablock.h"
#include <QUrl>

CFFFlashDataBlock::CFFFlashDataBlock(QObject *parent) : QObject(parent)
{

}

CFFFlashDataBlock * CFFFlashDataBlock::readFlashDataBlock(QFile * cff, long baseAddress, uint32_t CffHeaderSize, uint32_t LanguageBlockLength, QObject * parent)
{
    auto cff_flash_block = new CFFFlashDataBlock(parent);
    cff_flash_block->m_CffHeaderSize = CffHeaderSize;
    cff_flash_block->m_LanguageBlockLength = LanguageBlockLength;
    cff_flash_block->readCFFData(cff, baseAddress);
    return cff_flash_block;
}

void CFFFlashDataBlock::readCFFData(QFile * cff, long baseAddress)
{
    this->setBaseAddress(baseAddress);
    cff->seek(baseAddress);

    ulong bitFlags = 0;
    cff->read((char*)&bitFlags, 4);

    ushort tmp = 0;
    cff->read((char*)&tmp, 2);

    this->setQualifier(CFFUtils::ReadBitflagString(bitFlags, cff, baseAddress));

    int32_t LongName = ReadBitflag4Byte(LongName, bitFlags, cff);
    this->setLongName(LongName);
    int32_t Description = ReadBitflag4Byte(Description, bitFlags, cff);
    this->setDescription(Description);
    int32_t FlashData = ReadBitflag4Byte(FlashData, bitFlags, cff);
    this->setFlashData(FlashData);


    int32_t BlockLength = ReadBitflag4Byte(BlockLength, bitFlags, cff);
    this->setBlockLength(BlockLength);
    int32_t DataFormat = ReadBitflag4Byte(DataFormat, bitFlags, cff);
    this->setDataFormat(DataFormat);

    int32_t FileName = ReadBitflag4Byte(FileName, bitFlags, cff);
    this->setFileName(FileName);

    int32_t NumberOfFilters = ReadBitflag4Byte(NumberOfFilters, bitFlags, cff);
    this->setNumberOfFilters(NumberOfFilters);


    int32_t FiltersOffset = ReadBitflag4Byte(FiltersOffset, bitFlags, cff);
    this->setFiltersOffset(FiltersOffset);
    int32_t NumberOfSegments = ReadBitflag4Byte(NumberOfSegments, bitFlags, cff);
    this->setNumberOfSegments(NumberOfSegments);
    int32_t SegmentOffset = ReadBitflag4Byte(SegmentOffset, bitFlags, cff);
    this->setSegmentOffset(SegmentOffset);
    int32_t EncryptionMode = ReadBitflag4Byte(EncryptionMode, bitFlags, cff);
    this->setEncryptionMode(EncryptionMode);

    int32_t KeyLength = ReadBitflag4Byte(KeyLength, bitFlags, cff);
    this->setKeyLength(KeyLength);
    int32_t KeyBuffer = ReadBitflag4Byte(KeyBuffer, bitFlags, cff);
    this->setKeyBuffer(KeyBuffer);
    int32_t NumberOfOwnIdents = ReadBitflag4Byte(NumberOfOwnIdents, bitFlags, cff);
    this->setNumberOfOwnIdents(NumberOfOwnIdents);
    int32_t IdentsOffset = ReadBitflag4Byte(IdentsOffset, bitFlags, cff);
    this->setIdentsOffset(IdentsOffset);

    int32_t NumberOfSecurities = ReadBitflag4Byte(NumberOfSecurities, bitFlags, cff);
    this->setNumberOfSecurities(NumberOfSecurities);
    int32_t SecuritiesOffset = ReadBitflag4Byte(SecuritiesOffset, bitFlags, cff);
    this->setSecuritiesOffset(SecuritiesOffset);
    this->setDataBlockType(CFFUtils::ReadBitflagString(bitFlags, cff, baseAddress));
    int32_t UniqueObjectId = ReadBitflag4Byte(UniqueObjectId, bitFlags, cff);
    this->setUniqueObjectId(UniqueObjectId);

    this->setFlashDataInfo_Idk(CFFUtils::ReadBitflagString(bitFlags, cff, baseAddress));
    int32_t FlashDataInfoLang1 = ReadBitflag4Byte(FlashDataInfoLang1, bitFlags, cff);
    this->setFlashDataInfoLang1(FlashDataInfoLang1);
    int32_t FlashDataInfoLang2 = ReadBitflag4Byte(FlashDataInfoLang2, bitFlags, cff);
    this->setFlashDataInfoLang2(FlashDataInfoLang2);
    int32_t FlashDataInfo_Idk2 = ReadBitflag4Byte(FlashDataInfo_Idk2, bitFlags, cff);
    this->setFlashDataInfo_Idk2(FlashDataInfo_Idk2);


    long fileCursor = 0;
    // CtfUnk1 = CaesarReader.ReadBitflagInt32(ref ctfBitflags, reader);
    auto FlashSegments = QList<CFFFlashSegment *>();
    for (int segmentIndex = 0; segmentIndex < NumberOfSegments; segmentIndex++)
    {
        long segmentEntryAddress = SegmentOffset + baseAddress + (segmentIndex * 4);
        cff->seek(segmentEntryAddress);

        int32_t pos = 0;
        cff->read((char*)&pos, 4);
        long segmentBaseAddress = SegmentOffset + baseAddress + pos;

        long offset = this->FlashData() + this->m_CffHeaderSize + this->m_LanguageBlockLength + fileCursor + 0x414;
        auto segment = CFFFlashSegment::readFlashSegment(cff,segmentBaseAddress, offset, this);

        fileCursor += segment->SegmentLength();

        FlashSegments.append(segment);
    }
    this->setFlashSegments(FlashSegments);

    qDbg() << "Qualifier" <<  this->Qualifier();
    qDbg() << "FlashDataInfo_Idk" <<  this->FlashDataInfo_Idk();
    qDbg() << "BlockLength " << this->BlockLength();
    qDbg() << "FlashData " << this->FlashData();
    qDbg() << "FileName " << this->FileName();
    qDbg() << "LongName " << this->LongName();

}

void CFFFlashDataBlock::updateModel(CFFFlashSegmentModel * model)
{
    qDbg() << "update blocks model!";
    model->addFlashSegments(this->m_FlashSegments);
}

QString CFFFlashDataBlock::exportSegments(QString fpath, QString prefix)
{
    if(fpath.startsWith(QStringLiteral("file:")))
    {
        fpath = QDir::toNativeSeparators(QUrl(fpath).toLocalFile());
    }
    else fpath = QDir::toNativeSeparators(fpath);

    if(!fpath.endsWith(QDir::separator()))
    {
        fpath.append(QDir::separator());
    }

    foreach(auto segment, this->FlashSegments())
    {
        qDbg() << "Segment: " << fpath+prefix+"_"+this->FlashDataInfo_Idk()+QLatin1String("_")+segment->SegmentName()+".segment";
        QFile seg_file(fpath+prefix+"_"+this->FlashDataInfo_Idk()+QLatin1String("_")+segment->SegmentName()+".segment");
        if(seg_file.open(QIODevice::WriteOnly))
        {
            seg_file.write(segment->readFlashSegment());
            seg_file.close();
        }
    }

    return fpath;
}
