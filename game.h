#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "time.h"


class Game : QObject
{
    Q_OBJECT
    Board board;
    QVector<Player*> playerPointers;
    Player* currentPlayer;
    int numberOfPlayers=4;

    const int DiceMaxNumber = 6;

public:

    Game();
    Game(int _numberOfPlayers);

    void MovePlayer();
    void EndPlayerTurn();
    void BuyProperty();
    void BuyHouse();
    bool CanBuyHouse();
    bool CanBuyProperty();
    void Dice();
    Player *getCurrentPlayer();
    Player* getPlayerPointer(int index);
    Board* getBoardPtr();
    int getNumberOfPlayers();
    void setNumberOfPlayers(int numberofplayers);
    void isPlayerDone();




    ~Game();

signals:
    void newDiceThrow(int);
private:
    int ThrowDice();
    Player* getCardOwner(Card* card);
    void transferMoney(Player* sender, Player* receiver, int amount);
    void payBank(Player* player, int amount);
    void receiveFromBank(Player* player, int amount);
};

#endif // GAME_H
