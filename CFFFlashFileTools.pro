QT += qml quick widgets

CONFIG += c++20
win32:CONFIG += c++latest
win32:QMAKE_CXXFLAGS += /std:c++latest

TARGET=CFFFlashFileTools

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        cffflashcontainer.cpp \
        cffflashdatablock.cpp \
        cffflashdatablocksmodel.cpp \
        cffflashdescriptionheader.cpp \
        cffflashheader.cpp \
        cffflashsegment.cpp \
        cffflashsegmentmodel.cpp \
        cffutils.cpp \
        ctfheader.cpp \
        ctflanguage.cpp \
        main.cpp

RESOURCES += qml.qrc \
    images.qrc

TRANSLATIONS += \
    CFFFlashFileTools_ru_RU.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cffflashcontainer.h \
    cffflashdatablock.h \
    cffflashdatablocksmodel.h \
    cffflashdescriptionheader.h \
    cffflashheader.h \
    cffflashsegment.h \
    cffflashsegmentmodel.h \
    cffutils.h \
    ctfheader.h \
    ctflanguage.h \
    defs.h
