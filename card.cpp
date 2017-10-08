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
void Card::setBuyable(bool by)
{
    this->Buyable=by;
}
bool Card::getBuyable()
{
    return this->Buyable;
}
void Card::setColour(QString col)
{
    this->Colour=col;
}
void Card::setType(QString type)
{
    this->Type=type;
}
QString Card::getColour()
{
    return this->Colour;
}
QString Card::getType()
{
    return this->Type;
}

Card::~Card() {

}
