#include "addplayer.h"
#include "ui_addplayer.h"

#include "editplayers.h"
#include "team.h"
#include <QFile>

addplayer::addplayer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addplayer)
{
    par = parent;
    ui->setupUi(this);
    ui->label_6->hide();
}

addplayer::~addplayer()
{
    delete ui;
}


void addplayer::on_pushButton_clicked()
{
    ui->label_3->hide();
    ui->label_6->hide();
    ui->pushButton->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    par = new EditPlayers(par);
    par->show();
}


void addplayer::on_lineEdit_textChanged(const QString &arg1)
{
    name = ui->lineEdit->text();
}


void addplayer::on_lineEdit_2_textChanged(const QString &arg1)
{
    number = ui->lineEdit_2->text();
}

void addplayer::save(QString n, QString num, QString p, QString tpa, QString tpm, QString thpa, QString thpm, QString fta, QString ftm, QString rbo, QString rbd, QString ass, QString stl, QString blk, QString trn, QString foul){
    QString address = qApp->applicationDirPath();
    QString addressdel = "FreeThrowApp.app";
    QString addy = address.left(address.indexOf(addressdel));
    addy += "savedata.txt";
    QFile inputFile(addy);
    if (inputFile.open(QIODevice::ReadWrite)){
        QTextStream in(&inputFile);
        while(!in.atEnd()){
            QString line = in.readLine();
        }
        in << n << " " << num << " " << p << " " << tpa << " " << tpm << " " << thpa << " " << thpm << " " << fta << " " << ftm << " " << rbo << " " << rbd << " " << ass << " " << stl << " " << blk << " " << trn << " " << foul << "\n";
        inputFile.close();
    }
}


void addplayer::on_pushButton_2_clicked()
{
    if(name == "" || number == ""){
        ui->label_6->show();
    } else {
        players.push_back(new Player(name,number));
        save(name,number,"0","0","0","0","0","0","0","0","0","0","0","0","0","0");
        ui->label_3->hide();
        ui->label_6->hide();
        ui->pushButton->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->lineEdit->hide();
        ui->lineEdit_2->hide();
        par = new EditPlayers(par);
        par->show();
    }
}

