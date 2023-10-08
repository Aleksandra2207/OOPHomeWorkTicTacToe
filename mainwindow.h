#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void passComputerMove();
    void passPersonMove();
    void computerMove();
    void setPlayerName(QString name);
    void increaseCounterPerson();
    void increaseCounterComputer();
    void cleanField();


public slots:
    void onStart();
    void onTic1();
    void onTic2();
    void onTic3();
    void onTic4();
    void onTic5();
    void onTic6();
    void onTic7();
    void onTic8();
    void onTic9();
    void onblokField(bool isUnblok);
    bool onCheckForFinish(QString value);
    void onClickedReset();

signals:
    void personMoveIsComplited();
    void computerMoveIsComplited();
    void newGame();
    void finish(QString winner);


private:
    Ui::MainWindow *ui;
    QList <QPushButton*> _pCells;
    int _countNoEmptyCell;

    void connections();
    QList <QPushButton*> findCurrectCell();
    int _ch=2;
};
#endif // MAINWINDOW_H
