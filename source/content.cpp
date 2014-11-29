#include "content.h"

Content::Content(QWidget *parent) :
    QWidget(parent)
{
    //
    VCreateRawFolder =new QCheckBox();

    VCreateRawFolder->setText("создать подпапку для raw файлов");
    verLayot= new QVBoxLayout();
    VButtonGroup = new QGroupBox();
    VButtonGroup->setTitle("Параметры");
    horizontalLayot =new QHBoxLayout();

    // создание вида горизонтального расположениея кнопок
    verLayot->addWidget(VCreateRawFolder);

    VButtonGroup->setLayout(verLayot);

    //создание вида вертикального размещения элементов





    setLayout(VButtonGroup->layout());

}
