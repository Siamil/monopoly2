#ifndef BOARD_H
#define BOARD_H
#include "card.h"
#include <QVector>
#include <player.h>

class Board
{
public:
    QVector<Card*> cards;
    QVector<Player*> players;

    int Numofplayers=2;
    Board();
    ~Board();
};

#endif // BOARD_H
