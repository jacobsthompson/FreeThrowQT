#include "widget.h"
#include "ui_widget.h"
#include "startgame.h"
#include "editplayers.h"
#include "viewstats.h"
#include <QPalette>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    ui->label->hide();
    ui->label_2->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    startgame = new StartGame(this);
    startgame->show();
}


void Widget::on_pushButton_2_clicked()
{
    ui->label->hide();
    ui->label_2->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    editplayers = new EditPlayers(this);
    editplayers->show();
}


void Widget::on_pushButton_3_clicked()
{
    ui->label->hide();
    ui->label_2->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    viewstats = new ViewStats(this);
    viewstats->show();
}

