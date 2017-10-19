#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"
class Game
{
public:
    Player *player;
    int Numofplayers=2;
    Board board;
    int Tura=0;
    int dicenum;
    Game();
    void Move();
    void End();
    void Buy();
    void Dice();
};

#endif // GAME_H
