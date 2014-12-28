#include "params.h"

params::params()
{

    param DestinationFolder_;
    DestinationFolder_.name="DestinationFolder";
    DestinationFolder_.printValue="Выберите папку исходную";
    DestinationFolder_.type="QLabel";
    listofparam.push_back(DestinationFolder_);

    param ResultFolder_;
    ResultFolder_.name="ResultFolder";
    ResultFolder_.printValue="Выберите конечную папку";
    ResultFolder_.type="QLabel";
    listofparam.push_back(ResultFolder_);


    param Folder_name_;
    Folder_name_.name="Folder_name";
    Folder_name_.printValue="Введите название папки";
    Folder_name_.type="QLineEdit";
    listofparam.push_back(Folder_name_);

    param createRawFolder_;
    createRawFolder_.name="createRawFolder";
    createRawFolder_.printValue="Cоздать подпапку для raw файлов";
    createRawFolder_.type="QCheckBox";
    listofparam.push_back(createRawFolder_);

    param SaveDestinationFolder_;
    SaveDestinationFolder_.name="SaveDestinationFolder";
    SaveDestinationFolder_.printValue="Сохранить оригинальные названия папок в подпапках";
    SaveDestinationFolder_.type="QCheckBox";
    listofparam.push_back(SaveDestinationFolder_);

    param GetSmallCopy_;
    GetSmallCopy_.name="GetSmallCopy";
    GetSmallCopy_.printValue="Создать уменьшенную копию";
    GetSmallCopy_.type="QCheckBox";
    listofparam.push_back(GetSmallCopy_);

    param KeapRaw_;
    KeapRaw_.name="KeapRaw";
    KeapRaw_.printValue="Сохранить raw";
    KeapRaw_.type="QCheckBox";
    listofparam.push_back(KeapRaw_);

    param KeapOriginal_;
    KeapOriginal_.name="KeapOriginal";
    KeapOriginal_.printValue="Сохранить оригинал";
    KeapOriginal_.type="QCheckBox";
    listofparam.push_back(KeapOriginal_);

    param SaveResizeInOwnFolder_;
    SaveResizeInOwnFolder_.name="SaveResizeInOwnFolder";
    SaveResizeInOwnFolder_.printValue="Сохранять уменьшенную копию в отдельную папку прикол";
    SaveResizeInOwnFolder_.type="QCheckBox";
   // listofparam.push_back(SaveResizeInOwnFolder_);


    setCreateRawFolder(false);
    setSaveDestinationFolder(false);
    setGetSmallCopy(false);
    setKeapRaw(false);
    setKeapOriginal(false);
    setSaveResizeInOwnFolder(false);





}
QString params::getDestinationFolder() const
{
    return DestinationFolder;
}

void params::setDestinationFolder(const QString &value)
{
    DestinationFolder = value;

}
QString params::getResultFolder() const
{
    return ResultFolder;
}

void params::setResultFolder(const QString &value)
{
    ResultFolder = value;

}
bool params::getCreateRawFolder() const
{
    return createRawFolder;
}

void params::setCreateRawFolder(bool value)
{
    createRawFolder = value;
}
bool params::getSaveDestinationFolder() const
{
    return SaveDestinationFolder;
}

void params::setSaveDestinationFolder(bool value)
{
    SaveDestinationFolder = value;
}
bool params::getGetSmallCopy() const
{
    return GetSmallCopy;
}

void params::setGetSmallCopy(bool value)
{
    GetSmallCopy = value;
}
bool params::getKeapRaw() const
{
    return KeapRaw;
}

void params::setKeapRaw(bool value)
{
    KeapRaw = value;
}
bool params::getKeapOriginal() const
{
    return KeapOriginal;
}

void params::setKeapOriginal(bool value)
{
    KeapOriginal = value;
}
bool params::getSaveResizeInOwnFolder() const
{
    return SaveResizeInOwnFolder;
}

void params::setSaveResizeInOwnFolder(bool value)
{
    SaveResizeInOwnFolder = value;
}

void params::SetParam(QString name, QString value)
{
    if (name== "DestinationFolder"){


        setDestinationFolder(value);
    }

    else if(name=="ResultFolder")
    {

        setResultFolder(value);

    }else if(name=="Folder_name")
    {

        setFolder_name(value);

    }else if(name=="createRawFolder")
    {


        if(value=="false")
        setCreateRawFolder(false);
        else setCreateRawFolder(true);

     }
    else if(name=="SaveDestinationFolder")
    {

        if(value=="false")
        setSaveDestinationFolder(false);
        else setSaveDestinationFolder(true);
     }
    else if(name=="GetSmallCopy")
    {

        if(value=="false")
        setGetSmallCopy(false);
        else setGetSmallCopy(true);
    }
    else if(name=="KeapRaw")
    {

        if(value=="false")
        setKeapRaw(false);
        else setKeapRaw(true);
    }
    else if (name=="KeapOriginal")
    {

        if(value=="false")
        setKeapOriginal(false);
        else setKeapOriginal(true);
    }
    else if(name=="SaveResizeInOwnFolder")
    {

        if(value=="false")
        setSaveResizeInOwnFolder(false);
        else setSaveResizeInOwnFolder(true);
     }



}
QVector<param> params::getListofparam() const
{
    return listofparam;
}
QString params::getFolder_name() const
{
    return Folder_name;
}

void params::setFolder_name(const QString &value)
{
    Folder_name = value;
}


void params::setListofparam(const QVector<param> &value)
{
    listofparam = value;
}


QString params::GetFolderParam(QString name)
{
    if (name== "DestinationFolder"){


        return DestinationFolder;
    }
    else if(name=="ResultFolder")
    {

        return ResultFolder;

    }



}






