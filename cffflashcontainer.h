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
    explicit CFFFlashContainer(QObject *parent = nullptr);


    Q_INVOKABLE static CFFFlashContainer * openCaesarFlashContainer(QString fname, QObject *parent = nullptr);

    Q_INVOKABLE uint32_t readChecksum();
    Q_INVOKABLE uint32_t genChecksum();

    QByteArray readHeader();
    QByteArray readCFFHeader();

    Q_INVOKABLE CFFFlashHeader * readFlashCFF();
    Q_INVOKABLE CTFHeader * readCTF();


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
