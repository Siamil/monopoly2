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

Card *CardUI::getCard()
{
    return card;
}



void CardUI::draw(QPainter *painter, int x, int y, int w, int h, QColor color)
{

    QRect rec(x,y,w,h);
    QBrush fillbrush;
    fillbrush.setColor(color);
    fillbrush.setStyle(Qt::SolidPattern);
    QPen framepen(color);
    painter->setPen(framepen);
    painter->drawRect(rec);
    QRect uprec(x+(w/5),y+(h/5),(w/5)*3,h/4);
    painter->drawRect(uprec);
    painter->fillRect(uprec,fillbrush);
}



void CardUI::RefreshUI()
{


}
CardUI::~CardUI()

{

}
