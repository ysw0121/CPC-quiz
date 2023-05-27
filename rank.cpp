#include "rank.h"
#include "ui_rank.h"
#include"model_choose.h"
#include"usr_info.h"
#include<QString>
#include<QList>

extern QList<user>usrlist;
QList<user>Ranklist;

Rank::Rank(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rank)
{
    ui->setupUi(this);
    this->setWindowTitle("排行榜");
    ui->rankList->setEnabled(false);
    for(int i=0;i<usrlist.size();i++){
        if(usrlist[i].times!=0){
            Ranklist<<usrlist[i];
        }
    }
    for(int i=0;i<Ranklist.size();i++){//排后成绩从高到低
        for(int j=0;j<Ranklist.size()-i-1;j++){
            if(Ranklist[j].correct<Ranklist[j+1].correct){
                user temp;
                temp=Ranklist[j];
                Ranklist[j]=Ranklist[j+1];
                Ranklist[j+1]=temp;
            }
            else if(Ranklist[j].correct==Ranklist[j+1].correct){
                if(Ranklist[j].time>Ranklist[j+1].time){
                    user temp;
                    temp=Ranklist[j];
                    Ranklist[j]=Ranklist[j+1];
                    Ranklist[j+1]=temp;
                }
            }
        }
    }

    QListWidgetItem *item;
    item=new QListWidgetItem;
    QString qs;
    qs="用户    答对的题目数       用时(秒)";
    item->setText(QString(qs));
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable);
    item->setFlags(Qt::ItemIsEnabled);
    item->setCheckState(Qt::Unchecked);//默认 不选中状态
    ui->rankList->addItem(item);
    for(int i=0;i<Ranklist.size();i++){
        QListWidgetItem *item1;
        item1=new QListWidgetItem;
        QString qs1;
        qs1=Ranklist[i].name+"\t"+QString::number(Ranklist[i].correct,10)+"         \t"+QString::number(Ranklist[i].time) ;
        item1->setText(QString(qs1));
        item1->setFlags(item1->flags() & ~Qt::ItemIsSelectable);
        item1->setFlags(Qt::ItemIsEnabled);
        item1->setCheckState(Qt::Unchecked);//默认 不选中状态
        ui->rankList->addItem(item1);
    }

}

Rank::~Rank()
{
    Ranklist.clear();
    delete ui;
}

void Rank::on_return_2_clicked()
{
    Ranklist.clear();
    this->close();
    Model_Choose *pic=new Model_Choose();
    pic->show();

}

