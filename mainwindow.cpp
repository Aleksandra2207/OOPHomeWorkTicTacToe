#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QRandomGenerator>

const int countCell=9;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    _countNoEmptyCell = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connections()
{
    connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::onTic1);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onTic2);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onTic3);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onTic4);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onTic5);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::onTic6);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::onTic7);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::onTic8);
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::onTic9);
    connect(ui->pushButtonResetPlay, &QPushButton::clicked, this, &MainWindow::onClickedReset);

}

void MainWindow::passComputerMove()
{
    onblokField(false);
    QPalette palette;
    palette.setColor(QPalette::Background,Qt::gray);
    ui->labelPlayer->setPalette(palette);
    palette.setColor(QPalette::Background,Qt::yellow);
    ui->labelComputer->setPalette(palette);
}

void MainWindow::passPersonMove()
{
    onblokField(true);
    QPalette palette;
    palette.setColor(QPalette::Background,Qt::yellow);
    ui->labelPlayer->setPalette(palette);
    palette.setColor(QPalette::Background,Qt::gray);
    ui->labelComputer->setPalette(palette);
}

void MainWindow::computerMove()
{
    //ищем свободные клетки
     QList <QPushButton*> emptyCells = findCurrectCell();
     //выбиаем рандомную пустую клетку чтобы заполнить ее
     if(emptyCells.isEmpty())
         return;
     int i = QRandomGenerator::global()->bounded(emptyCells.length()-1);
    //заполняем клетку 0 и передаем ход человеку
    emptyCells.at(i)->setText("0");
    _countNoEmptyCell++;
    if (onCheckForFinish("0") || onCheckForFinish("X"))
            return;
    emit computerMoveIsComplited();

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

void MainWindow::onblokField(bool isUnblok)
{
    foreach (QPushButton* cell, _pCells)
    {
        cell->setEnabled(isUnblok);
    }
}

bool MainWindow::onCheckForFinish(QString value)
{
    int ch=0;
    for (int i=0; i<=6;)
    {
        int j=i+1, k=i+2;
        if(_pCells.at(i)->text() == value && _pCells.at(j)->text()== value && _pCells.at(k)->text() == value)
        {
            ch++;
            emit finish(value);
            return true;
        }
        i+=3;
    }
    for (int i=0; i<=2; i++)
    {
        int j=i+3, k=i+6;
        if(_pCells.at(i)->text() == value && _pCells.at(j)->text()== value && _pCells.at(k)->text() == value)
        {
            ch++;
            emit finish(value);
            return true;
        }
    }
    if(_pCells.at(0)->text() == value && _pCells.at(4)->text()== value && _pCells.at(8)->text() == value)
    {
        ch++;
        emit finish(value);
        return true;
    }
    if(_pCells.at(2)->text() == value && _pCells.at(4)->text()== value && _pCells.at(6)->text() == value)
    {
        ch++;
        emit finish(value);
        return true;
    }
    if(ch==0 && _countNoEmptyCell == countCell)
    {
        _ch--;
    }
    if(_ch==0 && _countNoEmptyCell == countCell)
    {
        emit finish ("draw");
        return true;
    }
        return false;
}

void MainWindow::onClickedReset()
{
    emit newGame();
}

QList <QPushButton*> MainWindow::findCurrectCell()
{
   QList <QPushButton*> emplyCells;
   foreach(QPushButton* cell, _pCells)
   {
       if (cell->text().isEmpty() == true)
          emplyCells.append(cell);
   }
   return emplyCells;
}

void MainWindow::onStart()
{
   _countNoEmptyCell = 0;
    QPalette palette;
   palette.setColor(QPalette::Background,Qt::yellow);
   ui->labelPlayer->setPalette(palette);
   palette.setColor(QPalette::Background,Qt::gray);
   ui->labelComputer->setPalette(palette);
   onblokField(true);
}

void MainWindow::onTic1()
{
    ui->pushButton_1->setText("X");
    _countNoEmptyCell++;
    if (onCheckForFinish("0") || onCheckForFinish("X"))
            return;
    emit personMoveIsComplited();

}
void MainWindow::onTic2()
{
    ui->pushButton_2->setText("X");
    _countNoEmptyCell++;
    if (onCheckForFinish("0") || onCheckForFinish("X"))
            return;
    emit personMoveIsComplited();

}
void MainWindow::onTic3()
{
    ui->pushButton_3->setText("X");
    _countNoEmptyCell++;
     if (onCheckForFinish("0") || onCheckForFinish("X"))
             return;

    emit personMoveIsComplited();

}
void MainWindow::onTic4()
{
    ui->pushButton_4->setText("X");
    _countNoEmptyCell++;
    if (onCheckForFinish("0") || onCheckForFinish("X"))
            return;

    emit personMoveIsComplited();

}
void MainWindow::onTic5()
{
    ui->pushButton_5->setText("X");
    _countNoEmptyCell++;
    if (onCheckForFinish("0") || onCheckForFinish("X"))
            return;

    emit personMoveIsComplited();

}
void MainWindow::onTic6()
{
    ui->pushButton_6->setText("X");
    _countNoEmptyCell++;
     if (onCheckForFinish("0") || onCheckForFinish("X"))
             return;

    emit personMoveIsComplited();

}
void MainWindow::onTic7()
{
    ui->pushButton_7->setText("X");
    _countNoEmptyCell++;
     if (onCheckForFinish("0") || onCheckForFinish("X"))
             return;

    emit personMoveIsComplited();

}

void MainWindow::onTic8()
{
    ui->pushButton_8->setText("X");
    _countNoEmptyCell++;
    if (onCheckForFinish("0") || onCheckForFinish("X"))
            return;

    emit personMoveIsComplited();

}
void MainWindow::onTic9()
{
    ui->pushButton_9->setText("X");
    _countNoEmptyCell++;
    if (onCheckForFinish("0") || onCheckForFinish("X"))
            return;
    emit personMoveIsComplited();
}
