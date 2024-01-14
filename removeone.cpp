#include "removeone.h"
#include "ui_removeone.h"

#include "removeplayer.h"
#include "team.h"

#include <QFile>

RemoveOne::RemoveOne(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RemoveOne)
{
    ui->setupUi(this);
    par = parent;
    playerList();
}

RemoveOne::~RemoveOne()
{
    delete ui;
}

void RemoveOne::playerList(){
    int level = 0;
    int place = 0;

    QFont font = ui->pushButton->font();
    font.setPointSize(30);

    for(int i = 0; i < ht.teamSize(); i++){
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

void RemoveOne::on_pushButton_clicked()
{
    for(int i = 0; i < ht.teamSize(); i++){
        buttons.button(i)->hide();
    }
    ui->label_3->hide();
    ui->pushButton->hide();
    par = new RemovePlayer(par);
    par->show();
}

void RemoveOne::buttonGotPressed(QAbstractButton* b){
    int id = buttons.id(b);

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
            QStringList playerdata = line.split(" ");
            if(!(line.contains(players[id]->getName())&&line.contains(players[id]->getNumber()))){
                s.append(line+"\n");
            }
        }
        inputFile.resize(0);
        in << s;
        inputFile.close();
    }

    Player* temp = players[id];
    players.erase(players.begin()+id);
    delete temp;

    for(int i = 0; i < ht.teamSize()+1; i++){
        buttons.button(i)->hide();
    }
    ui->label_3->hide();
    ui->pushButton->hide();
    par = new RemovePlayer(par);
    par->show();
}



