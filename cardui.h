#ifndef CARDUI_H
#define CARDUI_H
#include <QLabel>
#include "card.h"

class CardUI : public QLabel
{
public:
    Q_OBJECT
    Card *card;
    QLabel *Owner;
    int NrCard;
public:
    CardUI(QWidget *parent);
    CardUI();
    void setCard(Card *cardd);
    void setImage(QString file);
    void setOwner();
    void setNrcard();
    ~CardUI();
 public slots:
   void RefreshUI();
};

#endif // CARDUI_H
