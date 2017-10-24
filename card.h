#ifndef KARTA_H
#define KARTA_H
#include<QString>

class Card
{

public:
    int NrCard;

    int Price;
public:
    int Owner;

    bool Buyable;
    QString Colour;
    QString Type;
public:


    Card();

    Card(int nr, int price, int owner, QString colour);


    ~Card();
    //Card(int nr, int price, int owner, QString colour);


    int getNrCard();
    void setPrice(int ck);
    int getPrice();
    void setOwner(int nrG);
    int getOwner();
    void setNrCard(int nr);
    void setBuyable(bool by);
    bool getBuyable();
    void setColour(QString col);
    void setType(QString type);
    QString getColour();
    QString getType();


protected:


};

#endif // KARTA_H
