#include "game.h"
#include "board.h"
Game::Game()
{
    int iloscGraczy=2;
    player = new Player[Numofplayers];
    player[0].setCash(1000);
    player[0].setPosition(0);
    player[0].setNrPlayer(0);

    player[1].setCash(1000);
    player[1].setPosition(0);
    player[1].setNrPlayer(1);
    Board board;
}
void Game::Move()

{
    player[Tura].setPosition(player[Tura].getPosition()+dicenum);
    if(player[Tura].getPosition()>39) player[Tura].setPosition(player[Tura].getPosition()-38);

    if(board.cards[player[Tura].getPosition()]->Owner!=(Tura) && board.cards[player[Tura].getPosition()]->Owner!=(9))
    {
            player[Tura].setCash(player[Tura].getCash()- (board.cards[player[Tura].getPosition()]->getPrice()/10));
            player[board.cards[player[Tura].getPosition()]->Owner].setCash(player[board.cards[player[Tura].getPosition()]->Owner].getCash()+ ((board.cards[player[Tura].getPosition()]->getPrice())/10));
}
}
void Game::End()
{
    if(Tura<Numofplayers-1){
        Tura++;
    }
    else Tura=0;
}
void Game::Buy()

{
    board.cards[player[Tura].getPosition()]->setBuyable(false);
    board.cards[player[Tura].getPosition()]->setOwner(Tura);
    player[Tura].setCash(player[Tura].getCash() - board.cards[player[Tura].getPosition()]->Price);
}
void Game::Dice()
{
    dicenum = rand() % 6 +1;
}
Game::~Game()
{

}
