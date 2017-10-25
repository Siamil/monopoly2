#ifndef GAME_H
#define GAME_H
#include "board.h"


class Game
{
    Board board;
    QVector<Player*> playerPointers;
    Player* currentPlayer;

    const int DiceMaxNumber = 6;

public:
    Game(int numberOfPlayers);

    void MovePlayer();
    void EndPlayerTurn();
    void BuyProperty();
    void Dice();


    ~Game();

private:
    int ThrowDice();
};

#endif // GAME_H
