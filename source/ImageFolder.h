#ifndef IMAGEFOLDER_H
#define IMAGEFOLDER_H

#include <QMainWindow>
#include <QVector>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <content.h>
#include "QFileDialog"
#include "QFile"
#include "QTextStream"

#include <QStatusBar>

class ImageFolder : public QMainWindow
{
    Q_OBJECT

public:
    ImageFolder(QWidget *parent = 0);
    ~ImageFolder();

    QAction *openAction  ;
    QAction *syncAction ;
    QAction *exitAction;
    QAction *resultFolderAction;
    QAction *paramAction;

    QMenuBar *menu;
    QStatusBar *bar;
    Content *content;

    

    QString DestinationFolder;
    QString ResultFolder;





signals:
    void goodbuy();
    void compleet();

private slots:
    void quit();//выход из приложения
    void open();//функция открытия файла прайса
    void sync();
    void resultfolderselectaction();
 



};

#endif // IMAGEFOLDER_H
