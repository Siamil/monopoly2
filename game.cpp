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

        player->setCash(playerCash);
        player->setPosition(board.getStartCard());
        playerPointers.push_back(player);
    }
    if(numberOfPlayers>=1) playerPointers[0]->setColor(Qt::blue);
    if(numberOfPlayers>=2) playerPointers[1]->setColor(Qt::darkGreen);
    if(numberOfPlayers>=3) playerPointers[2]->setColor(Qt::darkRed);
    if(numberOfPlayers>=4) playerPointers[3]->setColor(Qt::yellow);
    if(numberOfPlayers>=5) playerPointers[4]->setColor(Qt::white);
    if(numberOfPlayers>=6) playerPointers[5]->setColor(Qt::black);
    if(numberOfPlayers>=7) playerPointers[6]->setColor(Qt::gray);
    if(numberOfPlayers>=8) playerPointers[7]->setColor(Qt::darkCyan);

    currentPlayer = playerPointers.first();
}

void Game::MovePlayer()

{
    int throwResult = ThrowDice();
    currentPlayer->setPosition(board.calculateNewPosition(currentPlayer,throwResult));

    Card* newPosition = currentPlayer->getPosition();

    // Let's check whether the card is taken or not.
    Player* owner = getCardOwner(newPosition);
    if (!(owner ==  NULL || owner == currentPlayer)) {

        int payment = newPosition->calculatePayment();
        transferMoney(currentPlayer, owner, payment);
        emit statement("Gracz "+ whosTurn() + " zaplacil za nocleg!");
    }


    Card::CardType tempType= newPosition->getType();
    if(tempType==Card::Jail)
    {
        currentPlayer->setJail(true);
    }
    else if(tempType==Card::Tax)
    {
        payBank(currentPlayer, 200);
        emit statement("Gracz "+ whosTurn() + " zaplacil podatek!");
    }
    else if(tempType==Card::Bonus)
    {
        receiveFromBank(currentPlayer, 200);
        emit statement("Gracz "+ whosTurn() + " otrzymal pieniadze!");
    }
    isPlayerDone();
}

void Game::EndPlayerTurn()
{
    int currentPlayerIndex = playerPointers.indexOf(currentPlayer);
    int nextOne = (currentPlayerIndex + 1) % numberOfPlayers;
    emit statement("Gracz "+ whosTurn() + " zakonczyl ture!");
    currentPlayer = playerPointers[nextOne];

}


void Game::BuyProperty()
{
    Card* playerPosition = currentPlayer->getPosition();
    playerPosition->setBuyable(false);
    int price = playerPosition->getPrice();
    currentPlayer->addCard(playerPosition);
    payBank(currentPlayer, price);
    emit statement("Gracz "+ whosTurn() + " kupil pole!");
}

void Game::BuyHouse()
{
    Card* playerPosition = currentPlayer->getPosition();
    int price = (playerPosition->getPrice())/2;
    int houses = playerPosition->getHouses();
    playerPosition->setHouses(houses + 1);
    payBank(currentPlayer, price);
    emit statement("Gracz "+ whosTurn() + " kupil domek!");
}

bool Game::CanBuyHouse()
{

    Card* position = currentPlayer->getPosition();
    if(position->getHouses() >= 4 || currentPlayer->getCash() < ((position->getPrice())/2) ) return false;
    for (int i = 0; i < board.getNumberOfCards(); i++)
    {
        if (board.getCard(i)->getColor()== position->getColor())
        {
            if(!(currentPlayer->ownsCard(board.getCard(i))))
            {
                return false;
            }

        }
    }
    return true;
}

bool Game::CanBuyProperty()
{
    Card* position = currentPlayer->getPosition();
    Card::CardType type = position->getType();
    int price = position->getPrice();
    int cash = currentPlayer->getCash();
    if(currentPlayer->getPosition()->getBuyable() ==true && type == Card::Property && price <= cash ) return true;
    else return false;
}

void Game::Auction()
{
    tradeCard = currentPlayer->getPosition();
    setAuctionPrice(tradeCard->getPrice());
    for (int i=0; i< numberOfPlayers; i++)
    {
        playerPointers[i]->setAuction(true);
    }

}

void Game::setAuctionPrice(int auctionprice)
{
    this->auctionPrice = auctionprice;
    emit DataChanged();
}

int Game::getAuctionPrice()
{
    return auctionPrice;
}

void Game::EndAuction()
{
    int aucPlayers=0;
    int index;
    for (int i=0; i < numberOfPlayers; i++)
    {
        if(playerPointers[i]->getAuction() == true)
        {
            aucPlayers++;
            index=i;
        }
    }
    if(aucPlayers==1 ){
        if(auctionPrice > tradeCard->getPrice())
        {
            tradeCard ->setBuyable(false);
            int price = auctionPrice;
            playerPointers[index]->addCard(tradeCard);
            payBank(playerPointers[index], price);
            for(int j=0; j < numberOfPlayers; j++)
            {
                if(playerPointers[j]->getPosition() == tradeCard)
                    currentPlayer = playerPointers[j];
            }
            emit auctionEnd();
        }
        else EndPlayerTurn();
    } else EndPlayerTurn();
    if(aucPlayers == 0)
    {
        for(int j=0; j < numberOfPlayers; j++)
        {
            if(playerPointers[j]->getPosition() == tradeCard)
                currentPlayer = playerPointers[j];
        }
        emit auctionEnd();
    }
}
QString Game::whosTurn()
{
    QColor color = currentPlayer->getColor();
    if(color==Qt::blue) return "blue";
    if(color==Qt::darkGreen) return "darkGreen";
    if(color==Qt::darkRed) return "darkRed";
    if(color==Qt::yellow) return "yellow";
    if(color==Qt::white) return "white";
    if(color==Qt::black) return "black";
    if(color==Qt::gray) return "gray";
    if(color==Qt::darkCyan) return "darkCyan";
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

void Game::setNumberOfPlayers(int numberofplayers)
{
    numberOfPlayers=numberofplayers;
}

void Game::isPlayerDone()
{
    if(currentPlayer->getCash()<=0)
    {
        setNumberOfPlayers(getNumberOfPlayers() - 1);
        playerPointers.remove(playerPointers.indexOf(currentPlayer));
        delete currentPlayer;


    }
}



Game::~Game()
{

}

int Game::ThrowDice()
{
    srand( time( NULL ) );
    int throwResult = rand() % DiceMaxNumber + 1;
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


