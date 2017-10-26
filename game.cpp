#include "game.h"
#include "board.h"

Game::Game()
{

}

Game::Game(int _numberOfPlayers)
    : numberOfPlayers(_numberOfPlayers)
{

    for (int i = 0; i < numberOfPlayers; ++i)
    {
        Player* player = new Player();

        player->setCash(1000);
        player->setPosition(board.getStartCard());
        playerPointers.push_back(player);
    }

    currentPlayer = playerPointers.first();
}

void Game::MovePlayer()

{
    int throwResult = ThrowDice();
    currentPlayer->setPosition(board.calculateNewPosition(currentPlayer,throwResult));

    Card* newPosition = currentPlayer->getPosition();

    // Let's check whether the card is taken or not.
    Player* owner = getCardOwner(newPosition);

    if (owner ==  NULL) {
        // We can buy it
    } else if (owner == currentPlayer) {
        // We can build on it
    } else {
        // Sadly we need to pay rent
        int payment = newPosition->calculatePayment();
        transferMoney(currentPlayer, owner, payment);
    }
}

void Game::EndPlayerTurn()
{
   int currentPlayerIndex = playerPointers.indexOf(currentPlayer);
   int nextOne = (currentPlayerIndex + 1) % numberOfPlayers;

   currentPlayer = playerPointers[nextOne];
}


void Game::BuyProperty()
{
    Card* playerPosition = currentPlayer->getPosition();
    int price = playerPosition->getPrice();
    currentPlayer->addCard(playerPosition);
    payBank(currentPlayer, price);
}

Board *Game::getBoardPtr()
{
    return &board;
}

Game::~Game()
{

}

int Game::ThrowDice()
{
    int throwResult = rand() % DiceMaxNumber +1;
    emit newDiceThrow( throwResult);
    return throwResult;

}

Player *Game::getCardOwner(Card *card)
{
    for (int i = 0; i < playerPointers.size(); i++) {
        Player* player = playerPointers[i];


        if (player->ownsCard(card)) return player;
    }

    return NULL;
}

void Game::transferMoney(Player *sender, Player* receiver, int amount)
{
    sender->setCash(sender->getCash() - amount);
    receiver->setCash(receiver->getCash() + amount);
}

void Game::payBank(Player *player, int amount)
{
    player->setCash(player->getCash() - amount);
}

void Game::receiveFromBank(Player *player, int amount)
{
    player->setCash(player->getCash() + amount);
}


