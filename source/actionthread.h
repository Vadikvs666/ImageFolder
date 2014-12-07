#ifndef ACTIONTHREAD_H
#define ACTIONTHREAD_H

#include <QThread>
#include "params.h"
#include <QDir>
#include <QFile>



class ActionThread : public QThread
{
    Q_OBJECT
public:
    explicit ActionThread(params *param,QObject *parent = 0);
    void run();

signals:
    void progress(int);
    void error(int);
    void sucsess();
    void message(QString msg);
    void log(QString txt);

public slots:
private:
    params *par;
    void action(params *p);

};





#endif // ACTIONTHREAD_H
