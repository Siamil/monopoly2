#ifndef CARDUI_H
#define CARDUI_H
#include <QLabel>
#include "card.h"
#include <QtCore>
#include <QPainter>

class CardUI : public QLabel
{
public:
    Q_OBJECT
    Card *card;
    QLabel *Owner;
public:
    int NrCard;
public:
    CardUI(QWidget *parent);
    CardUI();
    void setCard(Card *cardd);
    Card* getCard();
    void draw(QPainter *painter, int x, int y, int w, int h, Card *card, QColor color, int houses);

    ~CardUI();
public slots:
    void RefreshUI();
};

#endif // CARDUI_H
