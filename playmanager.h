#ifndef PLAYMANAGER_H
#define PLAYMANAGER_H

#include <QObject>
#include <QWidget>
#include "mainwindow.h"
#include "hellowwindow.h"
#include "winnerwindow.h"

class Playmanager: public QObject
{
    Q_OBJECT
public:
    Playmanager();
    void run();
    void onStart();
    void passMove();
    void connections();

    void onPassMoveToComputer();
    void onPassMoveToPerson();

public slots:
    void onFinish(QString winner);
    void onNewGame();
signals:
    void start();


private:
   MainWindow* game;
   HellowWindow* hellowWindow;
   WinnerWindow* winnerWindow;
};

#endif // PLAYMANAGER_H
