#ifndef GRACZ_H
#define GRACZ_H
#include <QString>
#include "card.h"
#include <QVector>
#include <QObject>

class Player :
        public QObject
{
    Q_OBJECT
    int NrPlayer;
    int Cash;
    Card* currentPosition;
    QVector <Card*> ownedCards;
    QColor color;
    bool jail=false;
    bool auction;

public:
    Player();
    int getCash();
    Card* getPosition();
    void setColor(QColor color);
    QColor getColor();
    void setJail(bool jail);
    bool getJail();
    void setAuction(bool auction);
    bool getAuction();

    void setCash(int newAmount);
    void setPosition(Card* newPosition);

    bool ownsCard(Card* card);
    void removeCard(Card *card);
    void addCard(Card* card);

    ~Player();

signals:
    void DataChanged();


};

#endif // GRACZ_H
