#ifndef BOARD_H
#define BOARD_H
#include "card.h"
#include <QVector>

class Board
{
public:
    QVector<Card*> cards;
    Board();
    ~Board();
};

#endif // BOARD_H
