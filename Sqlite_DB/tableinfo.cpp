#include "tableinfo.h"
#include "ui_tableinfo.h"
#include <QMessageBox>
TableInfo::TableInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableInfo)
{
    ui->setupUi(this);
    Login conn;
    if(!conn.connOpen())
        ui->label_sec_status->setText("Failed to open the database");
    else
        ui->label_sec_status->setText("Connected.....");
}

TableInfo::~TableInfo()
{
    delete ui;
}

void TableInfo::on_pushButton_clicked()
{
    Login conn;
    QString eid, name, surname, age;
    eid = QString::number(ui->text_age->text().toInt());
    name = ui->text_name->text();
    surname = ui->text_surname->text();
    age = QString::number(ui->text_age->text().toInt());


    if(!conn.connOpen()){
        qDebug() << "Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM NewTable WHERE eid=:eid");
    checkQuery.bindValue(":eid", eid);
    checkQuery.exec();
    checkQuery.next();
    int count = checkQuery.value(0).toInt();

    if (count == 0) {
        // eid 값이 존재하지 않는 경우 INSERT 쿼리문 실행
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO NewTable (eid, name, surname, age) VALUES (:eid, :name, :surname, :age)");
        insertQuery.bindValue(":eid", eid);
        insertQuery.bindValue(":name", name);
        insertQuery.bindValue(":surname", surname);
        insertQuery.bindValue(":age", age);

        if (insertQuery.exec()) {
            QMessageBox::information(this, "Success", "Record added successfully.");
        } else {
            QMessageBox::warning(this, "Error", "Record not added.");
        }
    } else {
        // eid 값이 이미 존재하는 경우 오류 메시지 표시
        QMessageBox::warning(this, "Error", "Record already exists.");
    }


/*
//    qry.prepare("insert into NewTable (eid,name,surface,age) values ('"+eid+"','"+name+"','"+surname+"','"+age+"')");
    qry.prepare("insert into NewTable (eid, name, surname, age) values (:eid, :name, :surname, :age)");
    qry.prepare("insert into NewTable (surface, name, age) values (:surname, :name, :age)");
//    qry.bindValue(":eid", eid);
    qry.bindValue(":surface", surname);
    qry.bindValue(":name", name);
    qry.bindValue(":age", age);
*/

    if(qry.exec())
    {
        QMessageBox::critical(this, tr("Save"), tr("Saved"));
        conn.connClose();
    }
    else
    {
        QMessageBox::critical(this, tr("error;;"), qry.lastError().text());
    }
}

