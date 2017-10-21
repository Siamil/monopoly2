#include "cardui.h"

cardUI::cardUI (QWidget *parent)
        : QLabel(parent)
{}

cardUI::cardUI()
{

}
void cardUI::setCard(Card *cardd)
{
    this->card=cardd;
}
void cardUI::setImage(QString file)
{
    this->setText(file);
}
void cardUI::setOwner()
{
    this->Owner->setText(QString::number(card->getOwner()));
}
void cardUI::setNrcard()
{
    this->NrCard=card->getNrCard();
}


void cardUI::RefreshUI()
{
this->setOwner();

}
cardUI::~cardUI()

{

}
