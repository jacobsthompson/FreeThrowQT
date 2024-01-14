#include "points.h"
#include "ui_points.h"
#include "team.h"

#include <QFile>
#include "startgame.h"
#include "pointschoice.h"

Points::Points(QWidget *parent, int id)
    : QWidget(parent)
    , ui(new Ui::Points)
{
    ui->setupUi(this);
    player = id;
    par = parent;
}

Points::~Points()
{
    delete ui;
}

void Points::clearScreen(){
    ui->label_3->hide();
    ui->back->hide();
    ui->twop->hide();
    ui->threep->hide();
    ui->blk->hide();
    ui->ft->hide();
    ui->rb->hide();
    ui->foul->hide();
    ui->turn->hide();
    ui->steal->hide();
    ui->ass->hide();
}

void Points::on_twop_clicked()
{
    clearScreen();
    pointschoice = new PointsChoice(par,player,0);
    pointschoice->show();
}


void Points::on_threep_clicked()
{
    clearScreen();
    pointschoice = new PointsChoice(par,player,1);
    pointschoice->show();
}


void Points::on_ft_clicked()
{
    clearScreen();
    pointschoice = new PointsChoice(par,player,2);
    pointschoice->show();
}


void Points::on_rb_clicked()
{
    clearScreen();
    pointschoice = new PointsChoice(par,player,3);
    pointschoice->show();
}


void Points::on_ass_clicked()
{
    players[player]->setAST();

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

    clearScreen();
    par = new StartGame(this);
    par->show();
}


void Points::on_steal_clicked()
{
    players[player]->setSTL();

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

    clearScreen();
    par = new StartGame(this);
    par->show();
}


void Points::on_blk_clicked()
{
    players[player]->setBLK();

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

    clearScreen();
    par = new StartGame(this);
    par->show();
}


void Points::on_turn_clicked()
{
    players[player]->setTRN();

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

    clearScreen();
    par = new StartGame(this);
    par->show();
}


void Points::on_foul_clicked()
{
    players[player]->setFLS();

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

    clearScreen();
    par = new StartGame(this);
    par->show();
}


void Points::on_back_clicked()
{
    clearScreen();
    par = new StartGame(this);
    par->show();
}

void Points::save(QString n, QString num, QString p, QString tpa, QString tpm, QString thpa, QString thpm, QString fta, QString ftm, QString rbo, QString rbd, QString ass, QString stl, QString blk, QString trn, QString foul){
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
