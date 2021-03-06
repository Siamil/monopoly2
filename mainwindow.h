#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <player.h>
#include <QString>
#include <game.h>
#include <QBoxLayout>
#include "boardui.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QMessageBox>
#include <QVector>
#include <QLabel>
#include "configreader.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int numberOfPLayers; // It needs to be prior Game game.
    // Because order here matters. Not one in initialization list of constructor
    BoardUI *board;
    Game *game;
    QHBoxLayout *Hlayout;
    QVBoxLayout *Vlayout ;
    QVector <QLabel*> labels;
    ConfigReader *configReader;



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *e);

private slots:
    //    int on_bDice_clicked();


    void diceThrown(int dice);
    void setStatement(QString statement);
    void auctionEnd();
    void setTradePrice();
    void tradeEnd();





    void on_bMove_clicked();

    void on_bEnd_clicked();

    void on_bBuy_clicked();

    void on_bBuyHouse_clicked();

    void on_bAuction_clicked();

    void on_bAucplus_clicked();



    void on_bBid_clicked();

    void on_bAucstop_clicked();



    void on_bAucplus50_clicked();



    void on_bTrade_clicked();

    void on_bTradeAuction_clicked();

    void on_bTradeBuy_clicked();

    void on_bTradeOk_clicked();

    void on_bTradeNo_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
