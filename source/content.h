#ifndef CONTENT_H
#define CONTENT_H

#include <QWidget>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
# include <QLayout>
# include "QVBoxLayout"
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>


class Content : public QWidget
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = 0);
    QPushButton *VOpenPriceButton;
    QPushButton *VSyncPriceButton;
    QPushButton *VParamDBButton;
    QPushButton *VExitButton;

    QGroupBox *VButtonGroup;
    QHBoxLayout *horizontalLayot;
    QVBoxLayout *verLayot;

    QTableView *VTable;
    QTableWidget *WTable;

signals:

public slots:

};

#endif // CONTENT_H
