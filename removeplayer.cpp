#include "removeplayer.h"
#include "ui_removeplayer.h"

#include "team.h"
#include "editplayers.h"
#include "Player.h"

#include <QFile>

RemovePlayer::RemovePlayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemovePlayer)
{
    ui->setupUi(this);
    par = parent;
}

RemovePlayer::~RemovePlayer()
{
    delete ui;
}

void RemovePlayer::on_pushButton_2_clicked()
{
    clicked++;
    if(clicked == 1){
        ui->pushButton_2->setText("ARE YOU SURE?");
    } else if(clicked == 2){
        int numtodel = ht.teamSize()-1;
        for(int i = numtodel; i >= 0; i--){
            Player* temp = players[i];
            players.pop_back();
            delete temp;
        }

        QString address = qApp->applicationDirPath();
        QString addressdel = "FreeThrowApp.app";
        QString addy = address.left(address.indexOf(addressdel));
        addy += "savedata.txt";
        QFile inputFile(addy);
        inputFile.resize(0);

        ui->label->hide();
        ui->pushButton->hide();
        ui->pushButton_2->hide();
        ui->pushButton_3->hide();
        par = new EditPlayers(par);
        par->show();
    }
}


void RemovePlayer::on_pushButton_3_clicked()
{
    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    par = new EditPlayers(par);
    par->show();
}


void RemovePlayer::on_pushButton_clicked()
{
    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    removeone = new RemoveOne(this);
    removeone->show();
}

