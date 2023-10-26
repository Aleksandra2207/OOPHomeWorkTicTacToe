#include "winnerwindow.h"
#include "ui_winnerwindow.h"
#include <QDebug>

const QString kWinnerWindowTitle = "Крестики-Нолики";

WinnerWindow::WinnerWindow(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::WinnerWindow)
{
    ui->setupUi(this);
    setWindowTitle(kWinnerWindowTitle);
    connect(ui->pushButtonNewGame, &QPushButton::clicked, this, &WinnerWindow::onClickedPushButtonNewGame);
}

WinnerWindow::~WinnerWindow()
{
    delete ui;
}

void WinnerWindow::setLabelwinner(QString winner)
{
    ui->labelNameWinner->setText(winner);
}

void WinnerWindow::onClickedPushButtonNewGame()
{
    emit newNewGame();
    close();
}
