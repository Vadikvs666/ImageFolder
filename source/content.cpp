#include "content.h"


Content::Content(QWidget *parent) :
    QWidget(parent)
{
    //
    VGroup1 = new QGroupBox(tr("Параметры"));

    Param=new params();



    verLayot1= new QVBoxLayout();
    verLayot2= new QVBoxLayout();
    for(int i=0; i<Param->getListofparam().length(); i++ )
    {
        param tec_name=Param->getListofparam()[i];
        if(tec_name.type=="QCheckBox")
        {
            QCheckBox *Checkparam =new QCheckBox();
            Checkparam->setText(tec_name.printValue);
            Checkparam->setObjectName(tec_name.name);
            verLayot1->addWidget(Checkparam);
            connect(Checkparam,SIGNAL(stateChanged(int)),this,SLOT(SetParamCheckBox(int)));

        }
        if(tec_name.type=="QLineEdit")
        {
            QLineEdit *LineEdit =new QLineEdit();
            LineEdit->setText(tec_name.printValue);
            LineEdit->setObjectName(tec_name.name);

            verLayot1->addWidget(LineEdit);
            connect(LineEdit,SIGNAL(textChanged(QString)),this,SLOT(SetTextEdit(QString)));

        }
        if(tec_name.type=="QLabel")
        {
            QLabel *Labelparam=new QLabel();
            Labelparam->setText(tec_name.printValue);
            Labelparam->setObjectName(tec_name.name);
           // connect(Param,SIGNAL(FolderChange(QString)),this,SLOT(SetLabelName(QString)));
            verLayot2->addWidget(Labelparam);


        }

    }


    verLayot1->addStretch(1);




    VGroup1->setLayout(verLayot1);

     VGroup2 = new QGroupBox(tr("Папки"));

     VGroup2->setLayout(verLayot2);

    horizontalLayot =new QHBoxLayout();
    horizontalLayot->addWidget(VGroup1);
    horizontalLayot->addWidget(VGroup2);


    setLayout(horizontalLayot);

}

void Content::SetParamCheckBox(int value)
{
   QString par=sender()->objectName() ;
   if(value==0)
   {
       Param->SetParam(par,"false");
   } else Param->SetParam(par,"true");
}

void Content::SetTextEdit(QString value)
{
    QString par=sender()->objectName() ;

        Param->SetParam(par,value);

}

void Content::SetLabelName(QString value )
{



}
