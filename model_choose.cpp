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
extern int exerflag;

int mode;

Model_Choose::Model_Choose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Model_Choose)
{
    ui->setupUi(this);
    if(succeed.times==3)ui->remain->setStyleSheet("color:rgb(255, 78, 25)");
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


    if(succeed.times!=3){
        QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("您的次数还剩余"+QString::number(3-succeed.times)+"次");
            msgBox.setText("您进行正式测试将少一次机会，是否消耗一次？\n");
            msgBox.setStandardButtons(QMessageBox::Ok| QMessageBox::No );
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            switch(ret){
            case QMessageBox::Ok:{
                this->close();
                FormalQuiz *pic=new FormalQuiz();
                pic->show();
                 break;
            }

            case QMessageBox::No:{
              break;
               }
            }
    }
    else if(succeed.times==3){
        QMessageBox::critical(this,tr("警告"),tr("您已用完次数，不可再参加正式竞赛"));
       return;
    }




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
    exerflag=1;
    Exercise *pic=new Exercise();
    pic->show();
}


void Model_Choose::on_rankView_clicked()
{
    this->close();
    Rank*pic=new Rank();
    pic->show();
}

