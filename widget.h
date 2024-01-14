#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "startgame.h"
#include "editplayers.h"
#include "viewstats.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void setScreen(int screen);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget *ui;
    StartGame *startgame;
    EditPlayers *editplayers;
    ViewStats *viewstats;
};

#endif // WIDGET_H
