#include "startgame.h"
#include "ui_startgame.h"
#include "widget.h"
#include "team.h"

#include <QButtonGroup>
#include <QObject>
#include <QFont>

StartGame::StartGame(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartGame)
{
    par = parent;
    ui->setupUi(this);
    playerList();
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::playerList(){
    int level = 0;
    int place = 0;
    QFont font = ui->pushButton_3->font();
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

void StartGame::buttonGotPressed(QAbstractButton* b){
    int id = buttons.id(b);
    clearScreen();
    points = new Points(this,id);
    points->show();
}

void StartGame::on_pushButton_3_clicked()
{
    clearScreen();
    par = new Widget(par);
    par->show();
}

void StartGame::clearScreen(){
    for(int i = 0; i < ht.teamSize(); i++){
        buttons.button(i)->hide();
    }
    ui->pushButton_3->hide();
    ui->label_3->hide();
}
