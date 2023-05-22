#include "model_choose.h"
#include "ui_model_choose.h"
#include"mainwindow.h"
#include"formalquiz.h"
#include"exercise.h"
#include"rank.h"
#include"usr_info.cpp"

extern user succeed;


int mode;
Model_Choose::Model_Choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Model_Choose)
{
    ui->setupUi(this);
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
    this->close();
    FormalQuiz *pic=new FormalQuiz();
    mode=1;
    pic->show();
}


void Model_Choose::on_simulate_clicked()
{
    this->close();
    FormalQuiz *pic=new FormalQuiz();
    mode=2;
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

