#-------------------------------------------------
#
# Project created by QtCreator 2022-11-06T16:43:42
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += core gui sql
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KursachArtemev
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#win32:RC_ICONS += your_icon.ico

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    popup.cpp \
    form.cpp \
    database.cpp

HEADERS += \
        mainwindow.h \
    popup.h \
    form.h \
    database.h

FORMS += \
        mainwindow.ui \
    form.ui

RESOURCES += \
    file.qrc
