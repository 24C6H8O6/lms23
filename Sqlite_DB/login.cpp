#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "secdialog.h"
Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/user/OneDrive/바탕 화면/hsu_image.JPG");
    ui->label_pic->setPixmap(pix);

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/user/OneDrive/바탕 화면/인력개발원/db/loginsample.db");

    if(!mydb.open())
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

    if(!mydb.isOpen()){
        qDebug() << "Failed to open the database";
        return;
    }

    QSqlQuery qry;

    if(qry.exec("select * from NewTable where username='"+ username +"' and password='"+ password +"'"))
    {
        int count=0;
        while(qry.next())
        {
            count++;
        }
        if(count==1)
        {
            ui->label->setText("username and password is correct");

            QMessageBox::information(this, tr("로그인"), tr("로그인 성공!!"));
            secdialog = new SecDialog(this);
            secdialog->show();
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

