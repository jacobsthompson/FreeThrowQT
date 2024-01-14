#include <QApplication>
#include "widget.h"
#include "team.h"

#include <QFile>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    QString address = qApp->applicationDirPath();
    QString addressdel = "FreeThrowApp.app";
    QString addy = address.left(address.indexOf(addressdel));
    addy += "savedata.txt";

    QFile inputFile(addy);
    if (inputFile.open(QIODevice::ReadOnly)){
        QTextStream in(&inputFile);
        while (!in.atEnd()){
            QString line = in.readLine();
            QStringList playerdata = line.split(" ");
            players.push_back(new Player(playerdata[0],playerdata[1],playerdata[2].toInt(),
                                         playerdata[3].toInt(),playerdata[4].toInt(),playerdata[5].toInt(),playerdata[6].toInt(),playerdata[7].toInt(),
                                         playerdata[8].toInt(),playerdata[9].toInt(),playerdata[10].toInt(),playerdata[11].toInt(),playerdata[12].toInt(),
                                         playerdata[13].toInt(),playerdata[14].toInt(),playerdata[15].toInt()));
        }
        inputFile.close();
    }


    return a.exec();
}
