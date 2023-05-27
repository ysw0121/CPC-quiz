#include "formalquiz.h"
#include "ui_formalquiz.h"
#include"model_choose.h"
#include"usr_info.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include <QTimer>
#include <QDateTime>
#include<QTime>
#include <QString>
#include <QApplication>
#include <QCoreApplication>
#include<QRandomGenerator>
#include <QEventLoop>
#include <QProcess>
#include<QMessageBox>
#include<QChar>
#include<QButtonGroup>
#include<QObject>


extern QList<question>questionlist;
extern QList<user>usrlist;
QList<question>exam;

extern QButtonGroup*box;
extern int mode;// 2为模拟
extern user succeed;
const int num_of_ex=5;
int score=0;
QList<QChar>ansSheet;

QTimer*tim;
bool start=false;
int second;
int msecond;
int num=0;


FormalQuiz::FormalQuiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormalQuiz)
{

    ui->setupUi(this);
    this->setWindowTitle("正式测试");
    qDebug()<<mode;

    QMessageBox::information(this,tr(""),tr("您有30秒时间，需要回答5道题目。\n答题形式同练习，您只能答完该题再进行下一道。\n时间到或者题目答完后系统自动交卷。\n准备好点击开始，进入后直接开始！"));

    for(int i=0;i<=questionlist.size()-questionlist.size()/num_of_ex;i+=questionlist.size()/num_of_ex){
        int j=QRandomGenerator::global()->bounded(i,i+questionlist.size()/num_of_ex-1);
        exam<<questionlist[j];
    }
    for(int i=0;i<exam.size();i++)qDebug()<<exam[i].quest;
    qDebug()<<exam.size();

    ui->A->setChecked(false);
    ui->B->setChecked(false);
    ui->C->setChecked(false);
    box=new QButtonGroup;
    box->setExclusive(true);
    box->addButton(ui->A);
    box->addButton(ui->B);
    box->addButton(ui->C);

    QString qs=exam[0].quest+"\n\n"+exam[0].option;
    ui->paper->setText(qs);

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
    tim->stop();
    disconnect(tim,&QTimer::timeout,this,&FormalQuiz::countdown);
    delete tim;
    delete ui;
}

void FormalQuiz::countdown(){ 

           time=time.addMSecs(-1);
           if(time.second()<=10)ui->CountDown->setStyleSheet("QLCDNumber{color:rgb(255, 78, 25);background-color: rgb(225, 225, 225);}");
           ui->CountDown->display(time.toString("ss:zzz"));

           if(time.second()==0&&time.msec()==0){
               tim->stop();
               QMessageBox::information(this,tr("考试结束"),tr("时间到，停止答题"));
               if(mode==2){
                   QString reci;
                   for(int i=0;i<ansSheet.size();i++){
                       if(ansSheet[i]==exam[i].answer)score++;
                       else{
                           reci+="您答错了："+exam[i].quest+"\n"+exam[i].option+"\n"+"您的答案是："+QString(ansSheet[i])+"   正确答案是："+QString(exam[i].answer)+"\n";
                       }
                   }
                   for(int i=ansSheet.size();i<exam.size();i++){
                       reci+="您未作答："+exam[i].quest+"\n"+exam[i].option+"\n"+"正确答案是："+QString(exam[i].answer)+"\n";
                   }
                   reci+="您的成绩：答对"+QString::number(score)+"题\n";
                   reci+="用时："+QString::number(30.000)+"秒";
                   QMessageBox::information(this,tr("考试结果"),reci);
               }

               if(mode==1){
                   QString reci;
                   for(int i=0;i<ansSheet.size();i++){
                       if(ansSheet[i]==exam[i].answer)score++;
                   }
                   reci+="您的成绩：答对"+QString::number(score)+"题\n";
                   reci+="用时："+QString::number(30.000)+"秒";

                   succeed.times++;
                   if(succeed.correct<score){
                       succeed.correct=score;
                       succeed.time=30.000;
                   }
                   else if(succeed.correct==score){
                       if(succeed.time>30.000)succeed.time=30.000;
                   }

                   if(succeed.times==1)succeed.time=30.000;

                   for(int i=0;i<usrlist.size();i++){
                       if(succeed.name==usrlist[i].name){
                           usrlist[i]=succeed;
                           break;
                       }
                   }

                   QFile file1("user.txt");
                           if(file1.open(QIODevice::WriteOnly|QIODevice::Truncate)){
                               QTextStream out(&file1);
                               out.setCodec("UTF-8");
                               for(int i=0;i<usrlist.size();i++){
                               out<<usrlist[i].name<<" "<<usrlist[i].password<<" "<<usrlist[i].times<<" "<<usrlist[i].correct<<" "
                                 <<usrlist[i].time<<endl;
                               }
                               //file1.flush();
                               file1.close();
                           }else{
                               qDebug()<<file1.errorString()<<endl;
                           }

                   QMessageBox::information(this,tr("考试结果"),reci);
               }

               tim->QObject::destroyed();
               exam.clear();
               num=0;
               score=0;
               ansSheet.clear();

               this->close();
               delete tim;
               Model_Choose*pic=new Model_Choose();
               pic->show();
               return;
           }

}



void FormalQuiz::on_next_clicked()
{
    QChar ans;
    if(!ui->A->isChecked()&&!ui->B->isChecked()&&!ui->C->isChecked()){
        QMessageBox::critical(this,tr("提示"),tr("您需要选出选项再进行下一题"));
       return;
    }
    if(ui->A->isChecked())ans='A';
    if(ui->B->isChecked())ans='B';
    if(ui->C->isChecked())ans='C';
    ansSheet<<ans;
    num++;
    ans=0;

    if(time.second()!=0){


         if(num==num_of_ex){

             tim->stop();
             QMessageBox::information(this,tr("考试结束"),tr("您已答完全部题目"));

             if(mode==2){
                 QString reci;
                 for(int i=0;i<ansSheet.size();i++){
                     if(ansSheet[i]==exam[i].answer)score++;
                     else{
                         reci+="您答错了："+exam[i].quest+"\n"+exam[i].option+"\n"+"您的答案是："+QString(ansSheet[i])+"   正确答案是："+QString(exam[i].answer)+"\n";
                     }
                 }

                 reci+="您的成绩：答对"+QString::number(score)+"题\n";
                 reci+="用时："+QString::number(30.000-time.second()-(double)time.msec()/1000)+"秒";
                 QMessageBox::information(this,tr("考试结果"),reci);
             }

             if(mode==1){
                 QString reci;
                 for(int i=0;i<ansSheet.size();i++){
                     if(ansSheet[i]==exam[i].answer)score++;
                 }

                 double resultTime=30.000-time.second()-(double)time.msec()/1000;
                 reci+="您的成绩：答对"+QString::number(score)+"题\n";
                 reci+="用时："+QString::number(resultTime)+"秒";

                 succeed.times++;
                 if(succeed.correct<score){
                     succeed.correct=score;
                     succeed.time=resultTime;
                 }

                 else if(succeed.correct==score){
                     if(succeed.time>resultTime)succeed.time=resultTime;
                 }

                 if(succeed.times==1)succeed.time=resultTime;

                 for(int i=0;i<usrlist.size();i++){
                     if(succeed.name==usrlist[i].name){
                         usrlist[i]=succeed;
                         break;
                     }
                 }

                 QFile file1("user.txt");
                         if(file1.open(QIODevice::WriteOnly|QIODevice::Truncate)){
                             QTextStream out(&file1);
                             out.setCodec("UTF-8");
                             for(int i=0;i<usrlist.size();i++){
                             out<<usrlist[i].name<<" "<<usrlist[i].password<<" "<<usrlist[i].times<<" "<<usrlist[i].correct<<" "
                               <<usrlist[i].time<<endl;
                             }
                             //file1.flush();
                             file1.close();
                         }else{
                             qDebug()<<file1.errorString()<<endl;
                         }


                 QMessageBox::information(this,tr("考试结果"),reci);
             }

             exam.clear();
             num=0;
             ans=0;
             score=0;
             ansSheet.clear();

             tim->QObject::destroyed();
             this->close();
             delete tim;
             Model_Choose*pic=new Model_Choose();
             pic->show();
             return;

         }


         else  if(num<num_of_ex){
             QString qs=exam[num].quest+"\n\n"+exam[num].option;
             ui->paper->setText(qs);

            box->setExclusive(false);
             ui->A->setChecked(false);
             ui->B->setChecked(false);
             ui->C->setChecked(false);
            box->setExclusive(true);
         }

    }
}

