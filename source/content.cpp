#include "content.h"

Content::Content(QWidget *parent) :
    QWidget(parent)
{
    //
    VGroup1 = new QGroupBox(tr("Параметры"));




    VCreateRawFolder =new QCheckBox();
    VCreateRawFolder->setText("Cоздать подпапку для raw файлов");

    VSaveOriginalFolderNAme=new QCheckBox();
    VSaveOriginalFolderNAme->setText("Сохранить оригинальные названия папок в подпапках");

    verLayot1= new QVBoxLayout();



    // создание вида горизонтального расположениея кнопок
    verLayot1->addWidget(VCreateRawFolder);
    verLayot1->addWidget(VSaveOriginalFolderNAme);
    verLayot1->addStretch(1);




    VGroup1->setLayout(verLayot1);

     VGroup2 = new QGroupBox(tr("Папки"));

     DestLabel=new QLabel("выберите папку исходную");
     ResultLabel=new QLabel("выберите папку конечную");

     verLayot2= new QVBoxLayout();
     verLayot2->addWidget(DestLabel);
     verLayot2->addWidget(ResultLabel);
     VGroup2->setLayout(verLayot2);

    horizontalLayot =new QHBoxLayout();
    horizontalLayot->addWidget(VGroup1);
    horizontalLayot->addWidget(VGroup2);


    setLayout(horizontalLayot);

}
