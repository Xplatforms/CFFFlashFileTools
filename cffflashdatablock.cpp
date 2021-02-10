#include "defs.h"
#include "cffflashdatablock.h"

CFFFlashDataBlock::CFFFlashDataBlock(QObject *parent) : QObject(parent)
{

}

CFFFlashDataBlock * CFFFlashDataBlock::readFlashDataBlock(QFile * cff, long baseAddress, QObject * parent)
{
    auto cff_flash_block = new CFFFlashDataBlock(parent);
    cff_flash_block->readCFFData(cff, baseAddress);
    return cff_flash_block;
}

void CFFFlashDataBlock::readCFFData(QFile * cff, long baseAddress)
{

}
