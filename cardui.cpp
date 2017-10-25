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
//void CardUI::setOwner()
//{
//    this->Owner->setText(QString::number(card->getOwner()));
//}


void CardUI::RefreshUI()
{


}
CardUI::~CardUI()

{

}
