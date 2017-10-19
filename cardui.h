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
    cardUI();
    void setImage(QString file);
    void setOwner();
    void setNrcard();
 public slots:
   void RefreshUI();
};

#endif // CARDUI_H
