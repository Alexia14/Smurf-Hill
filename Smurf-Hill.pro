#-------------------------------------------------
#
# Project created by QtCreator 2018-03-20T14:31:13
#
#-------------------------------------------------

QT += core gui
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Smurf-Hill
TEMPLATE = app
TRANSLATIONS += \
        smurfHill_fr_FR.ts \
        smurfHill_en_EN.ts

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        view.cpp \
    model.cpp \
    controller.cpp \
    autre.cpp \
    personnages.cpp \
    ressources.cpp \
    decor.cpp \
    action.cpp

HEADERS += \
        view.h \
    model.h \
    controller.h \
    autre.h \
    personnages.h \
    ressources.h \
    decor.h \
    action.h

FORMS += \
        view.ui

SUBDIRS += \
    Smurf-Hill.pro

RESOURCES += \
    images.qrc
