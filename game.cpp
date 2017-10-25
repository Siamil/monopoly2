#include "game.h"
#include "board.h"
Game::Game(int numberOfPlayers)
{
    for (int i = 0; i < numberOfPlayers; ++i)
        playerPointers.push_back(new Player());
}


void Game::Move()

{


    board.players[Tura]->setPosition(board.players[Tura]->getPosition()+dicenum);
    if(board.players[Tura]->getPosition()>15) board.players[Tura]->setPosition(board.players[Tura]->getPosition()-14);

    int tempplayerowner=board.cards[board.players[Tura]->getPosition()]->Owner;
    int tempcardprice=board.cards[board.players[Tura]->getPosition()]->getPrice();

    if(tempplayerowner!=(Tura) && board.cards[board.players[Tura]->getPosition()]->Owner!=(9))
    {
            board.players[Tura]->setCash(board.players[Tura]->getCash()- (tempcardprice/10));
            board.players[tempplayerowner]->setCash(board.players[tempplayerowner]->getCash()+((tempcardprice)/10));
}
}
void Game::End()
{
    if(Tura<board.Numofplayers-1){
        Tura++;
    }
    else Tura=0;
}
void Game::Buy()
{
    board.cards[board.players[Tura]->getPosition()]->setBuyable(false);
    board.cards[board.players[Tura]->getPosition()]->setOwner(Tura);
    board.players[Tura]->setCash(board.players[Tura]->getCash() - board.cards[board.players[Tura]->getPosition()]->Price);
}


void Game::Dice()
{
    dicenum =
}
Game::~Game()
{

}

int Game::ThrowDice()
{
    return rand() % DiceMaxNumber +1;
}
