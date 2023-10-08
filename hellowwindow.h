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
    QPushButton* onGetPushButtonStart();
    void onPushButtonStartClicked();

private slots:
signals:
    void startGame();

private:
    Ui::HellowWindow *ui;
};

#endif // HELLOWWINDOW_H
