#ifndef CFFFLASHHEADER_H
#define CFFFLASHHEADER_H

#include <QObject>
#include <QList>
#include <QFile>


class CFFFlashDescriptionHeader;
class CFFFlashDataBlock;
class CFFFlashHeader : public QObject
{
    Q_OBJECT
public:
    static CFFFlashHeader * readFlashHeader(QFile * cff, QObject * parent = Q_NULLPTR);


    Q_PROPERTY(int32_t CTFHeaderTable READ CTFHeaderTable NOTIFY CTFHeaderTableChanged);
    Q_PROPERTY(int32_t CffHeaderSize READ CffHeaderSize NOTIFY CffHeaderSizeChanged);
    Q_PROPERTY(QList<CFFFlashDescriptionHeader *> FlashDescriptionHeaders READ FlashDescriptionHeaders NOTIFY FlashDescriptionHeadersChanged);
    Q_PROPERTY(QList<CFFFlashDataBlock *> FlashDataBlocks READ FlashDataBlocks NOTIFY FlashDataBlocksChanged);
    Q_PROPERTY(long BaseAddress READ BaseAddress NOTIFY BaseAddressChanged);

    int32_t CTFHeaderTable(){return this->m_CTFHeaderTable;}
    int32_t CffHeaderSize(){return this->m_CffHeaderSize;}
    QList<CFFFlashDescriptionHeader *> FlashDescriptionHeaders(){return this->m_desc_headers;}
    QList<CFFFlashDataBlock *> FlashDataBlocks(){return this->m_flash_data_blocks;}
    long BaseAddress(){return this->m_BaseAddress;}


private:
    explicit CFFFlashHeader(QObject *parent = nullptr);
    void readFlash();


signals:
    void CTFHeaderTableChanged();
    void CffHeaderSizeChanged();
    void FlashDescriptionHeadersChanged();
    void FlashDataBlocksChanged();
    void BaseAddressChanged();

private:
    QFile * m_cff_file;

    int32_t m_CTFHeaderTable;
    int32_t m_CffHeaderSize;
    long m_BaseAddress;

    QList<CFFFlashDescriptionHeader *>  m_desc_headers;
    QList<CFFFlashDataBlock *>          m_flash_data_blocks;
};

#endif // CFFFLASHHEADER_H
