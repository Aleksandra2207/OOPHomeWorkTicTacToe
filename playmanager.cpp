#include "playmanager.h"
const QString kPersonWin = "Поздравляем! Вы победили";
const QString kComputerWin = "Увы, вы проиграли";
const QString kDraw = "Ничья";


Playmanager::Playmanager()
{
    hellowWindow = new HellowWindow;
    game = new MainWindow;
    winnerWindow = new WinnerWindow;
    connections();
}

void Playmanager::run()
{
    hellowWindow->show();
}

void Playmanager::onStart()
{
    game->setPlayerName(hellowWindow->getPlayerName());
    game->show();
    emit start();
}

void Playmanager::connections()
{
    connect(this, &Playmanager::start, game, &MainWindow::onStart);
    connect(hellowWindow, &HellowWindow::startGame, this, &Playmanager::onStart);
    connect(game, &MainWindow::personMoveIsComplited, this, &Playmanager::onPassMoveToComputer);
    connect (game, &MainWindow::emit computerMoveIsComplited, this, &Playmanager::onPassMoveToPerson);
    connect (game, &MainWindow::finish, this, &Playmanager::onFinish);
    connect(winnerWindow, &WinnerWindow::newNewGame, this, &Playmanager::onNewGame);
    connect(game, &MainWindow::newGame, this, &Playmanager::onNewGame);
}

void Playmanager::onPassMoveToComputer()
{
    game->passComputerMove();
    game->computerMove();
}

void Playmanager::onPassMoveToPerson()
{
    game->passPersonMove();
}

void Playmanager::onFinish(QString winner)
{
    if(winner == "0")
    {
        winnerWindow->setLabelwinner(kComputerWin);
        game->increaseCounterComputer();
    }
    if(winner == "X")
    {
        winnerWindow->setLabelwinner(kPersonWin);
         game->increaseCounterPerson();
    }
    if(winner == "draw")
        winnerWindow->setLabelwinner(kDraw);
    winnerWindow->show();
}

void Playmanager::onNewGame()
{
    game->cleanField();
    game->onStart();
}
