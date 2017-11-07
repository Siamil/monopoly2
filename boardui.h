#ifndef BOARDUI_H
#define BOARDUI_H
#include <QLabel>
#include <QVector>
#include "cardui.h"
#include <QBoxLayout>
#include <board.h>
#include "playerui.h"
#include "game.h"
#include "configreader.h"


class BoardUI : public QLabel
{
public:
    QVector<CardUI*> cardsUI;
    Game * gamePtr;
    Board * boardPtr;

    QVector<PlayerUI*> playersUI;
    void drawCards(QPainter *painter, QSize size);
    void drawPlayers(QPainter *painter, QSize size);
    int NumOfCards;
    BoardUI(Board* ptrToBoard, Game *ptrToGame, ConfigReader *configReader );
     int xspace=10;
     int yspace=50;
     int xfactor=11;
     int yfactor=9;

    ~BoardUI();
};

#endif // BOARDUI_H
