#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
// 창
//    void about
// Question 창
//    void aboutQt
// 창에 그림으로 나오는 아래 4가지
//    StandardButton critical
//    StandardButton information
//    StandardButton question
//    StandardButton warning

    // this : parent class
//    QMessageBox::about(this, "My Title", "This is my custom message");
//    QMessageBox::aboutQt(this, "My Title");
//    QMessageBox::critical(this, "My Title", "This is my custom message");
//    QMessageBox::information(this, "My Title", "This is my custom message");
//    QMessageBox::question(this, "My Title", "This is my custom message");
    QMessageBox::StandardButton reply= QMessageBox::question(this, "My Title", "This is my custom message", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    } else{
        qDebug() << "No is clicked";
    }
}

