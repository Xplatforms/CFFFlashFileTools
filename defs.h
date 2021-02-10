#ifndef DEFS_H
#define DEFS_H

#include <QObject>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDevice>
#include <QIODevice>


#define DELETE_OBJ(o){if(o != Q_NULLPTR){delete o; o = Q_NULLPTR;}}
#define DELETE_OBJ_LATER(o){if(o != Q_NULLPTR){o->deleteLater();}}
#define DELETE_STR(s){if(s != Q_NULLPTR){delete [] s; s = Q_NULLPTR;}}

#define qDbg() qDebug() << "["<< (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__) << __func__ << __LINE__ << "]: "
#define qDbgVar(v) qDbg() << #v << v;
#define qMd5(s) QCryptographicHash::hash(s.toLocal8Bit(), QCryptographicHash::Md5).toHex()

#include "cffutils.h"

/*
#define MEMWATCH(obj, objq) ExMemWatcher::getInstance()->addObject(reinterpret_cast<qlonglong>(obj), QStringLiteral(#objq)); \
connect(obj, &objq::destroyed, [o=obj](){ExMemWatcher::getInstance()->removeObject(reinterpret_cast<qlonglong>(o));})
*/

#endif // DEFS_H
