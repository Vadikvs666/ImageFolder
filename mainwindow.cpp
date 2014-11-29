#include "mainwindow.h"

#include "QFile.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
    
{
    

}


MainWindow::~MainWindow()
{
    
}


void MainWindow::on_CloseButton_clicked()
{
    emit goodbuy();
    this->close();
}
