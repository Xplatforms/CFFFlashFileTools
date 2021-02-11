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
        public int ;
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

    Q_PROPERTY(int32_t CTFHeaderTable READ CTFHeaderTable NOTIFY CTFHeaderTableChanged);
    Q_PROPERTY(int32_t CffHeaderSize READ CffHeaderSize NOTIFY CffHeaderSizeChanged);
    Q_PROPERTY(long BaseAddress READ BaseAddress);

    int32_t CTFHeaderTable(){return this->m_CTFHeaderTable;}
    int32_t CffHeaderSize(){return this->m_CffHeaderSize;}
    long BaseAddress(){return this->m_BaseAddress;}

private:
    explicit CFFFlashHeader(QObject *parent = nullptr);
    void readFlash();

signals:
    void CTFHeaderTableChanged();
    void CffHeaderSizeChanged();

private:
    QFile * m_cff_file;

    int32_t m_CTFHeaderTable;
    int32_t m_CffHeaderSize;
    long m_BaseAddress;

    QList<CFFFlashDescriptionHeader *>  m_desc_headers;
    QList<CFFFlashDataBlock *>          m_flash_data_blocks;
};

#endif // CFFFLASHHEADER_H
