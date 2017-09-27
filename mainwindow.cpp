#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFrame *jakas;
    for(int i=0;i<4;i++)
    {
        jakas++;
    jakas->setGeometry(450,150+(i*40),150,40);
   jakas->setStyleSheet("background-color: rgb(85, 170, 0)");
    jakas->setParent(this);
}
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
