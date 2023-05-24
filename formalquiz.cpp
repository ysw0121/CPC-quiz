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



extern int mode;

QTimer*tim;
bool start=false;
//int minute=20;
int second;
int msecond;
const int num_of_ex=5;


FormalQuiz::FormalQuiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormalQuiz)
{
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


