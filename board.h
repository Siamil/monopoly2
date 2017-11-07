#ifndef BOARD_H
#define BOARD_H
#include "card.h"
#include <QVector>
#include <player.h>
#include "configreader.h"

class Board
{
    QVector<Card*> cards;
    int NumberOfCards;
public:    
    Card* getStartCard();
    Board(ConfigReader *configReader);
    ~Board();
    int getNumberOfCards();
    Card* getCard(int index);


    Card* calculateNewPosition(Player* player, int throwResult);
};

#endif // BOARD_H
