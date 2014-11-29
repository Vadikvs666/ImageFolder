#ifndef IMAGEFOLDER_H
#define IMAGEFOLDER_H

#include <QMainWindow>
#include <QVector>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <content.h>
#include "model.h"
#include "dbsingl.h"
#include "../products/products.h"
#include "../products/listelem.h"
#include "QFileDialog"
#include "QFile"
#include "QTextStream"
#include "QTableWidgetItem"
#include "QSqlTableModel"
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
    QAction *loadSyteAction;
    QAction *paramAction;

    QMenuBar *menu;
    QStatusBar *bar;

    Content *content;

    QVector<Products> prod;
    QVector<QStringList> prod_list;

    QString remK(QString str);


signals:
    void goodbuy();
    void compleet();

private slots:
    void quit();//выход из приложения
    void open();//функция открытия файла прайса
    void sync();
    void load();
    void param();
    void process_line(QString line);
    void done_load(bool err);
    void loadcomleat();
    void addToTableWidget(QVector<QStringList> list);



};

#endif // IMAGEFOLDER_H
