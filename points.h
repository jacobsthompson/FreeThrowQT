#ifndef POINTS_H
#define POINTS_H

#include <QWidget>
#include "pointschoice.h"


namespace Ui {
class Points;
}

class Points : public QWidget
{
    Q_OBJECT

public:
    explicit Points(QWidget *parent = nullptr, int id = 0);
    ~Points();

    void clearScreen();
    void save(QString n, QString num, QString p, QString tpa, QString tpm, QString thpa, QString thpm, QString fta, QString ftm, QString rbo, QString rbd, QString ass, QString stl, QString blk, QString trn, QString foul);

private slots:

    void on_twop_clicked();

    void on_threep_clicked();

    void on_ft_clicked();

    void on_rb_clicked();

    void on_ass_clicked();

    void on_steal_clicked();

    void on_blk_clicked();

    void on_turn_clicked();

    void on_foul_clicked();

    void on_back_clicked();

private:
    Ui::Points *ui;
    int player;
    QWidget* par;
    PointsChoice* pointschoice;
};

#endif // POINTS_H
