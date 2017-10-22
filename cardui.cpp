#include "cardui.h"

CardUI::CardUI (QWidget *parent)
        : QLabel(parent)
{}

CardUI::CardUI()
{

}
void CardUI::setCard(Card *cardd)
{
    this->card=cardd;
}
void CardUI::setImage(QString file)
{
    this->setText(file);
}
void CardUI::setOwner()
{

    this->Owner->setText(QString::number(card->getOwner()));
}
void CardUI::setNrcard()
{
    this->NrCard=card->getNrCard();
}


void CardUI::RefreshUI()
{
this->setOwner();

}
CardUI::~CardUI()

{

}
