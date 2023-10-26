#include "hellowwindow.h"
#include "ui_hellowwindow.h"
#include "playmanager.h"
#include <QMessageBox>
#include <QDebug>

const QString kHellowWindowTitle = "Крестики-Нолики";

HellowWindow::HellowWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::HellowWindow)
{
    ui->setupUi(this);
    setWindowTitle(kHellowWindowTitle);
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &HellowWindow::onPushButtonStartClicked);
}

HellowWindow::~HellowWindow()
{
    delete ui;
}

QString HellowWindow::getPlayerName()
{
    return ui->lineEditName->text();
}

void HellowWindow::onPushButtonStartClicked()
{
    if(ui->radioButtonX->isChecked()==false && ui->radioButton0->isChecked()==false)
    {
        QMessageBox errorMessage;
        errorMessage.setText("Пожалуйста, сделайте выбор символа");
        errorMessage.exec();

    }
    if(ui->radioButtonX->isChecked()==true)
    {
        emit startGame(ui->radioButtonX->text());
        close();
    }
    if(ui->radioButton0->isChecked()==true)
    {
        emit startGame(ui->radioButton0->text());
        close();
    }
}
