#ifndef PLAYERUI_H
#define PLAYERUI_H
#include <QLabel>
#include "player.h"
#include "cardui.h"

class PlayerUI : public QLabel
{
public:
    Q_OBJECT
    Player *player;
    CardUI *card;
public:
    PlayerUI();
    void setPosition(Card *newPosition);
    void setPlayer(Player *player);
    void draw(QPainter *painter, int x, int y, int w, int h, Player *player);
    public slots:
    void RefreshUI();
};

#endif // PLAYERUI_H
