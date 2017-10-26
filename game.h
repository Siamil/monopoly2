#ifndef GAME_H
#define GAME_H
#include "board.h"


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
    Game(int numberOfPlayers);

    void MovePlayer();
    void EndPlayerTurn();
    void BuyProperty();
    void Dice();

    Player* getPlayerPointer(int index);
    Board* getBoardPtr();
    int getNumberOfPlayers();




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
