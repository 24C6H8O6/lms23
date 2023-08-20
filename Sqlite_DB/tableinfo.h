#ifndef TABLEINFO_H
#define TABLEINFO_H

#include <QDialog>
#include "login.h"
namespace Ui {
class TableInfo;
}

class TableInfo : public QDialog
{
    Q_OBJECT

public:
    Login conn;
    explicit TableInfo(QWidget *parent = nullptr);
    ~TableInfo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TableInfo *ui;
};

#endif // TABLEINFO_H
