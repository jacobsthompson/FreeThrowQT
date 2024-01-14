#include "stats.h"
#include "ui_stats.h"
#include "team.h"

#include "viewstats.h"

Stats::Stats(QWidget *parent, int id)
    : QWidget(parent)
    , ui(new Ui::Stats)
{
    ui->setupUi(this);
    player = id;
    par = parent;
    ui->playernum->setText(players[player]->getName()+" "+players[player]->getNumber());

}

Stats::~Stats()
{
    delete ui;
}

void Stats::showStats(){
    ui->tp_2->setText(players[player]->getPoints());
    ui->twop_2->setText(players[player]->get2PM()+" - "+players[player]->get2PA()+" - "+players[player]->get2PP()+"%");
    ui->threep_2->setText(players[player]->get3PM()+" - "+players[player]->get3PA()+" - "+players[player]->get3PP()+"%");
    ui->ft_2->setText(players[player]->getFTM()+" - "+players[player]->getFTA()+" - "+players[player]->getFTP()+"%");
    ui->rb_2->setText(players[player]->getRBO()+" - "+players[player]->getRBD()+" - "+players[player]->getRBT());
    ui->ass_2->setText(players[player]->getAST());
    ui->stl_2->setText(players[player]->getSTL());
    ui->blk_2->setText(players[player]->getBLK());
    ui->turn_2->setText(players[player]->getTRN());
    ui->fouls_2->setText(players[player]->getFLS());
}

void Stats::on_pushButton_clicked()
{
    ui->playernum->hide();
    ui->tp->hide();
    ui->twop->hide();
    ui->threep->hide();
    ui->ft->hide();
    ui->rb->hide();
    ui->ass->hide();
    ui->stl->hide();
    ui->blk->hide();
    ui->turn->hide();
    ui->fouls->hide();
    ui->tp_2->hide();
    ui->twop_2->hide();
    ui->threep_2->hide();
    ui->ft_2->hide();
    ui->rb_2->hide();
    ui->ass_2->hide();
    ui->stl_2->hide();
    ui->blk_2->hide();
    ui->turn_2->hide();
    ui->fouls_2->hide();
    ui->twoamp->hide();
    ui->threeamp->hide();
    ui->ftamp->hide();
    ui->rbofdt->hide();
    ui->pushButton->hide();
    par = new ViewStats(par);
    par->show();

}

