#ifndef POINTSCHOICE_H
#define POINTSCHOICE_H

#include <QWidget>


namespace Ui {
class PointsChoice;
}

class PointsChoice : public QWidget
{
    Q_OBJECT

public:
    explicit PointsChoice(QWidget *parent = nullptr, int id = 0, int type = 0);
    ~PointsChoice();

    void save(QString n, QString num, QString p, QString tpa, QString tpm, QString thpa, QString thpm, QString fta, QString ftm, QString rbo, QString rbd, QString ass, QString stl, QString blk, QString trn, QString foul);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::PointsChoice *ui;
    QWidget* par;
    int player;
    int pointtype;
};

#endif // POINTSCHOICE_H
