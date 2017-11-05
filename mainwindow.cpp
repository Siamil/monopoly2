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
    connect(&game, SIGNAL(DataChanged()), this, SLOT(setTradePrice()));
    connect(&game, SIGNAL(auctionEnd()), this, SLOT(auctionEnd()));
    connect(&game, SIGNAL(tradeEnd()), this, SLOT(tradeEnd()));
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

    ui->verticalL->setContentsMargins((size().width()*4)/5, 0, 0, 0);
    ui->lCash1->setText("Pieniadze gracza :" + QString::number(game.getPlayerPointer(0)->getCash()));
    ui->lCash2->setText("Pieniadze gracza :" + QString::number(game.getPlayerPointer(1)->getCash()));
    ui->lCash3->setText("Pieniadze gracza :" + QString::number(game.getPlayerPointer(2)->getCash()));
    ui->lCash4->setText("Pieniadze gracza :" + QString::number(game.getPlayerPointer(3)->getCash()));




}

void MainWindow::diceThrown(int dice)
{
    ui->lDice->setText("Wylosowales: " + QString::number(dice));
}

void MainWindow::setStatement(QString statement)
{
    QFont f( "Arial", 13, QFont::Bold);
    ui->lStatement->setFont( f);
    ui->lStatement->setText(statement);
}

void MainWindow::auctionEnd()
{
    ui->bAucplus50->setEnabled(false);
    ui->bAucplus50->setVisible(false);
    ui->bAucplus->setEnabled(false);
    ui->bAucplus->setVisible(false);
    ui->bBid->setVisible(false);
    ui->bAucstop->setVisible(false);
    ui->bAucstop->setEnabled(false);
    ui->bEnd->setEnabled(true);
}

void MainWindow::setTradePrice()
{
    ui->lAucprice->setText("Cena pola podczas licytacji: " +QString::number(game.getAuctionPrice()));
}

void MainWindow::tradeEnd()
{
    ui->tNrCard->setEnabled(false);
    ui->bTradeAuction->setEnabled(false);
    ui->bTradeBuy->setEnabled(false);
    ui->tCardPrice->setEnabled(false);
    ui->bTradeNo->setEnabled(false);
    ui->bTradeOk->setEnabled(false);
    ui->lTradeAsk->setText("");
}



void MainWindow::on_bMove_clicked()
{

    game.MovePlayer();
    ui->bEnd->setEnabled(true);
    ui->bMove->setEnabled(false);
    if(game.CanBuyProperty())
    {
        ui->bBuy->setEnabled(true);
        ui->bAuction->setEnabled(true);
    }
    else{
        ui->bBuy->setEnabled(false);
        ui->bAuction->setEnabled(false);
    }
    if(game.CanBuyHouse()) ui->bBuyHouse->setEnabled(true);
    else ui->bBuyHouse->setEnabled(false);


}

void MainWindow::on_bEnd_clicked()
{
    game.EndPlayerTurn();
    ui->bBuy->setEnabled(false);
    ui->bAuction->setEnabled(false);
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
    ui->bAuction->setEnabled(false);
}

void MainWindow::on_bBuyHouse_clicked()
{
    game.BuyHouse();
    if(game.CanBuyHouse()) ui->bBuyHouse->setEnabled(true);
    else ui->bBuyHouse->setEnabled(false);

}

void MainWindow::on_bAuction_clicked()
{
    game.Auction();
    ui->bAuction->setEnabled(false);
    ui->bBuy->setEnabled(false);
    ui->bAucplus50->setEnabled(true);
    ui->bAucplus50->setVisible(true);
    ui->bAucplus->setEnabled(true);
    ui->bAucplus->setVisible(true);
    ui->bBid->setVisible(true);
    ui->bAucstop->setVisible(true);
    ui->bAucstop->setEnabled(true);
    ui->bEnd->setEnabled(false);
    ui->bBid->setEnabled(false);

}

void MainWindow::on_bAucplus_clicked()
{

    game.setAuctionPrice(game.getAuctionPrice()+10);

    ui->bBid->setEnabled(true);
    ui->bAucstop->setEnabled(false);
}



void MainWindow::on_bBid_clicked()
{
    ui->bBid->setEnabled(false);
    ui->bAucstop->setEnabled(true);
    game.EndPlayerTurn();

    if(game.getCurrentPlayer()->getAuction()==false)
    {
        game.EndAuction();

    }
    else ui->bEnd->setEnabled(false);

}

void MainWindow::on_bAucstop_clicked()
{
    ui->bBid->setEnabled(false);
    game.getCurrentPlayer()->setAuction(false);
    //    if(game.getCurrentPlayer()->getAuction()==false)
    //    {
    game.EndAuction();

    //    }
    //    else ui->bEnd->setEnabled(false);

}



void MainWindow::on_bAucplus50_clicked()
{
    game.setAuctionPrice(game.getAuctionPrice() + 50);

    ui->bBid->setEnabled(true);
    ui->bAucstop->setEnabled(false);
}


void MainWindow::on_bTrade_clicked()
{
    ui->tNrCard->setEnabled(true);
    ui->bTradeAuction->setEnabled(true);
    ui->bTradeBuy->setEnabled(true);
    ui->tCardPrice->setEnabled(true);
}

void MainWindow::on_bTradeAuction_clicked()
{
    if(game.HasPlayerCard(ui->tNrCard->value()))
    {
        game.Auction();

        ui->bAuction->setEnabled(false);
        ui->bBuy->setEnabled(false);
        ui->bAucplus50->setEnabled(true);
        ui->bAucplus50->setVisible(true);
        ui->bAucplus->setEnabled(true);
        ui->bAucplus->setVisible(true);
        ui->bBid->setVisible(true);
        ui->bAucstop->setVisible(true);
        ui->bAucstop->setEnabled(true);
        ui->bEnd->setEnabled(false);
        ui->bBid->setEnabled(false);

    }
    else{
        QMessageBox::information(this, "Nie mozna wystawic karty", "Nie posiadasz tej karty");
    }
}

void MainWindow::on_bTradeBuy_clicked()
{
    int nrcard = ui->tNrCard->value();
    if(game.CanTradeProperty(nrcard) && ui->tCardPrice->value() > 0)
    {
        int price = ui->tCardPrice->value();
        game.TradeProperty(nrcard);
        ui->lTradeAsk->setText("Czy chcesz sprzedac pole "+ QString::number(nrcard) + " za " + QString::number(price) + "?" );
        ui->tCardPrice->setEnabled(false);
        ui->tNrCard->setEnabled(false);
        ui->bTradeNo->setEnabled(true);
        ui->bTradeOk->setEnabled(true);
    }
    else QMessageBox::information(this, "Nie mozna kupic karty", "Nikt nie posiada tej karty lub nie wpisales ceny karty");
}

void MainWindow::on_bTradeOk_clicked()
{
    int nrcard = ui->tNrCard->value();
    game.EndTradeOK(game.getTradingPlayer(), ui->tCardPrice->value(), nrcard);


}

void MainWindow::on_bTradeNo_clicked()
{
    game.EndTradeNo(game.getTradingPlayer());

}
