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
    QVector<cardUI*> cardsUI;
    BoardUI();

    ~BoardUI();
};

#endif // BOARDUI_H
