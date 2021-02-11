#include "defs.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "cffflashcontainer.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);

<<<<<<< HEAD
        auto cff = CFFFlashContainer::openCaesarFlashContainer("c:\\DIAG\\Dev\\219\\cbf\\ME28\\0054486502_001.cff", obj);
=======
        auto cff = CFFFlashContainer::openCaesarFlashContainer("C:\\Dev\\ZGW211.CFF", obj);
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961
        auto header = cff->readHeader();
        auto cff_header = cff->readCFFHeader();
        auto cff_chksum = cff->readChecksum();
        auto cff_calc_chksum = cff->CrcAccumulate();
        auto cff_flash_header = cff->ReadFlashCFF();
<<<<<<< HEAD
        auto ctf_header = cff->ReadCTF();
=======
>>>>>>> 6a3ae424ef77d14426213ab2a293862fd3d7a961

    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
