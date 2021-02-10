#ifndef CFFFLASHHEADER_H
#define CFFFLASHHEADER_H

#include <QObject>
#include <QList>
#include <QFile>


/*
        public int CffHeaderSize;
        public long BaseAddress;

        public string FlashName;
        public string FlashGenerationParams;
        public int Unk3;
        public int Unk4;
        public string FileAuthor;
        public string FileCreationTime;
        public string AuthoringToolVersion;
        public string FTRAFOVersionString;
        public int FTRAFOVersionNumber;
        public string CFFVersionString;
        public int NumberOfFlashAreas;
        public int FlashDescriptionTable;
        public int DataBlockTableCountProbably;
        public int DataBlockRefTable;
        public int CTFHeaderTable;
        public int LanguageBlockLength;
        public int NumberOfECURefs;
        public int ECURefTable;
        public int UnkTableCount;
        public int UnkTableProbably;
        public int Unk15;

        public List<FlashDataBlock> DataBlocks = new List<FlashDataBlock>();
        public List<FlashDescriptionHeader> DescriptionHeaders = new List<FlashDescriptionHeader>();
 */

class CFFFlashDescriptionHeader;
class CFFFlashDataBlock;
class CFFFlashHeader : public QObject
{
    Q_OBJECT
public:
    static CFFFlashHeader * readFlashHeader(QFile * cff, QObject * parent = Q_NULLPTR);

private:
    explicit CFFFlashHeader(QObject *parent = nullptr);
    void readFlash();


private:
    QFile * m_cff_file;
    QList<CFFFlashDescriptionHeader *>  m_desc_headers;
    QList<CFFFlashDataBlock *>          m_flash_data_blocks;
};

#endif // CFFFLASHHEADER_H
