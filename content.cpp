#include "content.h"

Content::Content(QWidget *parent) :
    QWidget(parent)
{
    //создание объекта таблицы
    VTable =new QTableView();
    WTable= new QTableWidget ;
    // создание вида горизонтального расположениея кнопок
    horizontalLayot =new QHBoxLayout();
    horizontalLayot->addWidget(VTable);
    horizontalLayot->addWidget(WTable);
/*
    VOpenPriceButton=new  QPushButton("Открыть прайс");
    VSyncPriceButton=new  QPushButton("Синхронизация");
    VParamDBButton=new  QPushButton("Параметры");
    VExitButton=new  QPushButton("Выход");
    horizontalLayot->addWidget(VOpenPriceButton);
    horizontalLayot->addWidget(VSyncPriceButton);
    horizontalLayot->addWidget(VParamDBButton);
    horizontalLayot->addWidget(VExitButton);
*/
    //создание вида вертикального размещения элементов
    verLayot= new QVBoxLayout();

    verLayot->addLayout(horizontalLayot);
    //verLayot->addWidget(VTable);


    VTable->setShowGrid(true);

    setLayout(verLayot);

}
