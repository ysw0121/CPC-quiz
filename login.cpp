#include "login.h"
#include "ui_login.h"
#include"mainwindow.h"
#include"model_choose.h"
#include"usr_info.h"
#include<QList>
#include<QMessageBox>



user succeed;
extern QList<user>usrlist;

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    ui->password->setEchoMode(QLineEdit:: Password);
}

login::~login()
{
    delete ui;
}

void login::on_return_2_clicked()
{
    this->close();
    MainWindow*pic=new MainWindow();
    pic->show();
}


void login::on_log_clicked()
{
    int flag=0;
    for(int i=0;i<usrlist.size();i++){
        if(ui->name->text()==usrlist[i].name&&ui->password->text()==usrlist[i].password){
            succeed=usrlist[i];
            flag=1;
            this->close();
            Model_Choose*pic=new Model_Choose();
            pic->show();
            return;
        }
    }
    if(flag==0){
        QMessageBox::critical(this,tr("警告"),tr("账号或密码错误，请改正或检查是否已注册！"));
        return;
    }

}


void login::on_showpsw_clicked(bool checked)
{
    if(checked){
         ui->password->setEchoMode(QLineEdit:: Normal);
    }
    else ui->password->setEchoMode(QLineEdit:: Password);
}

