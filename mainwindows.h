#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void goodbuy();

private slots:
    void on_CloseButton_clicked();

private:
  
};

#endif // MAINWINDOW_H
