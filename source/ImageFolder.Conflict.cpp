
#include "imagefolder.h"
#include "QMessageBox"
#include "QVector"
#include "QDate"

#include <QImage>

#include "qimagemetadata//QImageMetaData.h"


/*
 *  Функия проверки является ли папка поддерикторией
 *
 */
bool checkIsSubFolder(QString Dest,QString Res)
{
    return Res.contains(Dest, Qt::CaseInsensitive);
}



bool checkSelFolder(QString Dir)
{
    QDir dir(Dir);
    return QFile::exists(Dir);
}



ImageFolder::ImageFolder(QWidget *parent)
    : QMainWindow(parent)
{
    createRawFolder=false;
    SaveDestinationFolder=false;
    GetSmallCopy=false;
    KeapRaw=false;
    KeapOriginal=false;

    //заголовок формы
    this->setWindowTitle("Фото органайзер");

    //создание экшенов
    openAction = new QAction(tr("Выбрать папку с фотографиями"), this);
    resultFolderAction= new QAction(tr("Выбрать конечную  папку "), this);
    syncAction = new QAction(tr("Выполнить операцию"), this);
    exitAction = new QAction(tr("Выход"), this);


    //соединение со слотами функций
    connect(openAction, SIGNAL(triggered()), this, SLOT(open()));
     connect(resultFolderAction, SIGNAL(triggered()), this, SLOT(resultfolderselectaction()));
    connect(syncAction, SIGNAL(triggered()), this, SLOT(sync()));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(quit()));



    //создание центрального виджета
    content = new Content(this);

    //создание меню
    menu = new QMenuBar;

    //добавление пункта меню и экшенов
    QMenu *fileMenu = new QMenu(tr("Файл"), this);
    fileMenu->addAction(openAction);
    fileMenu->addAction(resultFolderAction);

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


    //вызов окна выбора файла
    DestinationFolder = QFileDialog::getExistingDirectory(this, tr("Выбрать папку с фотографиями"),"/home", QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    content->Param->setDestinationFolder(DestinationFolder);

    content->findChild<QLabel *>("DestinationFolder")->setText(DestinationFolder);







}

void ImageFolder::sync()
{
    bool error=false;
    //Проверка папки с исходниками
    if(!checkSelFolder(DestinationFolder))
    {
        QMessageBox::warning(this, tr("Предупреждение"),
                                       tr("Выберите папку с изображениями "),
                                       QMessageBox::Ok);
        error=true;
    }
    //проверка конечной папки
    if(!checkSelFolder(ResultFolder))
    {
        QMessageBox::warning(this, tr("Предупреждение"),
                                       tr("Выберите папку для конечных изображений "),
                                       QMessageBox::Ok);
        error=true;
    }
    //Проверка
    if(checkIsSubFolder(DestinationFolder,ResultFolder))
    {
        QMessageBox::warning(this, tr("Предупреждение"),
                                       tr("Выберите другую папку для конечных изображений... Нельзя чтобы  папка располагалась в папке с изображениями "),
                                       QMessageBox::Ok);
        error=true;
    }
    if(!error)
    {
        //выполнение перемещения фотографий
        QMessageBox::information( this, "Все в порядке","Выполнение"
                                       );
        //action(createRawFolder,SaveDestinationFolder,GetSmallCopy,KeapOriginal,KeapRaw, DestinationFolder, ResultFolder);
        ActionThread *Th=new ActionThread(content->Param);

        connect(Th,SIGNAL(message(QString)),this,SLOT(setInfoinBar(QString)));

        connect(Th,SIGNAL(log(QString)),this,SLOT(log(QString)));
        Th->start();
    }
}

void ImageFolder::resultfolderselectaction()
{
    ResultFolder = QFileDialog::getExistingDirectory(this, tr("Выбрать конечную папку"),"/home", QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);

    content->Param->setResultFolder(ResultFolder);

    content->findChild<QLabel *>("ResultFolder")->setText(ResultFolder);

}

void ImageFolder::setInfoinBar(QString msg)
{
    bar->showMessage(msg);
}

void ImageFolder::log(QString msg)
{
    QFile file("out.txt");
        if (!file.open(QIODevice::Append| QIODevice::Text))
            return;



        QTextStream out(&file);
        out << msg << "\n";

}

