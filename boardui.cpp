#include "boardui.h"


void BoardUI::drawCards(QPainter* painter,QSize size)
{

    int x=(size.width())/xfactor;
    int y=(size.height())/yfactor;
    for (int i = 0; i< NumOfCards; i++)
    {
        Card* tempCard = cardsUI[i]->getCard();
        // QColor tempColor= cardsUI[i]->getCard()->getColor();
        // Card::CardType tempType= cardsUI[i]->getCard()->getType();
        if(i<(NumOfCards/4)) cardsUI[i]->draw(painter,xspace+(i*x),yspace,x,y,tempCard);
        else if (i<(NumOfCards/2))    cardsUI[i]->draw(painter,xspace+((NumOfCards/4)*x),yspace+((i-(NumOfCards/4))*y),x,y,tempCard);

        else if (i<(NumOfCards/4)*3) cardsUI[i]->draw(painter,xspace+((NumOfCards/4)*x)-((i-(NumOfCards/2))*x),yspace+((NumOfCards/4)*y),x,y,tempCard);
        else if (i<NumOfCards) cardsUI[i]->draw(painter,xspace,(yspace+((NumOfCards/4)*y))-((i-(NumOfCards/4)*3)*y),x,y,tempCard);
    }
}

void BoardUI::drawPlayers(QPainter *painter, QSize size)
{
    int x=(size.width()) / xfactor;
    int y=(size.height()) / yfactor;
    for (int i = 0; i < gamePtr ->getNumberOfPlayers(); i++)
    {
        Player* tempPlayer = gamePtr -> getPlayerPointer(i);
        int index = tempPlayer -> getPosition() -> getNrCard();

        if(index<(NumOfCards/4)) playersUI[i]->draw(painter,xspace+(index*x),yspace,x,y,tempPlayer);
        else if (index<(NumOfCards/2))    playersUI[i]->draw(painter,xspace+((NumOfCards/4)*x),yspace+((index-(NumOfCards/4))*y),x,y,tempPlayer);

        else if (index<(NumOfCards/4)*3) playersUI[i]->draw(painter,xspace+((NumOfCards/4)*x)-((i-(NumOfCards/2))*x),yspace+((NumOfCards/4)*y),x,y,tempPlayer);
        else if (index<NumOfCards) playersUI[i]->draw(painter,xspace,(yspace+((NumOfCards/4)*y))-((index-(NumOfCards/4)*3)*y),x,y,tempPlayer);
    }
}

BoardUI::BoardUI(Board *ptrToBoard, Game *ptrToGame)
{
    boardPtr = ptrToBoard;
    gamePtr = ptrToGame;


    for (int i = 0; i< 16; i++)
    {
        CardUI* card = new CardUI();
        cardsUI.push_back(card);

    }
    for (int i = 0; i< 16; i++){

        cardsUI[i]->setCard(boardPtr->getCard(i));
        // cardsUI[i]->setOwner();

        // cardsUI[i]->setPixmap(QPixmap(":/new/jpg.jpg"));
        // cardsUI[i]->setScaledContents(true);
        //cardsUI[i]->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        //    if(i<(NumOfCards/4)) cardsUI[i]->setGeometry(10+(i*x),50,x,y);
        //    else if (i<(NumOfCards/2)) cardsUI[i]->setGeometry(10+(4*x),50+((i-4)*y),x,y);
        //    else if (i<(NumOfCards/4)*3) cardsUI[i]->setGeometry(10+(4*x)-((i-8)*x),50+(4*y),x,y);
        //    else if (i<NumOfCards) cardsUI[i]->setGeometry(10,(50+(4*y))-((i-12)*y),x,y);

    }
    for (int i=0; i<gamePtr->getNumberOfPlayers();++i)
    {
        PlayerUI* playerUI = new PlayerUI();
        playerUI->setPlayer(gamePtr->getPlayerPointer(i));
        playerUI->setPosition(ptrToBoard->getStartCard());
        playersUI.push_back(playerUI);

    }

}
BoardUI::~BoardUI()
{

}
