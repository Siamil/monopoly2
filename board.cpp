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
        card->setType(Card::Property);
        card->setPrice(200+i*50);
        card->setNrCard(i);
        cards.push_back(card);
    }
    cards[0]->setType(Card::Start);
    cards[8]->setType(Card::Jail);
    cards[12]->setType(Card::Bonus);
    cards[1]->setColor(Qt::cyan);

    cards[2]->setColor(Qt::cyan);
    cards[3]->setType(Card::Tax);
    cards[4]->setColor(Qt::cyan);
    cards[5]->setColor(Qt::red);
    cards[6]->setType(Card::Tax);
    cards[7]->setColor(Qt::red);
    cards[9]->setColor(Qt::red);
    cards[10]->setColor(Qt::yellow);
    cards[11]->setColor(Qt::yellow);
    cards[13]->setColor(Qt::yellow);
    cards[14]->setColor(Qt::green);
    cards[15]->setColor(Qt::green);


}
Board::~Board()
{

    for (int i = 0; i< 16; i++)
    {
        delete cards[i];
    }
}

int Board::getNumberOfCards()
{
    return NumberOfCards;
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
