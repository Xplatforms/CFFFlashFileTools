#include "defs.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "cffflashcontainer.h"
#include "cffflashheader.h"
#include "cffflashdescriptionheader.h"
#include "cffflashdatablock.h"
#include "cffflashsegment.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qRegisterMetaType<uint32_t>("uint32_t");
    qmlRegisterType<CFFFlashContainer>("xplatforms.cffflashcontainer.container", 1, 0, "CFFFlashContainer");
    qmlRegisterType<CFFFlashHeader>("xplatforms.cffflashcontainer.flashheader", 1, 0, "CFFFlashHeader");
    qmlRegisterType<CFFFlashDataBlock>("xplatforms.cffflashcontainer.flashblock", 1, 0, "CFFFlashDataBlock");
    //qmlRegisterType<QList<CFFFlashDataBlock*> >("xplatforms.cffflashcontainer.flashblocks", 1, 0, "CFFFlashDataBlocks");



    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);


        auto cff = CFFFlashContainer::openCaesarFlashContainer("c:\\DIAG\\Dev\\219\\cbf\\TEST\\2049023103_001.CFF", obj);

        auto header = cff->readHeader();
        auto cff_header = cff->readCFFHeader();
        auto cff_chksum = cff->readChecksum();
        auto cff_calc_chksum = cff->genChecksum();
        auto cff_flash_header = cff->readFlashCFF();
        auto ctf_header = cff->readCTF();

        foreach(auto db, cff_flash_header->FlashDataBlocks())
        {
            foreach(auto segment, db->FlashSegments())
            {
                qDbg() << "Segment: " << segment->SegmentName();
                QFile seg_file("c:\\DIAG\\Dev\\219\\cbf\\TEST\\"+segment->SegmentName()+".flash");
                if(seg_file.open(QIODevice::WriteOnly))
                {
                    seg_file.write(segment->readFlashSegment());
                    seg_file.close();
                }
            }
        }

        //foreach(auto db , cff_flash_header->)


    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
