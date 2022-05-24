#include <QLineEdit>
#include "set_name.h"
#include "ui_set_name.h"

set_name::set_name(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_name)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/app.ico"));
    flag = 0;
    name = "=";
    mode = 0;
}

set_name::~set_name()
{
    delete ui;
}

void set_name::on_quit1_clicked()
{
    exit(0);
}


void set_name::on_ok1_clicked()
{
    name = ui->textname->text();
    if(name == QString::fromLocal8Bit("")) return;
    flag = 1;
    close();
}

int set_name::check()
{
    if(flag ==0) exit(0);
    return mode;
}


void set_name::on_checkBox_stateChanged(int arg1)
{
    mode = 4;
}

void set_name::showw()
{
    this->show();
}

