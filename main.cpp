#include "mainwindow.h"
#include "hellowwindow.h"
#include "playmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Playmanager playManager;
    HellowWindow hellowWindow;
    playManager.run();
    return a.exec();
}
