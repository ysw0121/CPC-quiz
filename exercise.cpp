#include "exercise.h"
#include "ui_exercise.h"
#include"model_choose.h"
#include<QButtonGroup>

Exercise::Exercise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exercise)
{
    ui->setupUi(this);
    this->setWindowTitle("练习模式");
    QButtonGroup*box=new QButtonGroup;
    box->setExclusive(true);
    box->addButton(ui->A);
    box->addButton(ui->B);
    box->addButton(ui->C);
}

Exercise::~Exercise()
{
    delete ui;
}

void Exercise::on_return_2_clicked()
{
    this->close();
    Model_Choose*pic=new Model_Choose();
    pic->show();
}

