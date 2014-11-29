
#include "ImageFolder.h"

ImageFolder::ImageFolder(QWidget *parent)
    : QMainWindow(parent)
{
    //заголовок формы
    this->setWindowTitle("ImageByFolderOrganizer");

    //создание экшенов
    openAction = new QAction(tr("Выбрать папку с фотографиями"), this);

    syncAction = new QAction(tr("Выполнить опрерацию"), this);
    exitAction = new QAction(tr("Выход"), this);


    //соединение со слотами функций
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
    connect(syncAction, SIGNAL(triggered()), this, SLOT(sync()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(quit()));



    //создание центрального виджета
    content = new Content(this);

    //создание меню
    menu = new QMenuBar;

    //добавление пункта меню и экшенов
    QMenu *fileMenu = new QMenu(tr("Файл"), this);
    fileMenu->addAction(openAction);

    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    QMenu *workMenu = new QMenu(tr("Действия"), this);
    workMenu->addAction(syncAction);


    menu->addMenu(fileMenu);
    menu->addMenu(workMenu);

    bar =new QStatusBar;

    bar->showMessage("Выберите папку с фотографиями..",10000);

    setMenuBar(menu);
    setCentralWidget(content);
    setStatusBar(bar);

    //сигнал по завершению загрузки из БД



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
           //process_line(line);
        }
    }
   // done_load(error);


}

void ImageFolder::sync()
{

}


