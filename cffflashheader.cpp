#include "defs.h"
#include "cffflashheader.h"
#include "cffflashdescriptionheader.h"
#include "cffflashdatablock.h"



CFFFlashHeader::CFFFlashHeader(QObject *parent) : QObject(parent)
{

}


CFFFlashHeader * CFFFlashHeader::readFlashHeader(QFile * cff, QObject * parent)
{
    auto cff_header = new CFFFlashHeader(parent);
    cff_header->m_cff_file = cff;
    cff_header->readFlash();

    return cff_header;
}



void CFFFlashHeader::readFlash()
{
    this->m_cff_file->seek(0x410);
<<<<<<< HEAD
    this->m_CffHeaderSize  = 0;
    this->m_cff_file->read((char*)&this->m_CffHeaderSize, 4); emit CffHeaderSizeChanged();

    this->m_BaseAddress = this->m_cff_file->pos();
=======
    int32_t cffHeaderSize = 0;
    this->m_cff_file->read((char*)&cffHeaderSize, 4);

    auto BaseAddress = this->m_cff_file->pos();
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961

    ulong bitFlags = 0;
    this->m_cff_file->read((char*)&bitFlags, 4);

    ushort tmp = 0;
    this->m_cff_file->read((char*)&tmp, 2);

<<<<<<< HEAD
    auto FlashName = CFFUtils::ReadBitflagString(bitFlags, this->m_cff_file, this->m_BaseAddress);
    auto FlashGenerationParams = CFFUtils::ReadBitflagString(bitFlags, this->m_cff_file, this->m_BaseAddress);
=======
    auto FlashName = CFFUtils::ReadBitflagStringWithReader(bitFlags, this->m_cff_file, BaseAddress);
    auto FlashGenerationParams = CFFUtils::ReadBitflagStringWithReader(bitFlags, this->m_cff_file, BaseAddress);
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961

    int32_t Unk3 = ReadBitflag4Byte(Unk3, bitFlags, this->m_cff_file);
    int32_t Unk4 = ReadBitflag4Byte(Unk4, bitFlags, this->m_cff_file);

<<<<<<< HEAD
    auto FileAuthor = CFFUtils::ReadBitflagString(bitFlags, this->m_cff_file, this->m_BaseAddress);
    auto FileCreationTime = CFFUtils::ReadBitflagString(bitFlags, this->m_cff_file, this->m_BaseAddress);
    auto AuthoringToolVersion = CFFUtils::ReadBitflagString(bitFlags, this->m_cff_file, this->m_BaseAddress);
    auto FTRAFOVersionString = CFFUtils::ReadBitflagString(bitFlags, this->m_cff_file, this->m_BaseAddress);

    int32_t FTRAFOVersionNumber = ReadBitflag4Byte(FTRAFOVersionNumber, bitFlags, this->m_cff_file);;

    auto CFFVersionString = CFFUtils::ReadBitflagString(bitFlags, this->m_cff_file, this->m_BaseAddress);
=======
    auto FileAuthor = CFFUtils::ReadBitflagStringWithReader(bitFlags, this->m_cff_file, BaseAddress);
    auto FileCreationTime = CFFUtils::ReadBitflagStringWithReader(bitFlags, this->m_cff_file, BaseAddress);
    auto AuthoringToolVersion = CFFUtils::ReadBitflagStringWithReader(bitFlags, this->m_cff_file, BaseAddress);
    auto FTRAFOVersionString = CFFUtils::ReadBitflagStringWithReader(bitFlags, this->m_cff_file, BaseAddress);

    int32_t FTRAFOVersionNumber = ReadBitflag4Byte(FTRAFOVersionNumber, bitFlags, this->m_cff_file);;

    auto CFFVersionString = CFFUtils::ReadBitflagStringWithReader(bitFlags, this->m_cff_file, BaseAddress);
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961

    int32_t NumberOfFlashAreas = ReadBitflag4Byte(NumberOfFlashAreas, bitFlags, this->m_cff_file);
    int32_t FlashDescriptionTable = ReadBitflag4Byte(FlashDescriptionTable, bitFlags, this->m_cff_file);
    int32_t DataBlockTableCountProbably = ReadBitflag4Byte(DataBlockTableCountProbably, bitFlags, this->m_cff_file);
    int32_t DataBlockRefTable = ReadBitflag4Byte(DataBlockRefTable, bitFlags, this->m_cff_file);
<<<<<<< HEAD
    this->m_CTFHeaderTable = ReadBitflag4Byte(this->m_CTFHeaderTable, bitFlags, this->m_cff_file); emit CTFHeaderTableChanged();
=======
    int32_t CTFHeaderTable = ReadBitflag4Byte(CTFHeaderTable, bitFlags, this->m_cff_file);
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
    int32_t LanguageBlockLength = ReadBitflag4Byte(LanguageBlockLength, bitFlags, this->m_cff_file);
    int32_t NumberOfECURefs = ReadBitflag4Byte(NumberOfECURefs, bitFlags, this->m_cff_file);
    int32_t ECURefTable = ReadBitflag4Byte(ECURefTable, bitFlags, this->m_cff_file);
    int32_t UnkTableCount = ReadBitflag4Byte(UnkTableCount, bitFlags, this->m_cff_file);
    int32_t UnkTableProbably = ReadBitflag4Byte(UnkTableProbably, bitFlags, this->m_cff_file);

    int Unk15 = ReadBitflag1Byte(Unk15, bitFlags, this->m_cff_file);

    //this->m_desc_headers = new QList<CFFFlashDescriptionHeader *>();

    for (int flashDescIndex = 0; flashDescIndex < NumberOfFlashAreas; flashDescIndex++)
    {
<<<<<<< HEAD
        long flashTableEntryAddress = FlashDescriptionTable + this->m_BaseAddress + (flashDescIndex * 4);
=======
        long flashTableEntryAddress = FlashDescriptionTable + BaseAddress + (flashDescIndex * 4);
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
        this->m_cff_file->seek(flashTableEntryAddress);

        int32_t desc_pos = 0;
        this->m_cff_file->read((char*)&desc_pos, 4);
<<<<<<< HEAD
        long flashEntryBaseAddress = FlashDescriptionTable + this->m_BaseAddress + desc_pos;
=======
        long flashEntryBaseAddress = FlashDescriptionTable + BaseAddress + desc_pos;
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
        auto fdh = CFFFlashDescriptionHeader::readDescriptionHeader(this->m_cff_file, flashEntryBaseAddress, this);
        this->m_desc_headers.append(fdh);
    }


    for (int dataBlockIndex = 0; dataBlockIndex < DataBlockTableCountProbably; dataBlockIndex++)
    {
<<<<<<< HEAD
        long datablockEntryAddress = DataBlockRefTable + this->m_BaseAddress + (dataBlockIndex * 4);
=======
        long datablockEntryAddress = DataBlockRefTable + BaseAddress + (dataBlockIndex * 4);
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
        this->m_cff_file->seek(datablockEntryAddress);

        int32_t block_pos = 0;
        this->m_cff_file->read((char*)&block_pos, 4);
<<<<<<< HEAD
        long datablockBaseAddress = DataBlockRefTable + this->m_BaseAddress + block_pos;
=======
        long datablockBaseAddress = DataBlockRefTable + BaseAddress + block_pos;
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
        auto fdb = CFFFlashDataBlock::readFlashDataBlock(this->m_cff_file, datablockBaseAddress, this);
        this->m_flash_data_blocks.append(fdb);
    }


    qDbg() << "FlashName: " << FlashName;
    qDbg() << "FlashGenerationParams: " << FlashGenerationParams;
    qDbg() << "Unk3 " << Unk3 << "Unk4 " << Unk4;
    qDbg() << "FileAuthor: " << FileAuthor;
    qDbg() << "FileCreationTime: " << FileCreationTime;
    qDbg() << "AuthoringToolVersion: " << AuthoringToolVersion;
    qDbg() << "FTRAFOVersionString: " << FTRAFOVersionString;
    qDbg() << "FTRAFOVersionNumber: " << FTRAFOVersionNumber;
    qDbg() << "CFFVersionString: " << CFFVersionString;

    qDbgVar(NumberOfFlashAreas);
    qDbgVar(FlashDescriptionTable);
    qDbgVar(DataBlockTableCountProbably);
    qDbgVar(DataBlockRefTable);
<<<<<<< HEAD
    qDbgVar(this->CTFHeaderTable());
=======
    qDbgVar(CTFHeaderTable);
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
    qDbgVar(LanguageBlockLength);
    qDbgVar(NumberOfECURefs);
    qDbgVar(ECURefTable);
    qDbgVar(UnkTableCount);
    qDbgVar(UnkTableProbably);
    qDbgVar(Unk15);


}
