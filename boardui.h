#ifndef BOARDUI_H
#define BOARDUI_H
#include <QLabel>
#include <QVector>
#include "cardui.h"
#include <QBoxLayout>
#include <board.h>



class BoardUI : public QLabel
{
public:
    QVector<CardUI*> cardsUI;
    Board * boardPtr;
    BoardUI(Board* ptrToBoard);
    int x,y;

    ~BoardUI();
};

#endif // BOARDUI_H
