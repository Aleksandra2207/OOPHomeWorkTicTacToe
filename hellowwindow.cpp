#include "hellowwindow.h"
#include "ui_hellowwindow.h"
#include "playmanager.h"

HellowWindow::HellowWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::HellowWindow)
{
    ui->setupUi(this);
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

QPushButton* HellowWindow::onGetPushButtonStart()
{
    return ui->pushButtonStart;
}

void HellowWindow::onPushButtonStartClicked()
{
    emit startGame();
    close();
}
