#include "model_choose.h"
#include "ui_model_choose.h"
#include"mainwindow.h"
#include"formalquiz.h"
#include"exercise.h"
#include"rank.h"
#include"usr_info.h"
#include<QMessageBox>
#include<QString>


extern user succeed;


int mode;

Model_Choose::Model_Choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Model_Choose)
{
    ui->setupUi(this);
    ui->remain->setText("您的正式竞赛剩余次数还有"+QString::number(3-succeed.times)+"次");
    this->setWindowTitle("欢迎你，"+succeed.name+"，请进行模式选择");
}

Model_Choose::~Model_Choose()
{
    delete ui;
}

void Model_Choose::on_return_2_clicked()
{
    this->close();
    MainWindow*pic=new MainWindow();
    pic->show();
}


void Model_Choose::on_formal_clicked()
{
    mode=1;
    this->close();
    FormalQuiz *pic=new FormalQuiz();
    pic->show();
}


void Model_Choose::on_simulate_clicked()
{
    mode=2;
    this->close();
    FormalQuiz *pic=new FormalQuiz();
    pic->show();
}


void Model_Choose::on_exercise_clicked()
{
    this->close();
    Exercise *pic=new Exercise();
    pic->show();
}


void Model_Choose::on_rankView_clicked()
{
    this->close();
    Rank*pic=new Rank();
    pic->show();
}

