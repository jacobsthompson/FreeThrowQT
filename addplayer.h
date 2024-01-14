#ifndef ADDPLAYER_H
#define ADDPLAYER_H

#include <QWidget>

namespace Ui {
class addplayer;
}

class addplayer : public QWidget
{
    Q_OBJECT

public:
    explicit addplayer(QWidget *parent = nullptr);
    ~addplayer();
    void save(QString n, QString num, QString p, QString tpa, QString tpm, QString thpa, QString thpm, QString fta, QString ftm, QString rbo, QString rbd, QString ass, QString stl, QString blk, QString trn, QString foul);

private slots:

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

private:
    Ui::addplayer *ui;
    QWidget* par;
    QString name;
    QString number;
};

#endif // ADDPLAYER_H
