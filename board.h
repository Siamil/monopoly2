#ifndef BOARD_H
#define BOARD_H
#include "card.h"
#include <QVector>
#include <player.h>

class Board
{
    QVector<Card*> cards;
public:    
    Board();
    ~Board();
};

#endif // BOARD_H
