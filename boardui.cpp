#include "boardui.h"


BoardUI::BoardUI()
{

    for (int i = 0; i< 40; i++)
    {
     cardUI* card = new cardUI();
    cardsUI.push_back(card);

    }
    cardsUI[0]->setCard(Board.cards[0]);
}
BoardUI::~BoardUI()
{

}
