#include "editplayers.h"
#include "team.h"
#include "ui_editplayers.h"

#include "widget.h"

EditPlayers::EditPlayers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EditPlayers)
{
    par = parent;
    ui->setupUi(this);
    ui->label_4->hide();
}

EditPlayers::~EditPlayers()
{
    delete ui;
}

void EditPlayers::on_pushButton_3_clicked()
{
    ui->label_3->hide();
    ui->label_4->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    par = new Widget(par);
    par->show();
}


void EditPlayers::on_pushButton_clicked()
{
    if(ht.teamSize() > 14){
        ui->label_4->show();
    } else {
        ui->label_3->hide();
        ui->label_4->hide();
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        addplayers = new addplayer(this);
        addplayers->show();
    }
}


void EditPlayers::on_pushButton_2_clicked()
{
    ui->label_3->hide();
    ui->label_4->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    removeplayers = new RemovePlayer(this);
    removeplayers->show();
}

