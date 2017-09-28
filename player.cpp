#include "player.h"
#include "card.h"
#include <QVector>





Player::Player(int num, int cash, int poz )
{
this->NrPlayer=num;
this->Cash=cash;
this->Position=poz;
    //this->OwnedCards =new QVector<Card>();
}
int Player::getNrPlayer()
{
return this->NrPlayer;
}
int Player::getCash()
{
return this->Cash;
}
int Player::getPosition()
{
return this->Position;
}
void Player::setCash(int il)
{
this->Cash=il;
}
void Player::setPosition(int pozz)
{
this->Position=pozz;
}
void Player::buy(Card card)
{
//OwnedCards->push_back(card);
this->setCash(this->getCash()-card.Price);
card.setOwner(NrPlayer);
}
void Player::sell()
{

}
void Player::zastaw()
{

}
