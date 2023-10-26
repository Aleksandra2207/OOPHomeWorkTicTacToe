#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRandomGenerator>

const QString kPerson = "person";
const QString kComputer = "computer";
const QString kMainWindowTitle = "Крестики-Нолики";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(kMainWindowTitle);
    _pCells.append(ui->pushButton_1);
    _pCells.append(ui->pushButton_2);
    _pCells.append(ui->pushButton_3);
    _pCells.append(ui->pushButton_4);
    _pCells.append(ui->pushButton_5);
    _pCells.append(ui->pushButton_6);
    _pCells.append(ui->pushButton_7);
    _pCells.append(ui->pushButton_8);
    _pCells.append(ui->pushButton_9);
    connections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connections()
{
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::onPushButtonCliked);
    connect(ui->pushButtonResetPlay, &QPushButton::clicked, this, &MainWindow::onClickedReset);

}

void MainWindow::onPassComputerMove()
{
    onblokField(false);
    QPalette palette;
    palette.setColor(QPalette::Background,Qt::gray);
    ui->labelPlayer->setPalette(palette);
    palette.setColor(QPalette::Background,Qt::yellow);
    ui->labelComputer->setPalette(palette);
}

void MainWindow::onPassPersonMove()
{
    onblokField(true);
    QPalette palette;
    palette.setColor(QPalette::Background,Qt::yellow);
    ui->labelPlayer->setPalette(palette);
    palette.setColor(QPalette::Background,Qt::gray);
    ui->labelComputer->setPalette(palette);
}

void MainWindow::onPushButtonCliked()
{
    QObject* button = QObject::sender();
    bool isOk = false;
     if(button == ui->pushButton_1 && ui->pushButton_1->text().isEmpty())
     {
         ui->pushButton_1->setText(_signPlayer1);
         isOk = true;
     }
     if(button == ui->pushButton_2 && ui->pushButton_2->text().isEmpty())
     {
         ui->pushButton_2->setText(_signPlayer1);
          isOk = true;
     }
     if(button == ui->pushButton_3 && ui->pushButton_3->text().isEmpty())
     {
         ui->pushButton_3->setText(_signPlayer1);
          isOk = true;
     }
     if(button == ui->pushButton_4 && ui->pushButton_4->text().isEmpty())
     {
          ui->pushButton_4->setText(_signPlayer1);
         isOk = true;
     }
     if(button == ui->pushButton_5 && ui->pushButton_5->text().isEmpty())
     {
         ui->pushButton_5->setText(_signPlayer1);
         isOk = true;
     }
     if(button == ui->pushButton_6 && ui->pushButton_6->text().isEmpty())
     {
         ui->pushButton_6->setText(_signPlayer1);
         isOk = true;
     }
     if(button == ui->pushButton_7 && ui->pushButton_7->text().isEmpty())
     {
         ui->pushButton_7->setText(_signPlayer1);
         isOk = true;
     }
     if(button == ui->pushButton_8 && ui->pushButton_8->text().isEmpty())
     {
         ui->pushButton_8->setText(_signPlayer1);
         isOk = true;
     }
     if(button == ui->pushButton_9 && ui->pushButton_9->text().isEmpty())
     {
         ui->pushButton_9->setText(_signPlayer1);
         isOk = true;
     }
     if(isOk==true)
         emit doCheck(getField(), kPerson);
}

void MainWindow::onSetSingPlayer1(QString sign)
{
    _signPlayer1 = sign;
}

void MainWindow::onMakeComputerMove(int i, QString sign)
{
    _pCells.at(i)->setText(sign);
    emit doCheck(getField(), kComputer);
}

void MainWindow::setPlayerName(QString name)
{
    ui->labelPlayerName->setText(name);
}

void MainWindow::increaseCounterPerson()
{
    int ch = ui->spinBoxPlayer->value()+1;
    ui->spinBoxPlayer->setValue(ch);
}

void MainWindow::increaseCounterComputer()
{
    int ch = ui->spinBoxComputer->value()+1;
    ui->spinBoxComputer->setValue(ch);
}

void MainWindow::cleanField()
{
    foreach(QPushButton* cell, _pCells)
    {
        cell->setText("");
    }
}

QStringList MainWindow::getField()
{
    QStringList field;
    foreach(QPushButton* cell, _pCells)
    {
        field.append(cell->text());
    }
    return field;
}

void MainWindow::onblokField(bool isUnblok)
{
    foreach (QPushButton* cell, _pCells)
    {
        cell->setEnabled(isUnblok);
    }
}


void MainWindow::onClickedReset()
{
    emit newGame();
}
