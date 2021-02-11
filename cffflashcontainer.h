#ifndef CFFFLASHCONTAINER_H
#define CFFFLASHCONTAINER_H

#include <QObject>
#include <QFile>

class CFFFlashHeader;

class CTFHeader;
class CFFFlashContainer : public QObject
{
    Q_OBJECT
public:
    static CFFFlashContainer * openCaesarFlashContainer(QString fname, QObject *parent = nullptr);

    QByteArray readHeader();
    QByteArray readCFFHeader();
    int32_t readChecksum();
    int32_t CrcAccumulate();
    CFFFlashHeader * ReadFlashCFF();

    CTFHeader * ReadCTF();


private:
    explicit CFFFlashContainer(QObject *parent = nullptr);


signals:


private:
    QFile *         m_cff_file;
    QByteArray      m_cff_mem;


    CFFFlashHeader *    m_FlashHeader;
    CTFHeader *         m_CTFHeader;

    const int StubHeaderSize = 0x410;
    QString FileHeader = "CBF-TRANSLATOR-VERSION:04.00";

};

#endif // CFFFLASHCONTAINER_H
