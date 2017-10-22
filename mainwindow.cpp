#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <player.h>
#include "game.h"
#include <QBoxLayout>
#include <boardui.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   Game game;

   BoardUI* boardUI = new BoardUI(game.boardPTR);

   for(int i=0;i<16;i++)
   {
       boardUI->cardsUI[i]->setParent(this);
      // boardUI->cardsUI[i]->setLayout(ui->gridLayout);

   //boardUI->cardsUI[i]->show();

   }

   ui->bMove->setEnabled(false);
   ui->bZakoncz->setEnabled(false);
   ui->lTura->setText( "Tura gracza :"+QString::number(game.Tura+1));
   ui->lCash1->setText("Pieniadze gracza 1:" + QString::number(game.player[0].getCash()));
   ui->lCash2->setText("Pieniadze gracza 2:" + QString::number(game.player[1].getCash()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::on_bDice_clicked()
{

    game.Dice();
    QString s = QString::number(game.dicenum);
    ui->lDice->setText("Wylosowales :" +s);
    ui->bDice->setEnabled(false);
    ui->bMove->setEnabled(true);
    return game.dicenum;

}



void MainWindow::on_bMove_clicked()
{

    game.Move();
    QString s1 = QString::number(game.player[game.Tura].getPosition());
    ui->lPosition->setText("Jestes na polu :" +s1);
    ui->bZakoncz->setEnabled(true);
    ui->bMove->setEnabled(false);
    if(game.board.cards[game.player[game.Tura].getPosition()]->Buyable==true)
    {
        ui->bBuy->setEnabled(true);
    }
    else ui->bBuy->setEnabled(false);


    ui->lCash1->setText("Pieniadze gracza 1:" + QString::number(game.player[0].getCash()));
    ui->lCash2->setText("Pieniadze gracza 2:" + QString::number(game.player[1].getCash()));
}

void MainWindow::on_bZakoncz_clicked()
{
    game.End();

    ui->bDice->setEnabled(true);
    ui->bZakoncz->setEnabled(false);
   ui->lTura->setText( "Tura gracza :"+QString::number(game.Tura+1));
   QString s1 = QString::number(game.player[game.Tura].getPosition());
   ui->lPosition->setText("Jestes na polu :" +s1);
}

void MainWindow::on_bBuy_clicked()
{

    game.Buy();
    ui->lCash1->setText("Pieniadze gracza 1:" + QString::number(game.player[0].getCash()));
    ui->lCash2->setText("Pieniadze gracza 2:" + QString::number(game.player[1].getCash()));
    ui->bBuy->setEnabled(false);
}
