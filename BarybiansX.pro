QT       += core gui svg network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    base/basefragment.cpp \
    base/basefragmentfactory.cpp \
    base/basemodel.cpp \
    base/router.cpp \
    base/utils/requestx.cpp \
    base/utils/webconnectorx.cpp \
    cwidgets/addition/cardwidget.cpp \
    cwidgets/addition/menuheaderwidget.cpp \
    cwidgets/cardview.cpp \
    cwidgets/implfragmentfactory.cpp \
    cwidgets/slidingstackedwidget.cpp \
    fragmentts/loginfragment.cpp \
    fragmentts/splashfragment.cpp \
    fragmentts/userfragment.cpp \
    fragmentts/userpagefragment.cpp \
    main.cpp \
    mainwindow.cpp \
    base/utils/webconnector.cpp \
    base/data/data.cpp

HEADERS += \
    base/basefragment.h \
    base/basefragmentfactory.h \
    base/basemodel.h \
    base/data/constants.h \
    base/router.h \
    base/utils/requestx.h \
    base/utils/webconnectorx.h \
    cwidgets/addition/cardwidget.h \
    cwidgets/addition/menuheaderwidget.h \
    cwidgets/cardview.h \
    cwidgets/implfragmentfactory.h \
    cwidgets/slidingstackedwidget.h \
    fragmentts/loginfragment.h \
    fragmentts/splashfragment.h \
    fragmentts/userfragment.h \
    fragmentts/userpagefragment.h \
    mainwindow.h \
    base/utils/webconnector.h \
    base/data/data.h \
ICON=appicon.icns
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
