#include "card.h"
#include<QString>
Card::Card(QWidget* parent) :
    QWidget(parent)
{

}
<<<<<<< HEAD

Card::Card(int nr, int price, int owner, QString colour)
{
=======
//Card::Card(int nr, int price, int owner, QString colour)
//{
>>>>>>> d04be9c024a40fbcddf90432fd984ab10257bc12

//this->NrCard=nr;
//    this->Price=price;
//    this->Owner=owner;
//    this->Colour=colour;
//}
int Card::getNrCard()
{
return this->NrCard;
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
