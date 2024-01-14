#ifndef VIEWSTATS_H
#define VIEWSTATS_H

#include <QWidget>
#include <QButtonGroup>
#include "stats.h"

namespace Ui {
class ViewStats;
}

class ViewStats : public QWidget
{
    Q_OBJECT

public:
    explicit ViewStats(QWidget *parent = nullptr);
    ~ViewStats();

    void playerList();
    void clearScreen();

private slots:
    void on_pushButton_clicked();
    void buttonGotPressed(QAbstractButton* b);

private:
    Ui::ViewStats *ui;
    QWidget* par;
    QButtonGroup buttons;
    Stats* stats;
};

#endif // VIEWSTATS_H
