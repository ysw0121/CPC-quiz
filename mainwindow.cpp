#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"login.h"
#include<register.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("欢迎");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_login_clicked()
{
    this->close();
   login *pic=new login();
    pic->show();
}


void MainWindow::on_register_2_clicked()
{
    this->close();
    Register*pic=new Register();
    pic->show();
}

