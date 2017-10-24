#ifndef BOARDUI_H
#define BOARDUI_H
#include <QLabel>
#include <QVector>
#include "cardui.h"
#include <QBoxLayout>
#include <board.h>
#include "playerui.h"


class BoardUI : public QLabel
{
public:
    QVector<CardUI*> cardsUI;

    Board * boardPtr;
    PlayerUI *player1;
    PlayerUI *player2;
    int NumOfCards=16;
    BoardUI(Board* ptrToBoard);
    int x,y;

    ~BoardUI();
};

#endif // BOARDUI_H
