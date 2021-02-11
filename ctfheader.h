#ifndef CTFHEADER_H
#define CTFHEADER_H

#include <QObject>
#include <QFile>
#include "ctflanguage.h"

class CTFHeader : public QObject
{
    Q_OBJECT
public:
    explicit CTFHeader(QObject *parent = nullptr);
    static CTFHeader * readCTFHeader(QFile * cff, long baseAddress, int32_t headerSize, QObject * parent = Q_NULLPTR);

    Q_PROPERTY(QString Qualifier READ Qualifier WRITE setQualifier NOTIFY QualifierChanged);
    Q_PROPERTY(int32_t CtfUnk1 READ CtfUnk1 WRITE setCtfUnk1 NOTIFY CtfUnk1Changed);
    Q_PROPERTY(int32_t CtfUnk3 READ CtfUnk3 WRITE setCtfUnk3 NOTIFY CtfUnk3Changed);
    Q_PROPERTY(int32_t CtfUnk4 READ CtfUnk4 WRITE setCtfUnk4 NOTIFY CtfUnk4Changed);
    Q_PROPERTY(QString CtfUnkString READ CtfUnkString WRITE setCtfUnkString NOTIFY CtfUnkStringChanged);
    Q_PROPERTY(QList<CTFLanguage *> CtfLanguages READ CtfLanguages WRITE setCtfLanguages NOTIFY CtfLanguagesChanged);

    QString Qualifier(){return this->m_Qualifier;}
    int32_t CtfUnk1(){return this->m_CtfUnk1;}
    int32_t CtfUnk3(){return this->m_CtfUnk3;}
    int32_t CtfUnk4(){return this->m_CtfUnk4;}
    QString CtfUnkString(){return this->m_CtfUnkString;}
    QList<CTFLanguage *> CtfLanguages(){return this->m_CtfLanguages;}

    void setQualifier(QString data){this->m_Qualifier = data; emit QualifierChanged();}
    void setCtfUnk1(int32_t data){this->m_CtfUnk1 = data; emit CtfUnk1Changed();}
    void setCtfUnk3(int32_t data){this->m_CtfUnk3 = data; emit CtfUnk3Changed();}
    void setCtfUnk4(int32_t data){this->m_CtfUnk4 = data; emit CtfUnk4Changed();}
    void setCtfUnkString(QString data){this->m_CtfUnkString = data; emit CtfUnkStringChanged();}
    void setCtfLanguages(QList<CTFLanguage *> data){this->m_CtfLanguages = data; emit CtfLanguagesChanged();}

private:
    void readCFFData(QFile * cff, long baseAddress, int32_t headerSize);

signals:
    void QualifierChanged();
    void CtfUnk1Changed();
    void CtfUnk3Changed();
    void CtfUnk4Changed();
    void CtfUnkStringChanged();
    void CtfLanguagesChanged();

private:
    QString                 m_Qualifier;
    QString                 m_CtfUnkString;
    int32_t                 m_CtfUnk1;
    int32_t                 m_CtfUnk3;
    int32_t                 m_CtfUnk4;
    int32_t                 m_CtfLanguageCount;
    int32_t                 m_CtfLanguageTableOffset;

    QList<CTFLanguage *>    m_CtfLanguages;
    long                    m_BaseAddress;
};

#endif // CTFHEADER_H
