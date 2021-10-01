#ifndef CTFLANGUAGE_H
#define CTFLANGUAGE_H

#include <QObject>
#include <QFile>


class CTFLanguage : public QObject
{
    Q_OBJECT
public:
    explicit CTFLanguage(QObject *parent = nullptr);
    static CTFLanguage * readCTFLanguage(QFile * cff, long baseAddress, int32_t headerSize, QObject * parent = Q_NULLPTR);

    Q_PROPERTY(QString Qualifier READ Qualifier WRITE setQualifier NOTIFY QualifierChanged);
    Q_PROPERTY(int32_t LanguageIndex READ LanguageIndex WRITE setLanguageIndex NOTIFY LanguageIndexChanged);
    Q_PROPERTY(QStringList StringEntries READ StringEntries WRITE setStringEntries NOTIFY StringEntriesChanged);

    QString Qualifier(){return this->m_Qualifier;}
    int32_t LanguageIndex(){return this->m_LanguageIndex;}
    QStringList StringEntries(){return this->m_StringEntries;}

    void setQualifier(QString data){this->m_Qualifier = data; emit QualifierChanged();}
    void setLanguageIndex(int32_t data){this->m_LanguageIndex = data; emit LanguageIndexChanged();}
    void setStringEntries(QStringList data){this->m_StringEntries = data; emit StringEntriesChanged();}

private:
    void readCFFData(QFile * cff, long baseAddress, int32_t headerSize);
    void loadStrings(QFile * cff, int32_t headerSize);

signals:
    void QualifierChanged();
    void LanguageIndexChanged();
    void StringEntriesChanged();

private:
    QString     m_Qualifier;
    int32_t     m_LanguageIndex;
    QStringList m_StringEntries;
    int32_t     m_StringPoolSize;
    int32_t     m_MaybeOffsetFromStringPoolBase;
    int32_t     m_StringCount;
    long        m_BaseAddress;

};

#endif // CTFLANGUAGE_H
