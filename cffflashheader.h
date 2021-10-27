#ifndef CFFFLASHHEADER_H
#define CFFFLASHHEADER_H

#include <QObject>
#include <QList>
#include <QFile>

#include "cffflashdatablock.h"
#include "cffflashdescriptionheader.h"
#include "cffflashdatablocksmodel.h"

//class CFFFlashDataBlocksModel;
//class CFFFlashDescriptionHeader;
//class CFFFlashDataBlock;
class CFFFlashHeader : public QObject
{
    Q_OBJECT
public:
    explicit CFFFlashHeader(QObject *parent = nullptr);
    Q_INVOKABLE static CFFFlashHeader * readFlashHeader(QFile * cff, QObject * parent = Q_NULLPTR);

    Q_PROPERTY(QString FlashName READ FlashName WRITE setFlashName NOTIFY FlashNameChanged);
    Q_PROPERTY(QString FileAuthor READ FileAuthor WRITE setFileAuthor NOTIFY FileAuthorChanged);

    Q_PROPERTY(int32_t CTFHeaderTable READ CTFHeaderTable NOTIFY CTFHeaderTableChanged);
    Q_PROPERTY(int32_t CffHeaderSize READ CffHeaderSize NOTIFY CffHeaderSizeChanged);
    Q_PROPERTY(QList<CFFFlashDescriptionHeader *> FlashDescriptionHeaders READ FlashDescriptionHeaders NOTIFY FlashDescriptionHeadersChanged);
    Q_PROPERTY(QList<CFFFlashDataBlock *> FlashDataBlocks READ FlashDataBlocks NOTIFY FlashDataBlocksChanged);
    Q_PROPERTY(long BaseAddress READ BaseAddress NOTIFY BaseAddressChanged);

    Q_INVOKABLE void updateModel(CFFFlashDataBlocksModel *);

    int32_t CTFHeaderTable(){return this->m_CTFHeaderTable;}
    int32_t CffHeaderSize(){return this->m_CffHeaderSize;}
    QList<CFFFlashDescriptionHeader *> FlashDescriptionHeaders(){return this->m_desc_headers;}
    QList<CFFFlashDataBlock *> FlashDataBlocks(){return this->m_flash_data_blocks;}
    long BaseAddress(){return this->m_BaseAddress;}
    QString FlashName(){return this->m_FlashName;}
    QString FileAuthor(){return this->m_FileAuthor;}

    void setFlashName(QString data){this->m_FlashName = data;}
    void setFileAuthor(QString data){this->m_FileAuthor = data;}


private:
    void readFlash();


signals:
    void CTFHeaderTableChanged();
    void CffHeaderSizeChanged();
    void FlashDescriptionHeadersChanged();
    void FlashDataBlocksChanged();
    void BaseAddressChanged();
    void FileAuthorChanged();
    void FlashNameChanged();

private:
    QFile * m_cff_file;

    QString m_FlashName;
    QString m_FileAuthor;
    QString m_FlashGenerationParams;
    QString m_FileCreationTime;
    QString m_AuthoringToolVersion;
    QString m_FTRAFOVersionString;
    int32_t m_FTRAFOVersionNumber;
    QString m_CFFVersionString;


    int32_t m_CTFHeaderTable;
    int32_t m_CffHeaderSize;
    long m_BaseAddress;

    QList<CFFFlashDescriptionHeader *>  m_desc_headers;
    QList<CFFFlashDataBlock *>          m_flash_data_blocks;
};

#endif // CFFFLASHHEADER_H
