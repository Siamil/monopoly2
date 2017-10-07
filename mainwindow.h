#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <player.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
Card **cards;
Player *player;
int iloscGraczy=2;
int Tura=0;

int dicenum;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    int on_bDice_clicked();





    void on_bMove_clicked();

    void on_bZakoncz_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
