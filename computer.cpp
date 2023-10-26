#include "computer.h"
#include <QRandomGenerator>

Computer::Computer()
{
}

void Computer::setSign(QString sign)
{
    _mySign = sign;
}

void Computer::makeMove(QStringList field)
{
    //ищем свободные клетки
     QList <int> emptyCells = findCurrectCell(field);
     //выбираем рандомную пустую клетку чтобы заполнить ее
     if(emptyCells.isEmpty())
         return;
     if(emptyCells.length()==1)
     {
         emit finishMove(emptyCells.at(0), _mySign);
         return;
     }
     int i = QRandomGenerator::global()->bounded(emptyCells.length()-1);
     //заполняем клетку символом и передаем ход человеку
     emit finishMove(emptyCells.at(i), _mySign);
}

QList <int> Computer::findCurrectCell(QStringList field )
{
  QList <int> emplyCells;
  for(int i=0; i<field.length();i++)
  {
      if (field.at(i).isEmpty() == true)
         emplyCells.append(i);
  }
   return emplyCells;
}
