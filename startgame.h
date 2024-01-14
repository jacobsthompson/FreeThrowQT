#ifndef STARTGAME_H
#define STARTGAME_H

#include <QWidget>
#include <QButtonGroup>
#include "HomeTeam.h"
#include "points.h"

namespace Ui {
class StartGame;
}

class StartGame : public QWidget
{
    Q_OBJECT

public:
    explicit StartGame(QWidget *parent = nullptr);
    ~StartGame();

    void playerList();
    void clearScreen();
    QString name() const;

private slots:
    void on_pushButton_3_clicked();
    void buttonGotPressed(QAbstractButton* b);

private:
    Ui::StartGame *ui;
    QWidget* par;
    QButtonGroup buttons;
    Points* points;
    HomeTeam ht;
};

#endif // STARTGAME_H
