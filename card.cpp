#include "card.h"
#include<QString>
#include <QVector>


Card::Card (){

}
Card::Card(int nr, int price, int owner, QString colour)
{
this->NrCard=nr;
    this->Price=price;
    this->Owner=owner;
  this->Colour=colour;
}
int Card::getNrCard()
{
return this->NrCard;
}
void Card::setNrCard(int nr)
{
    this->NrCard=nr;
}
void Card::setPrice(int ck)
{
    this->Price=ck;
}
int Card::getPrice()
{
    return this->Price;
}
void Card::setOwner(int nrG)
{
    this->Owner=nrG;
}
int Card::getOwner()
{
    return this->Owner;
}

Card::~Card() {

}
