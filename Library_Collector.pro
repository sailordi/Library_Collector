QT  += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
CONFIG -=debug_and_release

CONFIG(release,debug|release)   { TARGET = Library_Collector }
CONFIG(debug,debug|release)     { TARGET = Library_Collector_D }

SOURCES += main.cpp \
    Data/Collector.cpp \
    WindowMain.cpp

HEADERS += \
    Data/Collector.h \
    WindowMain.h

FORMS += \
    WindowMain.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
