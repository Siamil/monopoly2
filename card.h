#ifndef KARTA_H
#define KARTA_H
#include<QString>
#include<QColor>

class Card
{
    int price;

    bool buyable;
    QString colour;
    CardType type;


public:

    enum CardType {
        Start,
        Property,
        Jail
    }

    Card();
    ~Card();

    void setPrice(int price);
    int getPrice();

    void setOwner(Player* newOwner);
    Player* getOwner();

    void setBuyable(bool isBuyable);
    bool getBuyable();

    void setColor(QColor col);
    QColor getColor();

    void setType(QString type);
    QString getType();


protected:


};

#endif // KARTA_H
