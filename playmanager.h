#ifndef PLAYMANAGER_H
#define PLAYMANAGER_H

#include <QObject>
#include <QWidget>
#include "mainwindow.h"
#include "hellowwindow.h"
#include "winnerwindow.h"
#include "computer.h"



class Playmanager: public QObject
{
    Q_OBJECT
public:
    Playmanager();
    void run();
    void onStart(QString playerSign);
    void connections();
    bool checkForFinish(QString value, QStringList field);
    void onPassMoveToComputer();
    void onPassMoveToPerson();

public slots:
    void onFinish(QString winner);
    void onNewGame();
    void onCheckForFinish(QStringList cells, QString player);

signals:
    void computerMove();
    void personMove();
    void finish(QString winner);
    void personMoveIsComplited();
    void computerMoveIsComplited();


private:
   MainWindow* game;
   HellowWindow* hellowWindow;
   WinnerWindow* winnerWindow;
   Computer* computer;
   int _ch=2;
   int _countNoEmptyCell=0;
   QString _personSign;
   QString _computerSign;

   void delay();
};

#endif // PLAYMANAGER_H
