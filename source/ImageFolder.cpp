
#include "ImageFolder.h"

ImageFolder::ImageFolder(QWidget *parent)
    : QMainWindow(parent)
{
    //заголовок формы
    this->setWindowTitle("WWW.HOZTOVATY-OMSK.RU");

    //создание экшенов
    openAction = new QAction(tr("Открыть прайс"), this);
    loadSyteAction = new QAction(tr("загрузить из сайта"), this);
    syncAction = new QAction(tr("Синхронизация"), this);
    exitAction = new QAction(tr("Выход"), this);
    paramAction = new QAction(tr("Параметры"), this);

    //соединение со слотами функций
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(syncAction, SIGNAL(triggered()), this, SLOT(sync()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(quit()));
    connect(loadSyteAction, SIGNAL(triggered()), this, SLOT(load()));
    connect(paramAction, SIGNAL(triggered()), this, SLOT(param()));


    //создание центрального виджета
    content = new Content(this);

    //создание меню
    menu = new QMenuBar;

    //добавление пункта меню и экшенов
    QMenu *fileMenu = new QMenu(tr("Файл"), this);
    fileMenu->addAction(openAction);
    fileMenu->addAction(loadSyteAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    QMenu *workMenu = new QMenu(tr("Действия"), this);
    workMenu->addAction(syncAction);
    workMenu->addAction(paramAction);

    menu->addMenu(fileMenu);
    menu->addMenu(workMenu);

    bar =new QStatusBar;

    bar->showMessage("Загрузите прайс лист..",10000);

    setMenuBar(menu);
    setCentralWidget(content);
    setStatusBar(bar);

    //сигнал по завершению загрузки из БД
    connect(this, SIGNAL(compleet()), this, SLOT(loadcomleat()));



}

ImageFolder::~ImageFolder()
{

}

void ImageFolder::quit()
{
    emit goodbuy();
    this->close();
}

void ImageFolder::open()
{

    bool error=false;
    //вызов окна выбора файла
    QString  fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл"),"/home",tr("прайс (*.csv)"));

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //Обработка ошибки открытия файла
        error=true;

    }
    else
    {

        QTextStream in(&file);
        while (!in.atEnd())
        {
           QString line = in.readLine();
           process_line(line);
        }
    }
    done_load(error);


}


