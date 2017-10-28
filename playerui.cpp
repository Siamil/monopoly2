#include "playerui.h"
#include <iostream>

PlayerUI::PlayerUI()
{

}
void PlayerUI::setPlayer(Player *player)
{
    this->player=player;
}

void PlayerUI::draw(QPainter *painter, int x, int y, int w, int h, Player *player)
{
    if(player->getColor()==Qt::red)
    {
    QFont font=painter->font() ;
    font.setPointSize (12);
    painter->setFont(font);
    QRect rec(x + (w/5), y + (h/5)*3, w/8, h/8);

    QPen framepen(Qt::black);
    QBrush fillpen(player->getColor());


    painter->setBrush(fillpen);
    painter->drawEllipse(rec);
    painter->setPen(framepen);
    painter->drawEllipse(rec);

}
    else if(player->getColor()==Qt::blue)
    {
    QFont font=painter->font() ;
    font.setPointSize (12);
    painter->setFont(font);
    QRect rec(x + (w/5)*3, y + (h/5)*4, w/8, h/8);

    QPen framepen(Qt::black);
    QBrush fillpen(player->getColor());


    painter->setBrush(fillpen);
    painter->drawEllipse(rec);
    painter->setPen(framepen);
    painter->drawEllipse(rec);

}
    else if(player->getColor()==Qt::green)
    {
    QFont font=painter->font() ;
    font.setPointSize (12);
    painter->setFont(font);
    QRect rec(x + (w/5)*3, y + (h/5)*3, w/8, h/8);
    QPen framepen(Qt::black);
    QBrush fillpen(player->getColor());


    painter->setBrush(fillpen);
    painter->drawEllipse(rec);
    painter->setPen(framepen);
    painter->drawEllipse(rec);
}
    else if(player->getColor()==Qt::yellow)
    {
    QFont font=painter->font() ;
    font.setPointSize (12);
    painter->setFont(font);
    QRect rec(x + (w/5), y + (h/5)*4, w/8, h/8);
    QPen framepen(Qt::black);
    QBrush fillpen(player->getColor());


    painter->setBrush(fillpen);
    painter->drawEllipse(rec);
    painter->setPen(framepen);
    painter->drawEllipse(rec);

}
}

void PlayerUI::setPosition(Card *newPosition)
{
   // QRect tmpGeo = newPosition->normalGeometry();
  //  this->card=&(card[player->Position]);
//    //int y= card->y();

//
//    this->setGeometry(tmpGeo);
}
void PlayerUI::RefreshUI()
{
    //this->draw();
}
