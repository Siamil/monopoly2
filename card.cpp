#include "card.h"
#include<QString>
#include <QVector>


Card::Card (){

}


void Card::setPrice(int price)
{
    this->price=price;
}
int Card::getPrice()
{
    return price;
}

void Card::setBuyable(bool isBuyable)
{
    this->buyable=isBuyable;
}
bool Card::getBuyable()
{
    return this->buyable;
}
void Card::setColor(QColor col)
{
    this->color=col;
}
void Card::setType(CardType type)
{
    this->type=type;
}

int Card::calculatePayment()
{
    // TODO. Vary the payment based on number of houses/hotels.
    // For now just take 1/10. houses and hotels are gonna be implemented later

    int payment = price / 10;
    return payment;
}

QColor Card::getColor()
{
    return color;
}

Card::CardType Card::getType()
{
    return type;
}
Card::~Card() {

}
