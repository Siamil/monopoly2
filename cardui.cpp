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



void CardUI::draw(QPainter *painter, int x, int y, int w, int h, Card *card)
{

    QFont font=painter->font() ;

    if(card->getType()==Card:: Property)

    {
        font.setPointSize (8);
        painter->setFont(font);
        QRect rec(x,y,w,h);
        QRect recprice(x+(w/5),y+(h/3),(w/5)*3,h/6);
        QRect uprec(x+(w/5),y+(h/9),(w/5)*3,h/6);
        QBrush fillbrush;
        QBrush whitebrush;
        whitebrush.setColor(Qt::white);
        whitebrush.setStyle(Qt::SolidPattern);
        painter->fillRect(rec,whitebrush);

        fillbrush.setColor(card->getColor());
        fillbrush.setStyle(Qt::SolidPattern);
        QPen framepen(Qt::black);
        framepen.setWidth(4);
        painter->setPen(framepen);
        painter->drawRect(rec);

        painter->drawRect(uprec);
        painter->fillRect(uprec,fillbrush);
        painter->drawRect(recprice);
        framepen.setColor(Qt::black);
        painter->setPen(framepen);
        painter->drawText(recprice,Qt::AlignCenter,"Price:" + QString::number(card->getPrice())+"$");

    }
    else if(card->getType()==Card:: Jail)
    {
        QRect rec(x,y,w,h);
        QBrush fillbrush;
        QBrush whitebrush;
        whitebrush.setColor(Qt::white);
        whitebrush.setStyle(Qt::SolidPattern);
        painter->fillRect(rec,whitebrush);

        font.setPointSize ( 18);
        painter->setFont(font);
        fillbrush.setColor(Qt::blue);
        fillbrush.setStyle(Qt::CrossPattern);
        QPen framepen(Qt::black);
        framepen.setWidth(4);
        painter->setPen(framepen);

        painter->drawRect(rec);
        painter->drawText(rec,Qt::AlignCenter,"JAIL");



        painter->fillRect(rec,fillbrush);
    }
    else if(card->getType()==Card:: Tax)
    {
        QRect rec(x,y,w,h);
        QBrush fillbrush;
        fillbrush.setColor(Qt::green);
        font.setPointSize ( 15);
        painter->setFont(font);
        QBrush whitebrush;
        whitebrush.setColor(Qt::green);
        whitebrush.setStyle(Qt::SolidPattern);
        painter->fillRect(rec,whitebrush);
        QPen framepen(Qt::black);
        framepen.setWidth(4);
        painter->setPen(framepen);
        painter->drawRect(rec);
        painter->drawText(rec,Qt::AlignCenter,"Pay Tax");
        painter->drawText(rec,Qt::AlignBottom,"200$");


    }
    else if(card->getType()==Card:: Bonus)
    {
        QRect rec(x,y,w,h);
        QBrush fillbrush;
        fillbrush.setColor(Qt::red);
        font.setPointSize ( 15);
        QBrush whitebrush;
        whitebrush.setColor(Qt::yellow);
        whitebrush.setStyle(Qt::SolidPattern);
        painter->fillRect(rec,whitebrush);
        painter->setFont(font);
        QPen framepen(Qt::black);
        framepen.setWidth(4);
        painter->setPen(framepen);
        painter->drawRect(rec);
        painter->drawText(rec,Qt::AlignCenter,"Bonus");
        painter->drawText(rec,Qt::AlignBottom,"200$");

    }
    else if(card->getType()==Card::Start)
    {
        QRect rec(x,y,w,h);
        QBrush fillbrush;
        fillbrush.setColor(Qt::red);
        font.setPointSize ( 15);
        QBrush whitebrush;
        whitebrush.setColor(Qt::blue);
        whitebrush.setStyle(Qt::SolidPattern);
        painter->fillRect(rec,whitebrush);
        painter->setFont(font);
        QPen framepen(Qt::black);
        framepen.setWidth(4);
        painter->setPen(framepen);
        painter->drawRect(rec);
        painter->drawText(rec,Qt::AlignCenter,"START");
        painter->drawText(rec,Qt::AlignBottom,"HAVE FUN");
    }

}



void CardUI::RefreshUI()
{


}
CardUI::~CardUI()

{

}
