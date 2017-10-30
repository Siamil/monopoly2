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
    ;
//    for(int i=0;i<16;i++)
//    {
//        board->cardsUI[i]->setParent(this);

//    }
    this->setUpdatesEnabled(true);

    ui->bMove->setEnabled(false);
    ui->bEnd->setEnabled(false);

    for(int i=0; i<numberOfPLayers;i++){

        connect(game.getPlayerPointer(i),SIGNAL(DataChanged()),this,SLOT(update()));

    }
    ui->bMove->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    board->drawCards(&painter,this->size());
    board->drawPlayers(&painter,this->size());
    ui->lTura->setText( "Tura gracza :"+(game.getCurrentPlayer()->getColor().name()));
    ui->lCash1->setText("Pieniadze gracza :" + QString::number(game.getCurrentPlayer()->getCash()));



}



void MainWindow::on_bMove_clicked()
{

    game.MovePlayer();
    //this->update();


    ui->bEnd->setEnabled(true);
    ui->bMove->setEnabled(false);
    if(game.CanBuyProperty())
    {
        ui->bBuy->setEnabled(true);
    }
    else ui->bBuy->setEnabled(false);
    if(game.CanBuyHouse()) ui->bBuyHouse->setEnabled(true);
    else ui->bBuyHouse->setEnabled(false);


}

void MainWindow::on_bEnd_clicked()
{
    game.EndPlayerTurn();

    ui->bMove->setEnabled(true);
    ui->bEnd->setEnabled(false);


}

void MainWindow::on_bBuy_clicked()
{

    game.BuyProperty();
    if(game.CanBuyHouse()) ui->bBuyHouse->setEnabled(true);
    else ui->bBuyHouse->setEnabled(false);

    ui->bBuy->setEnabled(false);
}

void MainWindow::on_bBuyHouse_clicked()
{
    game.BuyHouse();
    if(game.CanBuyHouse()) ui->bBuyHouse->setEnabled(true);
        else ui->bBuyHouse->setEnabled(false);

}
