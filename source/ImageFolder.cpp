
#include "ImageFolder.h"
#include "QMessageBox"
#include "QVector"
#include "QDate"
#include "QtMultimedia/QMediaMetaData"
#include "QtMultimedia/QMediaObject"
#include <QImage>
    #include <QCamera>



bool checkFolder(QString Dir)
{
    return QFileInfo::exists(Dir);
}

/*
 *  Функия проверки является ли папка поддерикторией
 *
 */
bool checkIsSubFolder(QString Dest,QString Res)
{
    return Res.contains(Dest, Qt::CaseInsensitive);
}

QDate GetDatebyExif(QString filename)
{

}

bool CreateFolderByDate(QDate date, QString ResultFolder )
{
    QString dir=ResultFolder+"//"+date.year()+"//"+date.month();
    QDir path(dir);
    if(!checkFolder(dir))
    {
        return path.mkdir(dir);
    }else return true;
}

void action(bool creatRaw,bool saveOrgFaleName, QString Dest, QString Result)
{
   QVector<QString> Dirs;
   QVector<QString> Files;
   QDir dir(Dest);
   dir.setFilter(QDir::Files |  QDir::NoSymLinks);
   dir.setSorting(QDir::Size);
   QFileInfoList list = dir.entryInfoList();
   for (int i = 0; i < list.size(); ++i)
   {
        QFileInfo fileInfo = list.at(i);
        Files.push_back(fileInfo.fileName());
        GetDatebyExif(fileInfo.fileName())
   }
    dir.setFilter(QDir::AllDirs|  QDir::NoDotAndDotDot);
    QFileInfoList list2 = dir.entryInfoList();
    for (int i = 0; i < list2.size(); ++i)
    {
         QFileInfo fileInfo = list2.at(i);
         Dirs.push_back(fileInfo.fileName());
    }

}

ImageFolder::ImageFolder(QWidget *parent)
    : QMainWindow(parent)
{
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
    content->DestLabel->setText(DestinationFolder);






}

void ImageFolder::sync()
{
    bool error=false;
    //Проверка папки с исходниками
    if(!checkFolder(DestinationFolder))
    {
        QMessageBox::warning(this, tr("Предупреждение"),
                                       tr("Выберите папку с изображениями "),
                                       QMessageBox::Ok);
        error=true;
    }
    //проверка конечной папки
    if(!checkFolder(ResultFolder))
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
        action(true,true, DestinationFolder, ResultFolder);
    }
}

void ImageFolder::resultfolderselectaction()
{
    ResultFolder = QFileDialog::getExistingDirectory(this, tr("Выбрать конечную папку"),"/home", QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);

    content->ResultLabel->setText(ResultFolder);
}



