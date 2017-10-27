#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <player.h>
#include "game.h"
#include <QBoxLayout>
#include <boardui.h>
#include "cardui.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    numberOfPLayers(4),
    game(numberOfPLayers)
{

    ui->setupUi(this);


   board = new BoardUI(game.getBoardPtr(), &game);
   //boardUI->player1->setParent(this);
   //boardUI->player2->setParent(this);
   for(int i=0;i<16;i++)
   {
       board->cardsUI[i]->setParent(this);
      //ui->gridLayout->addWidget(boardUI->cardsUI[i]);

   //boardUI->cardsUI[i]->show();

   }

   ui->bMove->setEnabled(false);
   ui->bEnd->setEnabled(false);
  // ui->lTura->setText( "Tura gracza :"+QString::number(game.Tura+1));
//   ui->lCash1->setText("Pieniadze gracza 1:" + QString::number(game.board.players[0]->getCash()));
//   ui->lCash2->setText("Pieniadze gracza 2:" + QString::number(game.board.players[1]->getCash()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    board->drawCards(&painter,this->size());
}



void MainWindow::on_bMove_clicked()
{

    game.MovePlayer();

//    game.Move();
//    QString s1 = QString::number(game.board.players[game.Tura]->getPosition());
//    ui->lPosition->setText("Jestes na polu :" +s1);
//    ui->bEnd->setEnabled(true);
//    ui->bMove->setEnabled(false);
//    if(game.board.cards[game.board.players[game.Tura]->getPosition()]->Buyable==true)
//    {
//        ui->bBuy->setEnabled(true);
//    }
//    else ui->bBuy->setEnabled(false);


//    ui->lCash1->setText("Pieniadze gracza 1:" + QString::number(game.board.players[0]->getCash()));
//    ui->lCash2->setText("Pieniadze gracza 2:" + QString::number(game.board.players[1]->getCash()));
}

void MainWindow::on_bEnd_clicked()
{
    game.EndPlayerTurn();

//    ui->bDice->setEnabled(true);
//    ui->bEnd->setEnabled(false);
//   ui->lTura->setText( "Tura gracza :"+QString::number(game.Tura+1));
//   QString s1 = QString::number(game.board.players[game.Tura]->getPosition());
//   ui->lPosition->setText("Jestes na polu :" +s1);
}

void MainWindow::on_bBuy_clicked()
{

    game.BuyProperty();
//    ui->lCash1->setText("Pieniadze gracza 1:" + QString::number(game.board.players[0]->getCash()));
//    ui->lCash2->setText("Pieniadze gracza 2:" + QString::number(game.board.players[1]->getCash()));
//    ui->bBuy->setEnabled(false);
}
