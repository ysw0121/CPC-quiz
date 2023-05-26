#include "mainwindow.h"
#include<QString>
#include<QDebug>
#include<QTextStream>
#include<QFile>
#include<QList>
#include"usr_info.h"
#include <QApplication>
#include<QTimer>

QList<user>usrlist;

QList<question>questionlist;

//QList<user>Ranklist;

extern user succeed;


int main(int argc, char *argv[])
{
#if (QT_VERSION >= QT_VERSION_CHECK(5,12,12))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QFile file("user.txt");
         bool isok = file.open(QIODevice::ReadOnly|QIODevice::Text);
         if(isok==true){
             QTextStream in(&file);
             in.setCodec("UTF-8");
             QStringList ls;
             QString str;
             QString s1,s2;

             int f1,f2;
             double f3;
             str=in.readLine();
             //str.remove(QChar('\n'), Qt::CaseInsensitive);
              if(str!=""){
             ls=str.split(" ",QString::SkipEmptyParts);
             s1=ls[0];s2=ls[1];
             f1=ls[2].toInt();
             f2=ls[3].toInt();
             f3=ls[4].toDouble();
             for(int i=0;i<ls.size();i++)qDebug()<<ls[i];
             user u;
            u.name=s1;u.password=s2;
            u.times=f1;u.correct=f2;u.time=f3;
             usrlist<<u;
              }
                while(!in.atEnd()){
                    str.clear();
                    ls.clear();
                    str=in.readLine();
                    if(str!=""){
                   ls=str.split(" ",QString::SkipEmptyParts);
                   s1=ls[0];s2=ls[1];
                   f1=ls[2].toInt();
                   f2=ls[3].toInt();
                   f3=ls[4].toDouble();
                   user u;
                  u.name=s1;u.password=s2;
                  u.times=f1;u.correct=f2;u.time=f3;
                   usrlist<<u;
                    }
                }

         }for(int i=0;i<usrlist.size();i++)qDebug()<<usrlist[i].name<<usrlist[i].time;
         if(!isok) qDebug()<<"error";
          file.close();

          QFile file1("exam.txt");
          bool isok1=file1.open(QIODevice::ReadOnly|QIODevice::Text);
          if(isok1==true){
              QTextStream in(&file1);
              in.setCodec("UTF-8");
              QStringList ls;
              QString s1,s2;
              s1=in.readLine();
              s2=in.readLine();
              if(s1!=""&&s2!=""){
                  s1.replace(" ","");
                  ls=s1.split(".",QString::SkipEmptyParts);
                  question que;
                  que.option=s2;
                  int pos=ls[1].indexOf("A")+ls[1].indexOf("B")+ls[1].indexOf("C")+2;
                  que.answer=ls[1][pos];
                  que.quest=ls[1].replace("A","__");
                  que.quest=ls[1].replace("B","__");
                  que.quest=ls[1].replace("C","__");
                  questionlist<<que;
              }
              while(!in.atEnd()){
                  ls.clear();s1.clear();s2.clear();
                  s1=in.readLine();
                  s2=in.readLine();
                  if(s1!=""&&s2!=""){
                      ls=s1.split(".",QString::SkipEmptyParts);
                      question que;
                      que.option=s2;
                      int pos=ls[1].indexOf("A")+ls[1].indexOf("B")+ls[1].indexOf("C")+2;
                      que.answer=ls[1][pos];
                      que.quest=ls[1].replace("A","__");
                      que.quest=ls[1].replace("B","__");
                      que.quest=ls[1].replace("C","__");
                      questionlist<<que;
                  }
              }
          }for(int i=0;i<5;i++)qDebug()<<questionlist[i].quest<<questionlist[i].answer<<questionlist[i].option;
          if(!isok1)qDebug()<<"error";
          file1.close();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
    return 0;
}
