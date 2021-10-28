#ifndef CFFFLASHSEGMENT_H
#define CFFFLASHSEGMENT_H

#include <QObject>
#include <QFile>


class CFFFlashSegment : public QObject
{
    Q_OBJECT
public:
    explicit CFFFlashSegment(QObject *parent = nullptr);
    static CFFFlashSegment * readFlashSegment(QFile * cff, long baseAddress, long flash_offset, QObject * parent = Q_NULLPTR);

    Q_PROPERTY(QString SegmentName READ SegmentName WRITE setSegmentName NOTIFY SegmentNameChanged);
    Q_PROPERTY(uint32_t FromAdress READ FromAdress WRITE setFromAdress NOTIFY FromAdressChanged);
    Q_PROPERTY(uint32_t SegmentLength READ SegmentLength WRITE setSegmentLength NOTIFY SegmentLengthChanged);
    Q_PROPERTY(uint32_t Unk3 READ Unk3 WRITE setUnk3 NOTIFY Unk3Changed);
    Q_PROPERTY(uint32_t Unk5 READ Unk5 WRITE setUnk5 NOTIFY Unk5Changed);
    Q_PROPERTY(uint32_t Unk6 READ Unk6 WRITE setUnk6 NOTIFY Unk6Changed);
    Q_PROPERTY(uint32_t Unk7 READ Unk7 WRITE setUnk7 NOTIFY Unk7Changed);
    Q_PROPERTY(long BaseAddress READ BaseAddress WRITE setBaseAddress NOTIFY BaseAddressChanged);

    Q_INVOKABLE QByteArray readFlashSegment();    
    Q_INVOKABLE void saveToFile(QString fpath);

    QString SegmentName(){return this->m_SegmentName;}
    uint32_t FromAdress(){return this->m_FromAdress;}
    uint32_t SegmentLength(){return this->m_SegmentLength;}
    uint32_t Unk3(){return this->m_Unk3;}
    uint32_t Unk5(){return this->m_Unk5;}
    uint32_t Unk6(){return this->m_Unk6;}
    uint32_t Unk7(){return this->m_Unk7;}
    long    BaseAddress(){return this->m_BaseAddress;}

    void setSegmentName(QString data){this->m_SegmentName = data; emit SegmentNameChanged();}
    void setFromAdress(uint32_t data){this->m_FromAdress= data; emit FromAdressChanged();}
    void setSegmentLength(uint32_t data){this->m_SegmentLength= data; emit SegmentLengthChanged();}
    void setUnk3(uint32_t data){this->m_Unk3= data; emit Unk3Changed();}
    void setUnk5(uint32_t data){this->m_Unk5= data; emit Unk5Changed();}
    void setUnk6(uint32_t data){this->m_Unk6= data; emit Unk6Changed();}
    void setUnk7(uint32_t data){this->m_Unk7= data; emit Unk7Changed();}
    void setBaseAddress(long data){this->m_BaseAddress = data; emit BaseAddressChanged();}

private:
    void readCFFData();

signals:
    void SegmentNameChanged();
    void FromAdressChanged();
    void SegmentLengthChanged();
    void Unk3Changed();
    void Unk5Changed();
    void Unk6Changed();
    void Unk7Changed();
    void BaseAddressChanged();

private:
    long    m_flash_offset;
    QFile * p_cff_file;

    QString m_SegmentName;
    uint32_t m_FromAdress;
    uint32_t m_SegmentLength;
    uint32_t m_Unk3;
    uint32_t m_Unk5;
    uint32_t m_Unk6;
    uint32_t m_Unk7;
    long    m_BaseAddress;
};

#endif // CFFFLASHSEGMENT_H
