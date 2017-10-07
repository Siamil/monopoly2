#ifndef GRACZ_H
#define GRACZ_H
#include <QString>
#include "card.h"
#include <QVector>
using namespace std;
class Player
{

    int NrPlayer;
public:
    int Cash;
    int Position;
    QVector <Card> *OwnedCards;



public:
   Player();
   Player(int num, int cash=0, int poz=0 );
    int getNrPlayer();
    int getCash();
    int getPosition();
    void setCash(int il);
    void setPosition(int pozz);
    void setNrPlayer(int nr);
    void buy(Card card);
    void sell();
    void zastaw();

};

#endif // GRACZ_H
