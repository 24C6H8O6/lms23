#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "secdialog.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->progressBar, SLOT(setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    // setText안에 html코드도 들어감
    ui->label->setText("Hi Seungwook");
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this, tr("THE TITLE"), tr("THis is a message"));
}


void MainWindow::on_pushButton_3_clicked()
{
//    SecDialog secdialog;
//    secdialog.setModal(true);
//    secdialog.exec();
    secdialog = new SecDialog(this);
    secdialog->show();
}

