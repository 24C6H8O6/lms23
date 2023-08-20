#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "secdialog.h"
#include "tableinfo.h"
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/user/OneDrive/바탕 화면/hsu_image.JPG");
    ui->label_pic->setPixmap(pix);

    if(!connOpen())
        ui->label->setText("Failed to open the database");
    else
        ui->label->setText("Connected.....");
}

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked()
{
    QString username,password;
    username = ui->lineEdit_Username->text();
    password = ui->lineEdit_Password->text();

    if(!connOpen()){
        qDebug() << "Failed to open the database";
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from NewTable where username='"+ username +"' and password='"+ password +"'");


    if(qry.exec())
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->label->setText("username and password is correct");
            connClose();
            QMessageBox::information(this, tr("로그인"), tr("로그인 성공!!"));
            this->hide();
//            secdialog = new SecDialog(this);
//            secdialog->show();
//            tableinfo = new TableInfo(this);
//            tableinfo->show();
            TableInfo tableinfo;
            tableinfo.setModal(true);
            tableinfo.exec();
        }


        if(count>1)
        {
            ui->label->setText("Duplicate username and password is correct");
            QMessageBox::warning(this, tr("로그인 에러"), tr("아이디,비밀번호 중복..."));
        }

        if(count<1)
        {
            ui->label->setText("username and password is not correct");
            QMessageBox::warning(this, tr("로그인 에러"), tr("로그인 실패...."));
        }
    }
}

