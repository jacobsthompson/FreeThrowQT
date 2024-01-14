#ifndef EDITPLAYERS_H
#define EDITPLAYERS_H

#include <QWidget>
#include "addplayer.h"
#include "removeplayer.h"
#include "HomeTeam.h"

namespace Ui {
class EditPlayers;
}

class EditPlayers : public QWidget
{
    Q_OBJECT

public:
    explicit EditPlayers(QWidget *parent = nullptr);
    ~EditPlayers();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditPlayers *ui;
    QWidget* par;
    addplayer *addplayers;
    RemovePlayer *removeplayers;
    HomeTeam ht;
};

#endif // EDITPLAYERS_H
