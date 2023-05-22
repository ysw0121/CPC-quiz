#include "rank.h"
#include "ui_rank.h"
#include"model_choose.h"
#include"usr_info.cpp"
#include<QString>
#include<QList>

extern QList<user>usrlist;
extern QList<user>Ranklist;

Rank::Rank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rank)
{
    ui->setupUi(this);
    this->setWindowTitle("排行榜");



}

Rank::~Rank()
{
    delete ui;
}

void Rank::on_return_2_clicked()
{
    this->close();
    Model_Choose *pic=new Model_Choose();
    pic->show();

}

