#include "register.h"
#include "ui_register.h"
#include"mainwindow.h"

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
}

Register::~Register()
{
    delete ui;
}

void Register::on_return_2_clicked()
{
    this->close();
    MainWindow*pic=new MainWindow();
    pic->show();
}

