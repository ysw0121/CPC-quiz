#include "formalquiz.h"
#include "ui_formalquiz.h"
#include"model_choose.h"
#include<QDebug>

extern int mode;

FormalQuiz::FormalQuiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormalQuiz)
{
    ui->setupUi(this);
    this->setWindowTitle("正式测试");
    qDebug()<<mode;
}

FormalQuiz::~FormalQuiz()
{
    delete ui;
}

void FormalQuiz::on_return_2_clicked()
{
    this->close();
    Model_Choose *pic=new Model_Choose();
    pic->show();
}

