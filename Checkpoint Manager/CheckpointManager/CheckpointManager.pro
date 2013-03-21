#-------------------------------------------------
#
# Project created by QtCreator 2013-03-20T15:15:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CheckpointManager
TEMPLATE = app


SOURCES += main.cpp\
        checkpointmanager.cpp \
    node.cpp \
    entrant.cpp \
    course.cpp

HEADERS  += checkpointmanager.h \
    node.h \
    entrant.h \
    course.h

FORMS    += checkpointmanager.ui
