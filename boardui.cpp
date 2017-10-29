#include "boardui.h"


void BoardUI::drawCards(QPainter* painter,QSize size)
{

    int x=(size.width())/xfactor;
    int y=(size.height())/yfactor;
    for (int i = 0; i< NumOfCards; i++)
    {
        Card* tempCard = cardsUI[i]->getCard();
        QColor color;
        for(int j=0; j< gamePtr->getNumberOfPlayers(); j++)
        {
            Player* tempPlayer = gamePtr -> getPlayerPointer(j);
            if(tempPlayer->ownsCard(tempCard))
            {
                color=tempPlayer->getColor();
                break;
            }
            else color=Qt::white;
        }

        if(i<(NumOfCards/4)) cardsUI[i]->draw(painter,xspace+(i*x),yspace,x,y,tempCard,color);
        else if (i<(NumOfCards/2))    cardsUI[i]->draw(painter,xspace+((NumOfCards/4)*x),yspace+((i-(NumOfCards/4))*y),x,y,tempCard,color);

        else if (i<(NumOfCards/4)*3) cardsUI[i]->draw(painter,xspace+((NumOfCards/4)*x)-((i-(NumOfCards/2))*x),yspace+((NumOfCards/4)*y),x,y,tempCard,color);
        else if (i<NumOfCards) cardsUI[i]->draw(painter,xspace,(yspace+((NumOfCards/4)*y))-((i-(NumOfCards/4)*3)*y),x,y,tempCard,color);
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

        else if (index<(NumOfCards/4)*3) playersUI[i]->draw(painter,xspace+((NumOfCards/4)*x)-((index-(NumOfCards/2))*x),yspace+((NumOfCards/4)*y),x,y,tempPlayer);
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
