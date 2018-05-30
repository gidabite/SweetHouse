#-------------------------------------------------
#
# Project created by QtCreator 2018-05-29T18:10:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SweetHouse
TEMPLATE = app

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
    exceptions/nullnodeexception.cpp \
    exceptions/workerisbusyexception.cpp \
    graph/graph.cpp \
    graph/node.cpp \
    graph/process.cpp \
    graph/psgraph.cpp \
    project/project.cpp \
    worker/slot.cpp \
    worker/specialization.cpp \
    worker/worker.cpp \
    auth.cpp \
    configuration.cpp \
    main.cpp \
    mainwindow.cpp \
    exceptions/specializationexception.cpp \
    exceptions/PossibleSpecAEExeption.cpp \
    exceptions/possiblespecializationnotexistexeption.cpp \
    exceptions/usedspecializationalreadyexist.cpp \
    exceptions/usedspecializationnotexist.cpp \
    workermanager.cpp \
    singleton.cpp \
    serialization/serializable.cpp \
    serialization/serializer.cpp \
    graph/graphexpression.cpp \
    gui/createworkerdialog.cpp


HEADERS += \
    exceptions/nullnodeexception.h \
    exceptions/workerisbusyexception.h \
    graph/graph.h \
    graph/node.h \
    graph/process.h \
    graph/psgraph.h \
    project/project.h \
    worker/slot.h \
    worker/specialization.h \
    worker/worker.h \
    auth.h \
    configuration.h \
    mainwindow.h \
    exceptions/specializationexception.h \
    exceptions/PossibleSpecAEExeption.h \
    exceptions/possiblespecializationnotexistexeption.h \
    exceptions/specializations.h \
    exceptions/usedspecializationalreadyexist.h \
    exceptions/usedspecializationnotexist.h \
    workermanager.h \
    singleton.h \
    serialization/serializable.h \
    serialization/serializer.h \
    graph/graphexpression.h \
    gui/createworkerdialog.h


FORMS += \
        mainwindow.ui \
    createworker.ui

TRANSLATIONS += \
    translations/sweethouse_ru.ts

RESOURCES += \
    resource.qrc
