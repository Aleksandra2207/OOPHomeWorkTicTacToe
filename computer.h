#ifndef COMPUTER_H
#define COMPUTER_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class Computer: public QObject
{
    Q_OBJECT
public:
    Computer();
    void setSign(QString sign);
    void makeMove (QStringList field);
signals:
    void finishMove(int cell, QString sign);

private:
    QString _mySign;
    QList <int> findCurrectCell(QStringList field);

};

#endif // COMPUTER_H
