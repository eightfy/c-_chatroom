QT       += core gui
QT       += network
LIBS += -lWs2_32
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG -= console

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


TARGET = communication
TEMPLATE = app

SOURCES += \
    connects.cpp \
    fun.cpp \
    main.cpp \
    mainwindow.cpp \
    set_name.cpp

HEADERS += \
    mainwindow.h \
    member.h \
    set_name.h

FORMS += \
    mainwindow.ui \
    set_name.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icon.qrc \
    monaka/monaka.qrc

DISTFILES += \
    monaka/cry.png \
    monaka/die.png \
    monaka/hhh.png \
    monaka/miao.png \
    monaka/mua.png \
    monaka/nice.png \
    monaka/run.png \
    monaka/xixi.png \
    monaka/zzz.png \
    monaka/呜呜呜.png \
    monaka/呼呼.png \
    monaka/咧嘴.png \
    monaka/喵.png \
    monaka/嘲笑.png \
    monaka/好耶.png \
    monaka/撬棍.png \
    monaka/轰.png
