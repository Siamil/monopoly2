#include "boardui.h"


BoardUI::BoardUI(Board *ptrToBoard)
{
    boardPtr = ptrToBoard;
    x=120;
    y=120;

    for (int i = 0; i< 16; i++)
    {
     CardUI* card = new CardUI();
    cardsUI.push_back(card);

    }
    for (int i = 0; i< 16; i++){

    cardsUI[i]->setCard(boardPtr->getCard(i));
   // cardsUI[i]->setOwner();

    cardsUI[i]->setPixmap(QPixmap(":/new/jpg.jpg"));
    cardsUI[i]->setScaledContents(true);
    cardsUI[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    if(i<(NumOfCards/4)) cardsUI[i]->setGeometry(10+(i*x),50,x,y);
    else if (i<(NumOfCards/2)) cardsUI[i]->setGeometry(10+(4*x),50+((i-4)*y),x,y);
    else if (i<(NumOfCards/4)*3) cardsUI[i]->setGeometry(10+(4*x)-((i-8)*x),50+(4*y),x,y);
    else if (i<NumOfCards) cardsUI[i]->setGeometry(10,(50+(4*y))-((i-12)*y),x,y);

   }
//    PlayerUI* player1 = new PlayerUI();
//    PlayerUI* player2 = new PlayerUI();
//    player1->setPlayer(boardPtr->players[0]);

//    player1->setPosition();
//    player2->setPlayer(boardPtr->players[1]);

   // player2->setPosition();
   // player1->setText("player1");
   // player2->setText("player2");
}
BoardUI::~BoardUI()
{

}
