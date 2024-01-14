#ifndef REMOVEPLAYER_H
#define REMOVEPLAYER_H

#include <QWidget>
#include "removeone.h"

namespace Ui {
class RemovePlayer;
}

class RemovePlayer : public QWidget
{
    Q_OBJECT

public:
    explicit RemovePlayer(QWidget *parent = nullptr);
    ~RemovePlayer();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::RemovePlayer *ui;
    QWidget* par;
    RemoveOne* removeone;
    int clicked = 0;
    HomeTeam ht;
};

#endif // REMOVEPLAYER_H
