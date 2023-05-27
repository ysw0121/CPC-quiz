#include "exercise.h"
#include "ui_exercise.h"
#include"model_choose.h"
#include"usr_info.h"
#include<QButtonGroup>
#include<QMessageBox>
#include<QList>
#include<QRandomGenerator>
#include<QChar>
#include<QDebug>

int exerflag;

extern QList<question>questionlist;

question temp;
QButtonGroup*box;


Exercise::Exercise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exercise)
{

    if(exerflag==1){
    QMessageBox msgBox;
    msgBox.setWindowTitle("练习说明");
    msgBox.setText("练习时选择左下角选项，点击确定则提交答案，系统判定正误，如果错误则告知答案\n"
                   "如需退出点击\"结束练习\"按钮");

    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}
    ui->setupUi(this);
    this->setWindowTitle("练习模式");
    ui->A->setChecked(false);
    ui->B->setChecked(false);
    ui->C->setChecked(false);
    box=new QButtonGroup;
    box->setExclusive(true);
    box->addButton(ui->A);
    box->addButton(ui->B);
    box->addButton(ui->C);

    int prnum=QRandomGenerator::global()->bounded(199);
    temp=questionlist[prnum];
    ui->textBrowser->setText("\n"+temp.quest+"\n\n\n"+temp.option);
}

Exercise::~Exercise()
{

    delete ui;
}

void Exercise::on_return_2_clicked()
{
    this->close();
    Model_Choose*pic=new Model_Choose();
    pic->show();
}


void Exercise::on_certain_clicked()
{

    QChar ans;
    if(!ui->A->isChecked()&&!ui->B->isChecked()&&!ui->C->isChecked()){
        QMessageBox::critical(this,tr("警告"),tr("您需要选出选项再进行下一题"));
       return;
    }
    if(ui->A->isChecked())ans='A';
    if(ui->B->isChecked())ans='B';
    if(ui->C->isChecked())ans='C';
    qDebug()<<ans;

    if(ans==temp.answer){
        QMessageBox msgBox;
        msgBox.setText("您答对了！是否进行下一题？");
        msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::No);
        int ret=msgBox.exec();
        switch(ret){
           case QMessageBox::Ok:{
            int prnum=QRandomGenerator::global()->bounded(199);
            temp=questionlist[prnum];
            ui->textBrowser->setText("\n"+temp.quest+"\n\n\n"+temp.option);

            box->setExclusive(false);
             ui->A->setChecked(false);
             ui->B->setChecked(false);
             ui->C->setChecked(false);
            box->setExclusive(true);
            break;
           }
           case QMessageBox::No:{
             this->close();
              Model_Choose*pic=new Model_Choose();
             pic->show();
             break;
           }
        }
    }
    else{
        QMessageBox msgBox;
        msgBox.setText("您答错了！正确答案是："+QString(temp.answer)+"\n是否进行下一题？");
        msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::No);
        int ret=msgBox.exec();
        switch(ret){
           case QMessageBox::Ok:{
            int prnum=QRandomGenerator::global()->bounded(199);
            temp=questionlist[prnum];
            ui->textBrowser->setText("\n"+temp.quest+"\n\n\n"+temp.option);

            box->setExclusive(false);
             ui->A->setChecked(false);
             ui->B->setChecked(false);
             ui->C->setChecked(false);
            box->setExclusive(true);

            break;
           }
           case QMessageBox::No:{
             this->close();
             Model_Choose*pic=new Model_Choose();
             pic->show();
             break;
           }
        }
    }

}

