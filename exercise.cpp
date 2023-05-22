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


extern QList<question>questionlist;
int prnum;
question temp;
QButtonGroup*box;


Exercise::Exercise(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Exercise)
{
    ui->setupUi(this);
    QMessageBox msgBox;
    msgBox.setStyleSheet("QLable{font:24px;}");
    msgBox.setWindowTitle("练习说明");
    msgBox.setText("练习时选择左下角选项，点击确定则提交答案，系统判定正误\n"
                   "如需退出点击\"结束练习\"按钮");

    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();

    this->setWindowTitle("练习模式");

    box=new QButtonGroup;
    box->setExclusive(true);
    box->addButton(ui->A);
    box->addButton(ui->B);
    box->addButton(ui->C);

    prnum=QRandomGenerator::global()->bounded(199);
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
    if(ui->A->isChecked())ans='A';
    if(ui->B->isChecked())ans='B';
    if(ui->C->isChecked())ans='C';
    qDebug()<<ans;
}

