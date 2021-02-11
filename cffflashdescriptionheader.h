#ifndef CFFFLASHDESCRIPTIONHEADER_H
#define CFFFLASHDESCRIPTIONHEADER_H

#include <QObject>
#include <QFile>

class CFFFlashDescriptionHeader : public QObject
{
    Q_OBJECT

public:
    explicit CFFFlashDescriptionHeader(QObject *parent = nullptr);
    static CFFFlashDescriptionHeader * readDescriptionHeader(QFile * cff, long baseAddress, QObject * parent = Q_NULLPTR);

    Q_PROPERTY(QString Qualifier READ Qualifier WRITE setQualifier NOTIFY QualifierChanged);
    Q_PROPERTY(int32_t Description READ Description WRITE setDescription NOTIFY DescriptionChanged);
    Q_PROPERTY(int32_t FlashAreaName READ FlashAreaName WRITE setFlashAreaName NOTIFY FlashAreaNameChanged);
    Q_PROPERTY(int32_t FlashTableStructureCount READ FlashTableStructureCount WRITE setFlashTableStructureCount NOTIFY FlashTableStructureCountChanged);
    Q_PROPERTY(int32_t FlashTableStructureOffset READ FlashTableStructureOffset WRITE setFlashTableStructureOffset NOTIFY FlashTableStructureOffsetChanged);
    Q_PROPERTY(int32_t NumberOfUploads READ NumberOfUploads WRITE setNumberOfUploads NOTIFY NumberOfUploadsChanged);
    Q_PROPERTY(int32_t UploadTableRefTable READ UploadTableRefTable WRITE setUploadTableRefTable NOTIFY UploadTableRefTableChanged);
    Q_PROPERTY(int32_t NumberOfIdentServices READ NumberOfIdentServices WRITE setNumberOfIdentServices NOTIFY NumberOfIdentServicesChanged);
    Q_PROPERTY(int32_t IdentServicesOffset READ IdentServicesOffset WRITE setIdentServicesOffset NOTIFY IdentServicesOffsetChanged);
    Q_PROPERTY(int32_t UniqueObjectID READ UniqueObjectID WRITE setUniqueObjectID NOTIFY UniqueObjectIDChanged);
    Q_PROPERTY(int32_t unkb READ unkb WRITE setunkb NOTIFY unkbChanged);
    Q_PROPERTY(int32_t unkc READ unkc WRITE setunkc NOTIFY unkcChanged);
    Q_PROPERTY(long BaseAddress READ BaseAddress WRITE setBaseAddress NOTIFY BaseAddressChanged);

    QString Qualifier(){return this->m_Qualifier;}
    int32_t Description(){return this->m_Description;}
    int32_t FlashAreaName(){return this->m_FlashAreaName;}
    int32_t FlashTableStructureCount(){return this->m_FlashTableStructureCount;}
    int32_t FlashTableStructureOffset(){return this->m_FlashTableStructureOffset;}
    int32_t NumberOfUploads(){return this->m_NumberOfUploads;}
    int32_t UploadTableRefTable(){return this->m_UploadTableRefTable;}
    int32_t NumberOfIdentServices(){return this->m_NumberOfIdentServices;}
    int32_t IdentServicesOffset(){return this->m_IdentServicesOffset;}
    int32_t UniqueObjectID(){return this->m_UniqueObjectID;}
    int32_t unkb(){return this->m_unkb;}
    int32_t unkc(){return this->m_unkc;}
    long    BaseAddress(){return this->m_BaseAddress;}

    void setQualifier(QString data){this->m_Qualifier = data; emit QualifierChanged();}
    void setDescription(int32_t data){this->m_Description = data; emit DescriptionChanged();}
    void setFlashAreaName(int32_t data){this->m_FlashAreaName = data; emit FlashAreaNameChanged();}
    void setFlashTableStructureCount(int32_t data){this->m_FlashTableStructureCount = data; emit FlashTableStructureCountChanged();}
    void setFlashTableStructureOffset(int32_t data){this->m_FlashTableStructureOffset = data; emit FlashTableStructureOffsetChanged();}
    void setNumberOfUploads(int32_t data){this->m_NumberOfUploads = data; emit NumberOfUploadsChanged();}
    void setUploadTableRefTable(int32_t data){this->m_UploadTableRefTable = data; emit UploadTableRefTableChanged();}
    void setNumberOfIdentServices(int32_t data){this->m_NumberOfIdentServices = data; emit NumberOfIdentServicesChanged();}
    void setIdentServicesOffset(int32_t data){this->m_IdentServicesOffset = data; emit IdentServicesOffsetChanged();}
    void setUniqueObjectID(int32_t data){this->m_UniqueObjectID = data; emit UniqueObjectIDChanged();}
    void setunkb(int32_t data){this->m_unkb = data; emit unkbChanged();}
    void setunkc(int32_t data){this->m_unkc = data; emit unkcChanged();}
    void setBaseAddress(long data){this->m_BaseAddress = data; emit BaseAddressChanged();}

signals:
    void QualifierChanged();
    void DescriptionChanged();
    void FlashAreaNameChanged();
    void FlashTableStructureCountChanged();
    void FlashTableStructureOffsetChanged();
    void NumberOfUploadsChanged();
    void UploadTableRefTableChanged();
    void NumberOfIdentServicesChanged();
    void IdentServicesOffsetChanged();
    void UniqueObjectIDChanged();
    void unkbChanged();
    void unkcChanged();
    void BaseAddressChanged();

private:
    void readCFFData(QFile * cff, long baseAddress);

private:
    QString m_Qualifier;
    int32_t m_Description;
    int32_t m_FlashAreaName;
    int32_t m_FlashTableStructureCount;
    int32_t m_FlashTableStructureOffset;
    int32_t m_NumberOfUploads;
    int32_t m_UploadTableRefTable;
    int32_t m_NumberOfIdentServices;
    int32_t m_IdentServicesOffset;
    int32_t m_UniqueObjectID;
    int32_t m_unkb;
    int32_t m_unkc;
    long    m_BaseAddress;


};

#endif // CFFFLASHDESCRIPTIONHEADER_H
