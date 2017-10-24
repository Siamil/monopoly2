#ifndef GRACZ_H
#define GRACZ_H
#include <QString>
#include "card.h"
#include <QVector>
#include <QObject>
using namespace std;
class Player :QObject
{

    int NrPlayer;
public:
    int Cash;
    int Position=0;
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
    signals:
    void DataChanged();

~Player();
};

#endif // GRACZ_H
