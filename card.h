#ifndef KARTA_H
#define KARTA_H
#include<QString>
#include<QColor>

class Card
{
public:


    enum CardType {
        Start,
        Property,
        Jail,
        Tax,
        Bonus
    };


private:
    int price;
    int nrCard;
    bool buyable=true;
    QColor color;
    CardType type;
    int houses=0;

public:



    Card();
    ~Card();

    void setPrice(int price);
    int getPrice();

    void setNrCard(int nrCard);
    int getNrCard();


    void setBuyable(bool isBuyable);
    bool getBuyable();

    void setColor(QColor col);
    QColor getColor();

    void setType(CardType type);
    CardType getType();

    void setHouses(int houses);
    int getHouses();

    int calculatePayment();



protected:


};

#endif // KARTA_H
