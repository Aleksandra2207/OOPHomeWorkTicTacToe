#ifndef WINNERWINDOW_H
#define WINNERWINDOW_H

#include <QDialog>

namespace Ui {
class WinnerWindow;
}

class WinnerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WinnerWindow(QDialog *parent = nullptr);
    ~WinnerWindow();
    void setLabelwinner(QString winner);

public slots:
    void onClickedPushButtonNewGame();

signals:
    void newNewGame();

private:
    Ui::WinnerWindow *ui;
};

#endif // WINNERWINDOW_H
