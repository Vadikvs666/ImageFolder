#ifndef PARAMS_H
#define PARAMS_H
#include "QTextStream"
#include "QVector"

struct param
{
    QString name;
    QString type;
    QString printValue;
};

class params
{


public:
    params();
    QString getDestinationFolder() const;
    void setDestinationFolder(const QString &value);

    QString getResultFolder() const;
    void setResultFolder(const QString &value);

    bool getCreateRawFolder() const;


    bool getSaveDestinationFolder() const;


    bool getGetSmallCopy() const;


    bool getKeapRaw() const;


    bool getKeapOriginal() const;


    bool getSaveResizeInOwnFolder() const;


    void SetParam(QString name, QString value );
    QString GetFolderParam(QString name);


    QVector<param> getListofparam() const;





    QString getFolder_name() const;


    bool getCreateDayFolder() const;


private:
    QString DestinationFolder;
    QString Folder_name;
    QString ResultFolder;
    bool createRawFolder;
    bool createDayFolder;
    bool SaveDestinationFolder;
    bool GetSmallCopy;
    bool KeapRaw;
    bool KeapOriginal;
    bool SaveResizeInOwnFolder;
    QVector<param> listofparam;

    void setListofparam(const QVector<param> &value);
    void setCreateRawFolder(bool value);
    void setSaveDestinationFolder(bool value);
    void setGetSmallCopy(bool value);
    void setKeapRaw(bool value);
    void setKeapOriginal(bool value);
    void setSaveResizeInOwnFolder(bool value);
    void setFolder_name(const QString &value);
    void setCreateDayFolder(bool value);
};

#endif // PARAMS_H
