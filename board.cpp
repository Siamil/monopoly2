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
        card->setPrice(400+i*25);
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
    cards[10]->setColor(Qt::gray);
    cards[11]->setColor(Qt::gray);
    cards[13]->setColor(Qt::gray);
    cards[14]->setColor(Qt::yellow);
    cards[15]->setColor(Qt::yellow);
    cards[16]->setType(Card::Tax);
    cards[17]->setColor(Qt::yellow);
    cards[18]->setColor(Qt::darkGray);
    cards[19]->setColor(Qt::darkGray);
    cards[20]->setType(Card::Bonus);
    cards[21]->setColor(Qt::darkGray);
    cards[22]->setColor(Qt::green);
    cards[23]->setType(Card::Jail);
    cards[24]->setColor(Qt::green);
    cards[25]->setType(Card::Bonus);
    cards[26]->setColor(Qt::green);
    cards[27]->setType(Card::Tax);


}
Board::~Board()
{

    for (int i = 0; i< NumberOfCards; i++)
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
    if((indexInVector + throwResult) > NumberOfCards) player->setCash(player->getCash()+300);
    int nextIndex = (indexInVector + throwResult) % NumberOfCards;
    return cards[nextIndex];
}
