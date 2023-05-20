QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    exercise.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    model_choose.cpp \
    register.cpp

HEADERS += \
    exercise.h \
    login.h \
    mainwindow.h \
    model_choose.h \
    register.h \
    usr_info.h

FORMS += \
    exercise.ui \
    login.ui \
    mainwindow.ui \
    model_choose.ui \
    register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
