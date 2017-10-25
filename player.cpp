#include "player.h"
#include "card.h"
#include <QVector>




Player::Player()
{

}
void Player::DataChanged()
{

}


int Player::getCash()
{
return this->Cash;
}
Card *Player::getPosition()
{
return this->currentPosition;
}
void Player::setCash(int newAmount)
{
this->Cash=newAmount;
    emit DataChanged();
}
void Player::setPosition(Card *newPosition)
{
    currentPosition=newPosition;
    emit DataChanged();
}

bool Player::ownsCard(Card *card)
{
    int index = ownedCards.indexOf(card);
    bool doIHaveIt = index >= 0;
    return doIHaveIt;
}

void Player::addCard(Card *card)
{
    ownedCards.push_back(card);
}


Player::~Player()
{

}
