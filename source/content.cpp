#include "content.h"

Content::Content(QWidget *parent) :
    QWidget(parent)
{
    //
    VButtonGroup = new QGroupBox(tr("Параметры"));
    VButtonGroup->setFlat(false);

    VCreateRawFolder =new QCheckBox();
    VCreateRawFolder->setText("Cоздать подпапку для raw файлов");

    VSaveOriginalFolderNAme=new QCheckBox();
    VSaveOriginalFolderNAme->setText("Сохранить оригинальные названия папок в подпапках");

    verLayot= new QVBoxLayout();
    horizontalLayot =new QHBoxLayout();

    // создание вида горизонтального расположениея кнопок
    verLayot->addWidget(VCreateRawFolder);
    verLayot->addWidget(VSaveOriginalFolderNAme);
    verLayot->addStretch(1);

    VButtonGroup->setLayout(verLayot);

    //создание вида вертикального размещения элементов





    setLayout(VButtonGroup->layout());

}
