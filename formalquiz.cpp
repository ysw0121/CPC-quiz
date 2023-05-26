#include "formalquiz.h"
#include "ui_formalquiz.h"
#include"model_choose.h"
#include<QDebug>
#include <QTimer>
#include <QDateTime>
#include<QTime>
#include"usr_info.h"
#include <QString>
#include <QApplication>
#include <QCoreApplication>
#include <QEventLoop>
#include <QProcess>
#include<QMessageBox>



extern int mode;// 2为模拟
extern user succeed;
const int num_of_ex=5;
int score=0;

QTimer*tim;
bool start=false;
int second;
int msecond;



FormalQuiz::FormalQuiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormalQuiz)
{

    if(mode==1){
    if(succeed.times!=3){
        QMessageBox msgBox;
            msgBox.setWindowTitle("提示");
            msgBox.setText("您的次数还剩余"+QString::number(3-succeed.times)+"次");
            msgBox.setText("您进行正式测试将少一次机会，是否消耗一次？\n");
            msgBox.setStandardButtons(QMessageBox::Ok| QMessageBox::No );
            msgBox.setDefaultButton(QMessageBox::Ok);
            int ret = msgBox.exec();
            switch(ret){
            case QMessageBox::Ok:
                break;
            case QMessageBox::No:{
                 this->close();
                Model_Choose*pic=new Model_Choose();
                pic->show();
               }
            }
        }
    else if(succeed.times==3){
        QMessageBox::critical(this,tr("警告"),tr("您已用完次数，不可再参加正式竞赛"));
        this->close();
       Model_Choose*pic=new Model_Choose();
       pic->show();
    }
    }


    ui->setupUi(this);
    this->setWindowTitle("正式测试");
    qDebug()<<mode;

    time.setHMS(0,0,30,800);
    tim=new QTimer(this);
    ui->CountDown->setSegmentStyle(QLCDNumber::Flat);
    ui->CountDown->setDigitCount(10);
    ui->CountDown->setMode(QLCDNumber::Dec);
    ui->CountDown->display("30:000");
    connect(tim,&QTimer::timeout,this,&FormalQuiz::countdown);

    tim->start(1);

}

FormalQuiz::~FormalQuiz()
{
//    tim->stop();
//    disconnect(tim,&QTimer::timeout,this,&FormalQuiz::countdown);
//     disconnect(this,&FormalQuiz::Delay_MSec,this,&FormalQuiz::countdown);

    delete ui;
}

void FormalQuiz::countdown(){ 

           time=time.addMSecs(-1);
           if(time.second()<=10)ui->CountDown->setStyleSheet("QLCDNumber{color:rgb(255, 78, 25);}");
           ui->CountDown->display(time.toString("ss:zzz"));
           if(time.second()==0&&time.msec()==0){
               tim->stop();
           }

}

void FormalQuiz::on_return_2_clicked()
{
    tim->stop();
    disconnect(tim,&QTimer::timeout,this,&FormalQuiz::countdown);
    delete tim;

    this->close();
    Model_Choose *pic=new Model_Choose();
    pic->show();
}


