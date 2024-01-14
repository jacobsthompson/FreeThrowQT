#ifndef STATS_H
#define STATS_H

#include <QWidget>

namespace Ui {
class Stats;
}

class Stats : public QWidget
{
    Q_OBJECT

public:
    explicit Stats(QWidget *parent = nullptr, int id = 0);
    ~Stats();

    void showStats();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Stats *ui;
    int player;
    QWidget* par;
};

#endif // STATS_H
