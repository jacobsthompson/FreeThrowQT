#include "viewstats.h"
#include "ui_viewstats.h"
#include "widget.h"

#include "team.h"

ViewStats::ViewStats(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ViewStats)
{
    par = parent;
    ui->setupUi(this);
    playerList();
}

ViewStats::~ViewStats()
{
    delete ui;
}

void ViewStats::playerList(){
    int level = 0;
    int place = 0;

    QFont font = ui->pushButton->font();
    font.setPointSize(30);

    for(int i = 0; i < players.size(); i++){
        QPushButton* button = new QPushButton(this);
        button->setText(players[i]->getNumber());

        if(i % 3 == 0 && i != 0){
            level++;
        }

        if(place == 3){
            place = 0;
        }

        button->setGeometry(50+(147*place),150+level*100,146,100);
        button->setFont(font);
        place++;

        buttons.addButton(button,i);
    }

    connect(&buttons, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(buttonGotPressed(QAbstractButton*)));

}

void ViewStats::buttonGotPressed(QAbstractButton* b){
    int id = buttons.id(b);
    clearScreen();
    stats = new Stats(this,id);
    stats->showStats();
    stats->show();
}

void ViewStats::on_pushButton_clicked()
{
    clearScreen();
    par = new Widget(par);
    par->show();
}

void ViewStats::clearScreen(){
    for(int i = 0; i < players.size(); i++){
        buttons.button(i)->hide();
    }
    ui->label_3->hide();
    ui->pushButton->hide();
}

