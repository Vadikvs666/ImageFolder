#-------------------------------------------------
#
# 
#
#-------------------------------------------------

QT += core
QT +=gui



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageFolder
TEMPLATE = app


SOURCES += main.cpp\
        imagefolder.cpp \
        content.cpp \
    qimagemetadata/QImageMetaData.cpp \
    actionthread.cpp \
    params.cpp

   

HEADERS  += imagefolder.h \
            content.h \
    qimagemetadata/QImageMetaData.h \
    qimagemetadata/QImageMetaDataRational.h \
    actionthread.h \
    params.h
   



RESOURCES +=
