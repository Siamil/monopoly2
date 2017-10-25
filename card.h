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
        Jail
    };


    private:
    int price;

    bool buyable;
    QColor color;
    CardType type;

public:



    Card();
    ~Card();

    void setPrice(int price);
    int getPrice();

    void setBuyable(bool isBuyable);
    bool getBuyable();

    void setColor(QColor col);
    QColor getColor();

    void setType(CardType type);
    CardType getType();

    int calculatePayment();



protected:


};

#endif // KARTA_H
