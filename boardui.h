#ifndef BOARDUI_H
#define BOARDUI_H
#include <QLabel>
#include <QVector>
#include "cardui.h"
#include <QBoxLayout>
#include <board.h>
#include "playerui.h"
#include "game.h"


class BoardUI : public QLabel
{
public:
    QVector<CardUI*> cardsUI;
    Game * gamePtr;
    Board * boardPtr;
    QVector<PlayerUI*> playersUI;

    int NumOfCards=16;
    BoardUI(Board* ptrToBoard, Game *ptrToGame);
    int x,y;

    ~BoardUI();
};

#endif // BOARDUI_H
