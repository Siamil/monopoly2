#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <player.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int iloscGraczy=2;
    player = new Player[iloscGraczy];


      player[0].setCash(1000);
      player[0].setPosition(0);
      player[0].setNrPlayer(0);

      player[1].setCash(1000);
      player[1].setPosition(0);
      player[1].setNrPlayer(1);
    cards = new Card*[40];
    for(int i=0;i<40;i++){
        cards[i] = new Card;
    }
    cards[0]->setNrCard(0);
    cards[0]->setOwner(9);
    cards[0]->setPrice(0);
    cards[0]->setBuyable(false);
    cards[0]->setType("start");

    cards[1]->setNrCard(1);
    cards[1]->setOwner(9);
    cards[1]->setPrice(60);
    cards[1]->setBuyable(true);
    cards[1]->setType("rent");
    cards[1]->setColour("purple");

    cards[2]->setNrCard(2);
    cards[2]->setOwner(9);
    cards[2]->setPrice(300);
    cards[2]->setBuyable(false);
    cards[2]->setType("chest");


    cards[3]->setNrCard(3);
    cards[3]->setOwner(9);
    cards[3]->setPrice(60);
    cards[3]->setBuyable(true);
    cards[3]->setType("rent");
    cards[3]->setColour("purple");

    cards[4]->setNrCard(4);
    cards[4]->setOwner(9);
    cards[4]->setPrice(200);
    cards[4]->setBuyable(false);
    cards[4]->setType("tax");


    cards[5]->setNrCard(5);
    cards[5]->setOwner(9);
    cards[5]->setPrice(300);
    cards[5]->setBuyable(false);
    cards[5]->setType("train");


    cards[6]->setNrCard(6);
    cards[6]->setOwner(9);
    cards[6]->setPrice(100);
    cards[6]->setBuyable(true);
    cards[6]->setType("rent");
    cards[6]->setColour("azure");

    cards[7]->setNrCard(7);
    cards[7]->setOwner(9);
    cards[7]->setPrice(0);
    cards[7]->setBuyable(false);
    cards[7]->setType("chance");

    cards[8]->setNrCard(8);
    cards[8]->setOwner(9);
    cards[8]->setPrice(100);
    cards[8]->setBuyable(true);
    cards[8]->setType("rent");
    cards[8]->setColour("azure");


    cards[9]->setNrCard(9);
    cards[9]->setOwner(9);
    cards[9]->setPrice(100);
    cards[9]->setBuyable(true);
    cards[9]->setType("rent");
    cards[9]->setColour("azure");

    cards[10]->setNrCard(10);
    cards[10]->setOwner(9);
    cards[10]->setPrice(100);
    cards[10]->setBuyable(false);
    cards[10]->setType("jail");

    cards[11]->setNrCard(11);
    cards[11]->setOwner(9);
    cards[11]->setPrice(140);
    cards[11]->setBuyable(true);
    cards[11]->setType("rent");
    cards[11]->setColour("pink");

    cards[12]->setNrCard(12);
    cards[12]->setOwner(9);
    cards[12]->setPrice(150);
    cards[12]->setBuyable(false);
    cards[12]->setType("tax");

    cards[13]->setNrCard(13);
    cards[13]->setOwner(9);
    cards[13]->setPrice(140);
    cards[13]->setBuyable(true);
    cards[13]->setType("rent");
    cards[13]->setColour("pink");

    cards[14]->setNrCard(14);
    cards[14]->setOwner(9);
    cards[14]->setPrice(160);
    cards[14]->setBuyable(true);
    cards[14]->setType("rent");
    cards[14]->setColour("pink");

    cards[15]->setNrCard(15);
    cards[15]->setOwner(9);
    cards[15]->setPrice(300);
    cards[15]->setBuyable(false);
    cards[15]->setType("train");

    cards[16]->setNrCard(16);
    cards[16]->setOwner(9);
    cards[16]->setPrice(180);
    cards[16]->setBuyable(true);
    cards[16]->setType("rent");
    cards[16]->setColour("orange");

    cards[17]->setNrCard(17);
    cards[17]->setOwner(9);
    cards[17]->setPrice(300);
    cards[17]->setBuyable(false);
    cards[17]->setType("chest");

    cards[18]->setNrCard(18);
    cards[18]->setOwner(9);
    cards[18]->setPrice(180);
    cards[18]->setBuyable(true);
    cards[18]->setType("rent");
    cards[18]->setColour("orange");

    cards[19]->setNrCard(19);
    cards[19]->setOwner(9);
    cards[19]->setPrice(200);
    cards[19]->setBuyable(true);
    cards[19]->setType("rent");
    cards[19]->setColour("orange");

    cards[20]->setNrCard(20);
    cards[20]->setOwner(9);
    cards[20]->setPrice(200);
    cards[20]->setBuyable(false);
    cards[20]->setType("tax");

    cards[21]->setNrCard(21);
    cards[21]->setOwner(9);
    cards[21]->setPrice(220);
    cards[21]->setBuyable(true);
    cards[21]->setType("rent");
    cards[21]->setColour("red");

    cards[22]->setNrCard(22);
    cards[22]->setOwner(9);
    cards[22]->setPrice(0);
    cards[22]->setBuyable(false);
    cards[22]->setType("chance");

    cards[23]->setNrCard(23);
    cards[23]->setOwner(9);
    cards[23]->setPrice(220);
    cards[23]->setBuyable(true);
    cards[23]->setType("rent");
    cards[23]->setColour("red");

    cards[24]->setNrCard(24);
    cards[24]->setOwner(9);
    cards[24]->setPrice(240);
    cards[24]->setBuyable(true);
    cards[24]->setType("rent");
    cards[24]->setColour("red");

    cards[25]->setNrCard(25);
    cards[25]->setOwner(9);
    cards[25]->setPrice(300);
    cards[25]->setBuyable(false);
    cards[25]->setType("train");

    cards[26]->setNrCard(26);
    cards[26]->setOwner(9);
    cards[26]->setPrice(260);
    cards[26]->setBuyable(true);
    cards[26]->setType("rent");
    cards[26]->setColour("yellow");

    cards[27]->setNrCard(27);
    cards[27]->setOwner(9);
    cards[27]->setPrice(260);
    cards[27]->setBuyable(true);
    cards[27]->setType("rent");
    cards[27]->setColour("yellow");

    cards[28]->setNrCard(28);
    cards[28]->setOwner(9);
    cards[28]->setPrice(150);
    cards[28]->setBuyable(false);
    cards[28]->setType("tax");

    cards[29]->setNrCard(29);
    cards[29]->setOwner(9);
    cards[29]->setPrice(280);
    cards[29]->setBuyable(true);
    cards[29]->setType("rent");
    cards[29]->setColour("yellow");

    cards[30]->setNrCard(30);
    cards[30]->setOwner(9);
    cards[30]->setPrice(100);
    cards[30]->setBuyable(false);
    cards[30]->setType("jail");

    cards[31]->setNrCard(31);
    cards[31]->setOwner(9);
    cards[31]->setPrice(300);
    cards[31]->setBuyable(true);
    cards[31]->setType("rent");
    cards[31]->setColour("green");

    cards[32]->setNrCard(32);
    cards[32]->setOwner(9);
    cards[32]->setPrice(300);
    cards[32]->setBuyable(true);
    cards[32]->setType("rent");
    cards[32]->setColour("green");

    cards[33]->setNrCard(33);
    cards[33]->setOwner(9);
    cards[33]->setPrice(0);
    cards[33]->setBuyable(false);
    cards[33]->setType("chance");

    cards[34]->setNrCard(34);
    cards[34]->setOwner(9);
    cards[34]->setPrice(320);
    cards[34]->setBuyable(true);
    cards[34]->setType("rent");
    cards[34]->setColour("green");

    cards[35]->setNrCard(35);
    cards[35]->setOwner(9);
    cards[35]->setPrice(300);
    cards[35]->setBuyable(false);
    cards[35]->setType("train");

    cards[36]->setNrCard(36);
    cards[36]->setOwner(9);
    cards[36]->setPrice(0);
    cards[36]->setBuyable(false);
    cards[36]->setType("chance");

    cards[37]->setNrCard(37);
    cards[37]->setOwner(9);
    cards[37]->setPrice(350);
    cards[37]->setBuyable(true);
    cards[37]->setType("rent");
    cards[37]->setColour("blue");

    cards[38]->setNrCard(38);
    cards[38]->setOwner(9);
    cards[38]->setPrice(75);
    cards[38]->setBuyable(false);
    cards[38]->setType("tax");

    cards[39]->setNrCard(39);
    cards[39]->setOwner(9);
    cards[39]->setPrice(400);
    cards[39]->setBuyable(true);
    cards[39]->setType("rent");
    cards[39]->setColour("blue");




    ui->bMove->setEnabled(false);
    ui->bZakoncz->setEnabled(false);
    ui->lTura->setText( "Tura gracza :"+QString::number(Tura+1));

    ui->lCash1->setText("Pieniadze gracza 1:" + QString::number(player[0].getCash()));
    ui->lCash2->setText("Pieniadze gracza 2:" + QString::number(player[1].getCash()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::on_bDice_clicked()
{

    dicenum = rand() % 6 +1;
    QString s = QString::number(dicenum);
    ui->lDice->setText("Wylosowales :" +s);
    ui->bDice->setEnabled(false);
    ui->bMove->setEnabled(true);
    return dicenum;

}



void MainWindow::on_bMove_clicked()
{

    player[Tura].setPosition(player[Tura].getPosition()+dicenum);
    if(player[Tura].getPosition()>31) player[Tura].setPosition(player[Tura].getPosition()+dicenum -33);
    QString s1 = QString::number(player[Tura].getPosition());
    ui->lPosition->setText("Jestes na polu :" +s1);
    ui->bZakoncz->setEnabled(true);
    ui->bMove->setEnabled(false);
    if(cards[player[Tura].getPosition()]->Buyable==true)
    {
        ui->bBuy->setEnabled(true);
    }
    if(cards[player[Tura].getPosition()]->Owner!=(Tura) && cards[player[Tura].getPosition()]->Owner!=(9))
    {
            player[Tura].setCash(player[Tura].getCash()- (cards[player[Tura].getPosition()]->getPrice()/10));
            player[cards[player[Tura].getPosition()]->Owner].setCash(player[cards[player[Tura].getPosition()]->Owner].getCash()+ ((cards[player[Tura].getPosition()]->getPrice())/10));
}
    ui->lCash1->setText("Pieniadze gracza 1:" + QString::number(player[0].getCash()));
    ui->lCash2->setText("Pieniadze gracza 2:" + QString::number(player[1].getCash()));
}

void MainWindow::on_bZakoncz_clicked()
{
    if(Tura<iloscGraczy-1){
        Tura++;
    }
    else Tura=0;
    ui->bDice->setEnabled(true);
    ui->bZakoncz->setEnabled(false);
   ui->lTura->setText( "Tura gracza :"+QString::number(Tura+1));
   QString s1 = QString::number(player[Tura].getPosition());
   ui->lPosition->setText("Jestes na polu :" +s1);
}

void MainWindow::on_bBuy_clicked()
{
    cards[player[Tura].getPosition()]->setBuyable(false);
    cards[player[Tura].getPosition()]->setOwner(Tura);
    player[Tura].setCash(player[Tura].getCash() - cards[player[Tura].getPosition()]->Price);
    ui->lCash1->setText("Pieniadze gracza 1:" + QString::number(player[0].getCash()));
    ui->lCash2->setText("Pieniadze gracza 2:" + QString::number(player[1].getCash()));
    ui->bBuy->setEnabled(false);
}
