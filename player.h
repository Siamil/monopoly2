#ifndef GRACZ_H
#define GRACZ_H
#include <QString>
#include "card.h"
#include <QVector>
#include <QObject>

class Player :
        QObject
{
    int NrPlayer;
    int Cash;
    Card* currentPosition;
    QVector <Card> *ownedCards;

public:
   Player();
   Player(int num, int cash=0, int poz=0 );

    int getCash();
    Card* getPosition();

    void setCash(int newAmount);
    void setPosition(Card* newPosition);

    ~Player();

    signals:
    void DataChanged();


};

#endif // GRACZ_H
