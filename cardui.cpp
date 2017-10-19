#include "cardui.h"

cardUI::cardUI()
{

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
