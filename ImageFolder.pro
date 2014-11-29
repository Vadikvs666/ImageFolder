#-------------------------------------------------
#
# 
#
#-------------------------------------------------

QT += core
QT +=gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = inputGoods
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
   

HEADERS  += mainwindow.h \
   

FORMS    += mainwindow.ui \
        searchpost.ui

RESOURCES +=
