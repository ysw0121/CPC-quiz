#include "login.h"
#include "ui_login.h"
#include"mainwindow.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
}

login::~login()
{
    delete ui;
}

void login::on_return_2_clicked()
{
    this->close();
    MainWindow*pic=new MainWindow();
    pic->show();
}

