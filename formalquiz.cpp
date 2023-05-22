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
int minute=20;
int second;
int msecond;
const int num_of_ex=20;


FormalQuiz::FormalQuiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormalQuiz)
{
    ui->setupUi(this);
    this->setWindowTitle("正式测试");
    qDebug()<<mode;

   tim=new QTimer(this);
    ui->CountDown->setSegmentStyle(QLCDNumber::Flat);
    ui->CountDown->setDigitCount(10);
    ui->CountDown->setMode(QLCDNumber::Dec);
    ui->CountDown->display("20:00:000");
    connect(tim,&QTimer::timeout,this,&FormalQuiz::countdown);
    tim->start(1000);

}

FormalQuiz::~FormalQuiz()
{
    tim->stop();
    disconnect(tim,&QTimer::timeout,this,&FormalQuiz::countdown);
     disconnect(this,&FormalQuiz::Delay_MSec,this,&FormalQuiz::countdown);
    delete tim;
    if (tim){
            if (tim->isActive() == true){
                tim->stop();
            }
            delete tim;
            tim= nullptr;
        }
    setAttribute(Qt::WA_DeleteOnClose);
    delete ui;
}

void FormalQuiz::countdown(){
    for(minute=19;minute>=0;minute--){
        if(minute<=2)ui->CountDown->setStyleSheet("QLCDNumber{color:rgb(255, 78, 25);}");
        for(second=59;second>=0;second--){
            for(msecond=999;msecond>=0;msecond--){
                 ui->CountDown->display(QDateTime::currentDateTime().toString(QString::number(minute).sprintf("%02d",minute)
                                                                              +":"+ QString::number(second).sprintf("%02d",second)+":"+QString::number(msecond).sprintf("%03d",msecond)));
                 Delay_MSec(1);
            }
        }
    }
    tim->stop();
    return;
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

void FormalQuiz::Delay_MSec(unsigned int msec){//毫秒
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime() < _Timer){
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }

}
