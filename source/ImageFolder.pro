#-------------------------------------------------
#
# 
#
#-------------------------------------------------

QT += core
QT +=gui
QT +=multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageFolder
TEMPLATE = app


SOURCES += main.cpp\
        imagefolder.cpp \
        content.cpp

   

HEADERS  += imagefolder.h \
            content.h\
   



RESOURCES +=
