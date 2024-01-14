#ifndef REMOVEONE_H
#define REMOVEONE_H

#include <QWidget>
#include <QButtonGroup>
#include "HomeTeam.h"

namespace Ui {
class RemoveOne;
}

class RemoveOne : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveOne(QWidget *parent = nullptr);
    ~RemoveOne();

    void playerList();

private slots:
    void on_pushButton_clicked();
    void buttonGotPressed(QAbstractButton* b);

private:
    Ui::RemoveOne *ui;
    QWidget* par;
    QButtonGroup buttons;
    HomeTeam ht;
};

#endif // REMOVEONE_H
