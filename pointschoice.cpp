#include "pointschoice.h"
#include "ui_pointschoice.h"

#include "startgame.h"
#include "team.h"

#include <QFile>

PointsChoice::PointsChoice(QWidget *parent, int id, int type)
    : QWidget(parent)
    , ui(new Ui::PointsChoice)
{
    ui->setupUi(this);
    par = parent;
    pointtype = type;
    player = id;
    if(type == 0){
        ui->label->setText("2 POINTS FG");
    } else if(type == 1){
        ui->label->setText("3 POINTS FG");
    } else if(type == 2){
        ui->label->setText("FREE THROW");
    } else if(type == 3){
        ui->label->setText("REBOUND");
        ui->pushButton->setText("OFFENSE");
        ui->pushButton_2->setText("DEFENSE");
    }
}

PointsChoice::~PointsChoice()
{
    delete ui;
}

void PointsChoice::on_pushButton_clicked()
{
    if(pointtype == 0){
        players[player]->set2PM();
    } else if(pointtype == 1){
        players[player]->set3PM();
    } else if(pointtype == 2){
        players[player]->setFTM();
    } else if(pointtype == 3){
        players[player]->setRBO();
    }

    save(
        players[player]->getName(),players[player]->getNumber(),
        players[player]->getPoints(),players[player]->get2PA(),
        players[player]->get2PM(),players[player]->get3PA(),
        players[player]->get3PM(),players[player]->getFTA(),
        players[player]->getFTM(),players[player]->getRBO(),
        players[player]->getRBD(),players[player]->getAST(),
        players[player]->getSTL(),players[player]->getBLK(),
        players[player]->getTRN(),players[player]->getFLS()
        );

    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    par = new StartGame(par);
    par->show();
}


void PointsChoice::on_pushButton_2_clicked()
{
    if(pointtype == 0){
        players[player]->set2PA();
    } else if(pointtype == 1){
        players[player]->set3PA();
    } else if(pointtype == 2){
        players[player]->setFTA();
    } else if(pointtype == 3){
        players[player]->setRBD();
    }

    save(
        players[player]->getName(),players[player]->getNumber(),
        players[player]->getPoints(),players[player]->get2PA(),
        players[player]->get2PM(),players[player]->get3PA(),
        players[player]->get3PM(),players[player]->getFTA(),
        players[player]->getFTM(),players[player]->getRBO(),
        players[player]->getRBD(),players[player]->getAST(),
        players[player]->getSTL(),players[player]->getBLK(),
        players[player]->getTRN(),players[player]->getFLS()
        );

    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    par = new StartGame(par);
    par->show();
}


void PointsChoice::on_pushButton_3_clicked()
{
    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    par = new StartGame(par);
    par->show();
}

void PointsChoice::save(QString n, QString num, QString p, QString tpa, QString tpm, QString thpa, QString thpm, QString fta, QString ftm, QString rbo, QString rbd, QString ass, QString stl, QString blk, QString trn, QString foul){
    QString address = qApp->applicationDirPath();
    QString addressdel = "FreeThrowApp.app";
   QString addy = address.left(address.indexOf(addressdel));
    addy += "savedata.txt";
    QFile inputFile(addy);
    if (inputFile.open(QIODevice::ReadWrite)){
        QTextStream in(&inputFile);
        QString s;
        while (!in.atEnd()){
            QString line = in.readLine();
            if(!(line.contains(n)&&line.contains(num))){
                s.append(line+"\n");
            } else {
                s.append(n + " " + num + " " + p + " " + tpa + " " + tpm + " " + thpa + " " + thpm + " " + fta + " " + ftm + " " + rbo + " " + rbd + " " + ass + " " + stl + " " + blk + " " + trn + " " + foul + "\n");
            }
        }
        inputFile.resize(0);
        in << s;
        inputFile.close();
    }
}
