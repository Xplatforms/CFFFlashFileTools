#ifndef CFFUTILS_H
#define CFFUTILS_H

#include <QObject>
#include <QFile>


#define ReadBitflag4Byte(o,b,f) 0;{if(CFFUtils::CheckAndAdvanceBitflag(b))f->read((char*)&o, 4);}
<<<<<<< HEAD
#define ReadBitflag2Byte(o,b,f) 0;{if(CFFUtils::CheckAndAdvanceBitflag(b))f->read((char*)&o, 2);}
=======
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
#define ReadBitflag1Byte(o,b,f) 0;{if(CFFUtils::CheckAndAdvanceBitflag(b))f->read((char*)&o, 1);}


class CFFUtils : public QObject
{
    Q_OBJECT
public:
    explicit CFFUtils(QObject *parent = nullptr);

    static bool CheckAndAdvanceBitflag(ulong & bitFlag);
<<<<<<< HEAD
    static QString ReadString(QFile * cff);
    static QString ReadBitflagString(ulong & bitFlags, QFile * cff, long virtualBase = 0);
=======
    static QString ReadStringFromBinaryReader(QFile * cff);
    static QString ReadBitflagStringWithReader(ulong & bitFlags, QFile * cff, long virtualBase = 0);
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961

signals:

};

#endif // CFFUTILS_H
