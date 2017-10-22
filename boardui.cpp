#include "boardui.h"


BoardUI::BoardUI(Board *ptrToBoard)
{
    boardPtr = ptrToBoard;
    x=100;
    y=120;
    for (int i = 0; i< 16; i++)
    {
     CardUI* card = new CardUI();
    cardsUI.push_back(card);

    }
    for (int i = 0; i< 16; i++){

    cardsUI[i]->setCard(boardPtr->cards[i]);
    //cardsUI[i]->setOwner();
    cardsUI[i]->setNrcard();

    cardsUI[i]->setPixmap(QPixmap(":/new/jpg.jpg"));
    cardsUI[i]->setScaledContents(true);
    cardsUI[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
    if(i<4) cardsUI[i]->setGeometry(10+(i*x),50,x,y);
    else if (i<8) cardsUI[i]->setGeometry(10+(4*x),50+((i-4)*y),x,y);
    else if (i<12) cardsUI[i]->setGeometry(10+(4*x)-((i-8)*x),50+(4*y),x,y);
    else if (i<16) cardsUI[i]->setGeometry(10,(50+(4*y))-((i-12)*y),x,y);

   }
}
BoardUI::~BoardUI()
{

}
