#ifndef CARDUI_H
#define CARDUI_H
#include <QLabel>
#include "card.h"

class cardUI : public QLabel
{
public:
    Q_OBJECT
    Card *card;
    QLabel *Owner;
    int NrCard;
public:
    cardUI(QWidget *parent);
    cardUI();
    void setCard(Card *cardd);
    void setImage(QString file);
    void setOwner();
    void setNrcard();
    ~cardUI();
 public slots:
   void RefreshUI();
};

#endif // CARDUI_H
