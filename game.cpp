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
    switch( numberOfPlayers )
    {
    case 2:
        playerPointers[0]->setColor(Qt::blue);
        playerPointers[1]->setColor(Qt::green);
        break;

    case 3:
        playerPointers[0]->setColor(Qt::blue);
        playerPointers[1]->setColor(Qt::green);
        playerPointers[2]->setColor(Qt::red);
        break;


    case 4:
        playerPointers[0]->setColor(Qt::blue);
        playerPointers[1]->setColor(Qt::green);
        playerPointers[2]->setColor(Qt::red);
        playerPointers[3]->setColor(Qt::yellow);
        break;
    case 5:
        playerPointers[0]->setColor(Qt::blue);
        playerPointers[1]->setColor(Qt::green);
        playerPointers[2]->setColor(Qt::red);
        playerPointers[3]->setColor(Qt::yellow);
        playerPointers[4]->setColor(Qt::white);
    case 6:
        playerPointers[0]->setColor(Qt::blue);
        playerPointers[1]->setColor(Qt::green);
        playerPointers[2]->setColor(Qt::red);
        playerPointers[3]->setColor(Qt::yellow);
        playerPointers[4]->setColor(Qt::white);
        playerPointers[5]->setColor(Qt::black);
    case 7:
        playerPointers[0]->setColor(Qt::blue);
        playerPointers[1]->setColor(Qt::green);
        playerPointers[2]->setColor(Qt::red);
        playerPointers[3]->setColor(Qt::yellow);
        playerPointers[4]->setColor(Qt::white);
        playerPointers[5]->setColor(Qt::black);
        playerPointers[6]->setColor(Qt::gray);
    case 8:
        playerPointers[0]->setColor(Qt::blue);
        playerPointers[1]->setColor(Qt::green);
        playerPointers[2]->setColor(Qt::red);
        playerPointers[3]->setColor(Qt::yellow);
        playerPointers[4]->setColor(Qt::white);
        playerPointers[5]->setColor(Qt::black);
        playerPointers[6]->setColor(Qt::gray);
        playerPointers[7]->setColor(Qt::darkYellow);


        break;
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

Player *Game::getCurrentPlayer()
{
    return currentPlayer;
}

Player *Game::getPlayerPointer(int index)
{
    return playerPointers.at(index);
}

Board *Game::getBoardPtr()
{
    return &board;
}

int Game::getNumberOfPlayers()
{
    return numberOfPlayers;
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


