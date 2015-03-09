#include "actionthread.h"



#include "QDate"

#include <QImage>
#include <QDir>

#include "qimagemetadata//QImageMetaData.h"


QString IntToStr(int s)
{
    QVariant temp=s;
    return temp.toString();
}


bool checkFolder(QString Dir)
{
    QDir dir(Dir);
    return QFile::exists(Dir);
}



 QStringList GetDatebyExif(QString filename)
{
    QStringList list;
    QImageMetaData* metadata = new QImageMetaData();



    if (!metadata->read(filename)) {
        QString  msg=metadata->errorMessage();
        list << "Error";


    } else {
        QString  datetime=metadata->dateAndTimeOriginal();


       list = datetime.split(":");
       QString day=list[2];
       QStringList temp=day.split(" ");
       list[2]=temp[0];

        }

    delete(metadata);
    return list;
}

bool CreateFolderByDate(QString dir )
{

    QDir path(dir);
    if(!checkFolder(dir))
    {
        return path.mkpath(dir);
    }else return true;
}






ActionThread::ActionThread(params *param, QObject *parent)
{
    par=param;
}

void ActionThread::run()
{
    emit log("Запущена синхронизация...");
    emit log("Исходная папка :"+ par->getDestinationFolder());
    emit log("Конечная папка :"+ par->getResultFolder());
    action(par);
    emit message("Операция успешно завершена!!!");
}

void ActionThread::action(params *p)
{
    QString Dest=p->getDestinationFolder();
    QString Folder_name=p->getFolder_name();
    bool creatRaw=p->getCreateRawFolder();
    bool saveOrgFaleName=p->getSaveDestinationFolder();
    bool smalCopy=p->getGetSmallCopy();
    bool keapOriginal=p->getKeapOriginal();
    bool keapRaw=p->getKeapRaw();
    bool dayFolder=p->getCreateDayFolder();
    QString Result=p->getResultFolder();
    QDir dir(Dest);
    dir.setFilter(QDir::Files |  QDir::NoSymLinks);
    dir.setSorting(QDir::Size);
    QFileInfoList list = dir.entryInfoList();
    emit log("Текущая папка :" + Dest);
    for (int i = 0; i < list.size(); ++i)
    {
         QFileInfo fileInfo = list.at(i);
       QString filename=Dest+"/"+fileInfo.fileName();
         emit log("Текущий файл :" + filename);
         if(fileInfo.suffix().toLower()=="jpg"||fileInfo.suffix().toLower()=="jpg"||fileInfo.suffix().toLower()=="nef"||fileInfo.suffix().toLower()=="png")
         {




             QStringList d= GetDatebyExif(filename);
             QString resfilename;
             QString year ;
             QString month ;
             QString day ;
             emit log("Получение exif файла " + filename);
             if(d[0]!="Error")
             {
                  if(d.length()>=2)
                  {
                          year =d[0];
                         month =d[1];
                         day =d[2];
                   }
                  else
                  {
                      QDateTime date =fileInfo.created();

                      year =IntToStr(date.date().year());
                      QString month_t=IntToStr(date.date().month());
                      if(month_t=="10"||month_t=="11"||month_t=="12")
                      {
                            month=month_t;
                      }else month="0"+month_t;
                      day=IntToStr(date.date().day());
                  }

             }
             else
             {
                 QDateTime date =fileInfo.created();
                 year =IntToStr(date.date().year());
                 QString month_t=IntToStr(date.date().month());
                 if(month_t=="10"||month_t=="11"||month_t=="12")
                 {
                       month=month_t;
                 }else month="0"+month_t;
                 day=IntToStr(date.date().day());

             }
             QString resDir=Result+"/"+year+"/"+month;
             if(dayFolder)
             {
                 resDir=resDir+"/"+day;

             }
             emit message("Выполняется операция с файлом : "+filename);
                 if(saveOrgFaleName)
                 {
                     QStringList path=Dest.split("/");
                     QString saved=path.last();

                     resDir=resDir+"/"+saved+"/";
                 }
                 else
                 {
                     if(Folder_name=="Введите название папки для конечной папки"||Folder_name=="")
                     {
                        ;
                     }
                     else resDir=resDir+"/"+Folder_name+"/";
                 }
                 if(creatRaw)
                 {
                     if(fileInfo.suffix()=="nef"||fileInfo.suffix()=="NEF")
                     {
                         resDir=resDir+"RAW/";
                     }
                 }
                 if(smalCopy)
                 {
                     if(fileInfo.suffix().toLower()!="nef")
                     {



                         QString tempdir;
                         if(keapOriginal)
                         {
                              tempdir=resDir+"resize/";
                         }else  tempdir=resDir;
                         if(CreateFolderByDate(tempdir ))
                         {
                             if(!checkFolder(tempdir+fileInfo.fileName()))
                             {
                                 emit log("Ресайз изображения :" + filename);
                                 QImage img(filename);

                                 img.scaledToWidth(1920,Qt::FastTransformation);
                                 img.save(tempdir+fileInfo.fileName(),0,70);
                             }
                         }
                         resDir=resDir+"original/";
                     }


                 }
                 if(keapOriginal)
                 {
                     if(CreateFolderByDate(resDir ))
                     {


                         resfilename=resDir+fileInfo.fileName();
                         /*  QMessageBox::information(NULL, "Все в порядке",resfilename
                                            );*/
                         emit log("копирование изображения :" + filename);
                         QFile::copy(filename,resfilename);

                     }
                 }

         }


    }
     dir.setFilter(QDir::AllDirs|  QDir::NoDotAndDotDot);
     QFileInfoList list2 = dir.entryInfoList();
     for (int i = 0; i < list2.size(); ++i)
     {
          QFileInfo fileInfo = list2.at(i);
          par->setDestinationFolder(Dest+"/"+fileInfo.fileName());
          action(par);
     }
}
