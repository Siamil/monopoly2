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
    cards = new Card*[32];
    for(int i=0;i<32;i++){
        cards[i] = new Card;
    }
    ui->bMove->setEnabled(false);
    ui->bZakoncz->setEnabled(false);
    ui->lTura->setText( "Tura gracza :"+QString::number(Tura+1));
    //cards[i]->setNrCard(i);
    //cards[i]->setOwner(0);
   // }



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
