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

    //void computerMove();
    void setPlayerName(QString name);
    void increaseCounterPerson();
    void increaseCounterComputer();
    void cleanField();
    QStringList getField();


public slots:
    void onPassComputerMove();
    void onPassPersonMove();
    void onPushButtonCliked();
    void onSetSingPlayer1(QString sign);
    void onMakeComputerMove (int i, QString sign);
    void onblokField(bool isUnblok);
    void onClickedReset();

signals:
    void doCheck(QStringList field, QString player);
    void newGame();


private:
    Ui::MainWindow *ui;
    QList <QPushButton*> _pCells;
    QString _signPlayer1;
    void connections();

};
#endif // MAINWINDOW_H
