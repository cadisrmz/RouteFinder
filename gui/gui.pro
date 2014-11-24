#-------------------------------------------------
#
# Project created by QtCreator 2014-11-07T11:14:18
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app
CONFIG += c++11

LIBS += -lzip

SOURCES += main.cpp\
        mainwindow.cpp \
    debugwindow.cpp \
    ../src/algorithm/BSF.cpp \
    ../src/algorithm/DSF.cpp \
    ../src/algorithm/SimAnnealingAlg.cpp \
    ../src/db/lib/DataReader.cpp \
    ../src/db/lib/GTFSReader.cpp \
    ../src/db/lib/RouteData.cpp \
    ../src/db/lib/ServiceData.cpp \
    ../src/db/lib/StopData.cpp \
    ../src/db/lib/StopTimeData.cpp \
    ../src/db/lib/Time.cpp \
    ../src/db/lib/TripData.cpp \
    ../src/db/DataBase.cpp \
    ../src/graph/Connection.cpp \
    ../src/graph/Edge.cpp \
    ../src/graph/Network.cpp \
    ../src/graph/Node.cpp \
    ../src/graph/Route.cpp \
    ../src/jsoncpp/jsoncpp.cpp

HEADERS  += mainwindow.h \
    debugwindow.h \
    ../src/algorithm/BSF.h \
    ../src/algorithm/DSF.h \
    ../src/algorithm/SimAnnealingAlg.h \
    ../src/algorithm/Solver.h \
    ../src/db/lib/DataReader.h \
    ../src/db/lib/GTFSReader.h \
    ../src/db/lib/RouteData.h \
    ../src/db/lib/ServiceData.h \
    ../src/db/lib/StopData.h \
    ../src/db/lib/StopTimeData.h \
    ../src/db/lib/Time.h \
    ../src/db/lib/TripData.h \
    ../src/db/DataBase.h \
    ../src/graph/Connection.h \
    ../src/graph/Edge.h \
    ../src/graph/Network.h \
    ../src/graph/Node.h \
    ../src/graph/Route.h \
    ../src/graph/TransportType.h \
    ../src/jsoncpp/json/json-forwards.h \
    ../src/jsoncpp/json/json.h

FORMS    += mainwindow.ui \
    debugwindow.ui
