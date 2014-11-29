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
# include "QCheckBox"



class Content : public QWidget
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = 0);
    QPushButton *VOpenPriceButton;
    QPushButton *VSyncPriceButton;
    QPushButton *VParamDBButton;
    QPushButton *VExitButton;
    QCheckBox *VCreateRawFolder;

    QGroupBox *VButtonGroup;
    QHBoxLayout *horizontalLayot;
    QVBoxLayout *verLayot;



signals:

public slots:

};

#endif // CONTENT_H
