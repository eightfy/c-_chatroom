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
    icon.qrc
