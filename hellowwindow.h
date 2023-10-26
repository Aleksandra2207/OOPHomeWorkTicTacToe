#ifndef HELLOWWINDOW_H
#define HELLOWWINDOW_H

#include <QDialog>

namespace Ui {
class HellowWindow;
}

class HellowWindow : public QDialog
{
    Q_OBJECT

public:
    explicit HellowWindow(QDialog *parent = nullptr);
    ~HellowWindow();
    QString getPlayerName();

public slots:
    void onPushButtonStartClicked();

signals:
    void startGame(QString sign);

private:
    Ui::HellowWindow *ui;
};

#endif // HELLOWWINDOW_H
