#include "board.h"

Card *Board::getStartCard()
{
    return cards.first();
}

Board::Board()
{

    for (int i = 0; i< NumberOfCards; i++)
    {
        Card* card = new Card();
        cards.push_back(card);
    }



}
Board::~Board()
{

    for (int i = 0; i< 16; i++)
    {
        delete cards[i];
    }
}

Card *Board::getCard(int index)
{
    return cards.at(index);
}
Card *Board::calculateNewPosition(Player *player, int throwResult)
{
    Card* tempCard= player->getPosition();

    //finding position of tempCard in vector of cards

    int indexInVector =cards.indexOf(tempCard);
    int nextIndex = (indexInVector + throwResult) % NumberOfCards;
     return cards[nextIndex];
}
