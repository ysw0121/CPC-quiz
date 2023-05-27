#include "register.h"
#include "ui_register.h"
#include"mainwindow.h"
#include"login.h"
#include<QMessageBox>
#include<QLineEdit>
#include<QString>
#include"usr_info.h"
#include<QFile>
#include<QDebug>
#include<QTextStream>

extern QList<user>usrlist;

extern QList<question>questionlist;

extern QList<user>Ranklist;

extern user succeed;



Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowTitle("注册");
    ui->password->setEchoMode(QLineEdit:: Password);
}

Register::~Register()
{
    delete ui;
}

void Register::on_return_2_clicked()
{
    this->close();
    MainWindow*pic=new MainWindow();
    pic->show();
}


void Register::on_certain_clicked()
{

    if(ui->nwarning->text()=="用户名格式正确！"&&ui->pwarning->text()=="密码格式正确！"){
        QString nme=ui->name->text(),psw=ui->password->text();
        user u;
        u.name=nme;
        u.password=psw;
        u.correct=0;
        u.times=0;
        u.time=31.000;
        usrlist<<u;
        QFile file1("user.txt");
                  if(file1.open(QIODevice::WriteOnly|QIODevice::Append)){
                      QTextStream out(&file1);
                      out.setCodec("UTF-8");
                      out<<QString(nme)<<" "<<QString(psw)<<" 0 0 31.000"<<endl;
                      file1.close();
                  }else{
                      qDebug()<<file1.errorString()<<endl;
                  }

        QMessageBox::information(this,tr(""),tr("注册成功，请登录。"));
        this->close();
        login *pic=new login();
        pic->show();
    }
    else{
        QMessageBox::critical(this,tr("警告"),tr("信息不符合规范，请改正！"));
        return;
    }

}


void Register::on_name_textEdited(const QString &arg1)
{
    if(ui->name->text()==""){
        ui->nwarning->setText("用户名不能为空！");
        ui->nwarning->setStyleSheet("color: rgb(255, 78, 25);");
    }
    else if(ui->name->text().size()>20){
        ui->nwarning->setText("用户名不能为过长！");
        ui->nwarning->setStyleSheet("color: rgb(255, 78, 25);");
    }
    else if(ui->name->text().indexOf(" ")!=-1){
        ui->nwarning->setText("用户名不能含空格！");
        ui->nwarning->setStyleSheet("color: rgb(255, 78, 25);");
    }
    else{
        int fla=1;
        for(int i=0;i<usrlist.size();i++){
            if(usrlist[i].name==ui->name->text()){
                ui->nwarning->setText("用户名不能与别人重复！");
                ui->nwarning->setStyleSheet("color: rgb(255, 78, 25);");
                fla=0;
            }
        }
        if(fla==1){
            ui->nwarning->setText("用户名格式正确！");
            ui->nwarning->setStyleSheet("color: rgb(0,255, 25);");
        }
    }

}


void Register::on_password_textEdited(const QString &arg1)
{
    if(ui->password->text()==""){
        ui->pwarning->setText("密码不能为空！");
        ui->pwarning->setStyleSheet("color: rgb(255, 78, 25);");
    }
    else if(ui->password->text().size()<8){
        ui->pwarning->setText("密码不能少于8位！");
        ui->pwarning->setStyleSheet("color: rgb(255, 78, 25);");
    }
    else if(ui->password->text().size()>20){
        ui->pwarning->setText("密码不能为过长！");
        ui->pwarning->setStyleSheet("color: rgb(255, 78, 25);");
    }
    else if(ui->password->text().indexOf(" ")!=-1){
        ui->pwarning->setText("密码不能含空格！");
        ui->pwarning->setStyleSheet("color: rgb(255, 78, 25);");
    }
    else{
            ui->pwarning->setText("密码格式正确！");
            ui->pwarning->setStyleSheet("color: rgb(0,255, 25);");
    }


}


void Register::on_showpsw_clicked(bool checked)
{
    if(checked){
         ui->password->setEchoMode(QLineEdit:: Normal);
    }
    else ui->password->setEchoMode(QLineEdit:: Password);
}

