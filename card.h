#ifndef KARTA_H
#define KARTA_H
#include<QString>
#include<QWidget>
class Card
{

public:
    int NrCard;

    int Price;
    int Owner;

private:
QString Colour;
public:
<<<<<<< HEAD

    Card();

    Card(int nr, int price, int owner, QString colour);
=======
    Card(QWidget* parent = 0);
    ~Card();
    //Card(int nr, int price, int owner, QString colour);
>>>>>>> d04be9c024a40fbcddf90432fd984ab10257bc12

    int getNrCard();
    void setPrice(int ck);
    int getPrice();
    void setOwner(int nrG);
    int getOwner();



protected:

   public slots:
};

#endif // KARTA_H
