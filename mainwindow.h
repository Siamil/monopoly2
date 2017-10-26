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


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

const int numberOfPLayers; // It needs to be prior Game game.
                           // Because order here matters. Not one in initialization list of constructor
BoardUI *board;
Game game;
QHBoxLayout *Hlayout;
QVBoxLayout *Vlayout ;



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
//    int on_bDice_clicked();





    void on_bMove_clicked();

    void on_bEnd_clicked();

    void on_bBuy_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
