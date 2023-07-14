QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 static

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    additionalinfogetter.cpp \
    courses.cpp \
    customcoursesadd.cpp \
    keycolorslots.cpp \
    keymapping.cpp \
    main.cpp \
    mainwindow.cpp \
    keycolor.cpp \
    keymappingslots.cpp

HEADERS += \
    additionalinfogetter.h \
    courses.h \
    customcoursesadd.h \
    keycolorslots.h \
    keymapping.h \
    mainwindow.h \
    preapptasks.h \
    keycolor.h \
    keymappingslots.h

FORMS += \
    courses.ui \
    customcoursesadd.ui \
    keycolorslots.ui \
    keymapping.ui \
    mainwindow.ui \
    keycolor.ui \
    keymappingslots.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = icon.ico

RESOURCES += \
    pictures.qrc
