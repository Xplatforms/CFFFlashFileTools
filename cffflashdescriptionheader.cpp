#include "defs.h"
#include "cffflashdescriptionheader.h"


CFFFlashDescriptionHeader::CFFFlashDescriptionHeader(QObject *parent):QObject(parent)
{

}


CFFFlashDescriptionHeader * CFFFlashDescriptionHeader::readDescriptionHeader(QFile * cff, long baseAddress, QObject * parent)
{
    auto cff_descr_header = new CFFFlashDescriptionHeader(parent);
    cff_descr_header->readCFFData(cff, baseAddress);
    return cff_descr_header;
}

void CFFFlashDescriptionHeader::readCFFData(QFile * cff, long baseAddress)
{
    this->setBaseAddress(baseAddress);

    cff->seek(baseAddress);
    ulong flashBitFlags = 0;
    cff->read((char*)&flashBitFlags, 4);

    this->setQualifier(CFFUtils::ReadBitflagString(flashBitFlags, cff, baseAddress));
    int32_t Description = ReadBitflag4Byte(Description, flashBitFlags, cff);
    this->setDescription(Description);
    int32_t FlashAreaName = ReadBitflag4Byte(FlashAreaName, flashBitFlags, cff);
    this->setFlashAreaName(FlashAreaName);
    int32_t FlashTableStructureCount = ReadBitflag4Byte(FlashTableStructureCount, flashBitFlags, cff);
    this->setFlashTableStructureCount(FlashTableStructureCount);
    int32_t FlashTableStructureOffset = ReadBitflag4Byte(FlashTableStructureOffset, flashBitFlags, cff);
    this->setFlashTableStructureOffset(FlashTableStructureOffset);
    int32_t NumberOfUploads = ReadBitflag4Byte(NumberOfUploads, flashBitFlags, cff);
    this->setNumberOfUploads(NumberOfUploads);
    int32_t UploadTableRefTable = ReadBitflag4Byte(UploadTableRefTable, flashBitFlags, cff);
    this->setUploadTableRefTable(UploadTableRefTable);
    int32_t NumberOfIdentServices = ReadBitflag4Byte(NumberOfIdentServices, flashBitFlags, cff);
    this->setNumberOfIdentServices(NumberOfIdentServices);
    int32_t IdentServicesOffset = ReadBitflag4Byte(IdentServicesOffset, flashBitFlags, cff);
    this->setIdentServicesOffset(IdentServicesOffset);
    int32_t UniqueObjectID = ReadBitflag4Byte(UniqueObjectID, flashBitFlags, cff);
    this->setUniqueObjectID(UniqueObjectID);
    int32_t unkb = ReadBitflag4Byte(unkb, flashBitFlags, cff);
    this->setunkb(unkb);
    int32_t unkc = ReadBitflag4Byte(unkc, flashBitFlags, cff);
    this->setunkc(unkc);

    qDbg() << "BaseAddress: " << this->BaseAddress();
    qDbg() << "Qualifier: " << this->Qualifier();
    qDbg() << "FlashAreaName: " << this->FlashAreaName();
    qDbgVar(NumberOfUploads);
    qDbgVar(UniqueObjectID);
}
