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

    for(int i=0; i<numberOfPLayers; i++){

        connect(game.getPlayerPointer(i), SIGNAL(DataChanged()), this, SLOT(update()));

    }
    connect(&game, SIGNAL(newDiceThrow(int)), this, SLOT(diceThrown(int)));
    connect(&game, SIGNAL(statement(QString)), this, SLOT(setStatement(QString)));
    ui->bMove->setEnabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    board->drawCards(&painter, this->size());
    board->drawPlayers(&painter, this->size());
    ui->lTura->setText( "Tura gracza :" + game.whosTurn());
    ui->lCash1->setText("Pieniadze gracza :" + QString::number(game.getCurrentPlayer()->getCash()));




}

void MainWindow::diceThrown(int dice)
{
    ui->lDice->setText("Wylosowales: " + QString::number(dice));
}

void MainWindow::setStatement(QString statement)
{
    ui->lStatement->setText(statement);
}



void MainWindow::on_bMove_clicked()
{

    game.MovePlayer();
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
    ui->bBuy->setEnabled(false);
    if(game.getCurrentPlayer()->getJail())
    {
        ui->bMove->setEnabled(false);
        ui->bEnd->setEnabled(true);
        game.getCurrentPlayer()->setJail(false);
    }

    else{
        ui->bMove->setEnabled(true);
        ui->bEnd->setEnabled(false);
    }

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
