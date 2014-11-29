#include "imagefolder.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("Windows-1251"));
    QApplication a(argc, argv);
    Sync w;
    w.resize(800,600);
    w.show();

    return a.exec();
}
