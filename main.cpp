#include "defs.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "cffflashcontainer.h"
#include "cffflashheader.h"
#include "cffflashdescriptionheader.h"
#include "cffflashdatablock.h"
#include "cffflashdatablocksmodel.h"
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
    qmlRegisterType<CFFFlashDataBlocksModel>("xplatforms.cffflashcontainer.flashblocksmodel", 1, 0, "CFFFlashDataBlocksModel");



    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
