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
    void drawCards(QPainter *painter, QSize size);
    int NumOfCards=16;
    BoardUI(Board* ptrToBoard, Game *ptrToGame);
    const int xspace=10;
    const int yspace=50;
    const int xfactor=7;
    const int yfactor=6;

    ~BoardUI();
};

#endif // BOARDUI_H
