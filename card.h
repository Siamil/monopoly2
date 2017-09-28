#ifndef KARTA_H
#define KARTA_H
#include<QString>
#include<QWidget>
class Card : public QWidget
{
Q_OBJECT
public:
    int NrCard;

    int Price;
    int Owner;

private:
QString Colour;
public:
    Card(QWidget* parent = 0);
    ~Card();
    //Card(int nr, int price, int owner, QString colour);

    int getNrCard();
    void setPrice(int ck);
    int getPrice();
    void setOwner(int nrG);
    int getOwner();



protected:

   public slots:
};

#endif // KARTA_H
