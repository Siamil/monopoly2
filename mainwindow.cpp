#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   /* QFrame *tablica;
    QFrame *jakas= tablica;
    tablica= new QFrame[5];

    for(int i=0;i<4;i++)
    {

   *jakas[i].setGeometry(450,150+(i*40),150,40);
   *jakas[i].setStyleSheet("background-color: rgb(85, 170, 0)");
jakas++;
}*/
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
