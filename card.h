#ifndef KARTA_H
#define KARTA_H
#include<QString>

class Card
{

public:
    int NrCard;

    int Price;
    int Owner;

private:
QString Colour;
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



protected:


};

#endif // KARTA_H
