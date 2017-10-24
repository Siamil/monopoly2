#include "player.h"
#include "card.h"
#include <QVector>





Player::Player(int num, int cash, int poz )
{
this->NrPlayer=num;
this->Cash=cash;
this->Position=poz;
 this->OwnedCards =new QVector<Card>();
}
Player::Player()
{

}
void Player::DataChanged()
{

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
    emit DataChanged();
}
void Player::setPosition(int pozz)
{
this->Position=pozz;
   emit DataChanged();
}
void Player::setNrPlayer(int nr)
{
    this->NrPlayer=nr;
    emit DataChanged();
}

Player::~Player()
{

}
