#include "playerui.h"
#include <iostream>

PlayerUI::PlayerUI()
{

}
void PlayerUI::setPlayer(Player *player)
{
    this->player=player;
}

void PlayerUI::setPosition()
{
    this->card=&(card[player->Position]);
    //int y= card->y();

    //this->setGeometry(card->normalGeometry());

}
void PlayerUI::RefreshUI()
{
    this->setPosition();
}
