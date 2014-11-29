
#include "ImageFolder.h"

ImageFolder::ImageFolder(QWidget *parent)
    : QMainWindow(parent)
{
    //заголовок формы
    this->setWindowTitle("ImageByFolderOrganizer");

    //создание экшенов
    openAction = new QAction(tr("Выбрать папку с фотографиями"), this);
    resultFolderAction= new QAction(tr("Выбрать конечную  папку "), this);
    syncAction = new QAction(tr("Выполнить опрерацию"), this);
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

}

void ImageFolder::resultfolderselectaction()
{
    ResultFolder = QFileDialog::getExistingDirectory(this, tr("Выбрать конечную папку"),"/home", QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);

    content->ResultLabel->setText(ResultFolder);
}


