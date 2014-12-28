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
#include <QTextEdit>
# include "QVBoxLayout"
# include "QCheckBox"
# include "QLabel"
#include "params.h"



class Content : public QWidget
{
    Q_OBJECT
public:
    explicit Content(QWidget *parent = 0);
    QPushButton *VOpenPriceButton;
    QPushButton *VSyncPriceButton;
    QPushButton *VParamDBButton;
    QPushButton *VExitButton;


    QGroupBox *VGroup1;
    QGroupBox *VGroup2;
    QHBoxLayout *horizontalLayot;

    QVBoxLayout *verLayot1;
    QVBoxLayout *verLayot2;

    params *Param;



signals:


public slots:
    void SetParamCheckBox(int value );
    void SetTextEdit(QString value );
    void SetLabelName(QString value );

};

#endif // CONTENT_H
