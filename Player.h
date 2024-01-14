#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include <iostream>

class Player{
private:
    QString name;
    QString number;
    int points;
    int twoPointAtt, twoPointMade;
    int threePointAtt, threePointMade;
    int freeThrowAtt, freeThrowMade;
    int reboundOff, reboundDef;
    int assists, steals, blocks, turnovers, fouls;
public:
    Player(QString n, QString num){
        name = n;
        number = num;
        points = 0;
        twoPointAtt = 0;
        twoPointMade = 0;
        threePointAtt = 0;
        threePointMade = 0;
        freeThrowAtt = 0;
        freeThrowMade = 0;
        reboundOff = 0;
        reboundDef = 0;
        assists = 0;
        steals = 0;
        blocks = 0;
        turnovers = 0;
        fouls = 0;
    }

    Player(QString n, QString num, int p, int tpa, int tpm, int thpa, int thpm, int fta, int ftm, int rbo, int rbd, int ass, int stl, int blk, int trn, int foul){
        name = n;
        number = num;
        points = p;
        twoPointAtt =tpa;
        twoPointMade = tpm;
        threePointAtt = thpa;
        threePointMade = thpm;
        freeThrowAtt = fta;
        freeThrowMade = ftm;
        reboundOff = rbo;
        reboundDef = rbd;
        assists = ass;
        steals = stl;
        blocks = blk;
        turnovers = trn;
        fouls = foul;
    }

    ~Player(){};

    QString getName(){ return name; }
    QString getNumber(){ return number; }
    QString getPoints(){return QString::number(points); }
    QString get2PA(){ return QString::number(twoPointAtt); }
    QString get2PM(){ return QString::number(twoPointMade); }
    QString get3PA(){ return QString::number(threePointAtt); }
    QString get3PM(){ return QString::number(threePointMade); }
    QString getFTA(){ return QString::number(freeThrowAtt); }
    QString getFTM(){ return QString::number(freeThrowMade); }
    QString getRBO(){ return QString::number(reboundOff); }
    QString getRBD(){ return QString::number(reboundDef); }
    QString getAST(){ return QString::number(assists); }
    QString getSTL(){ return QString::number(steals); }
    QString getBLK(){ return QString::number(blocks); }
    QString getTRN(){ return QString::number(turnovers); }
    QString getFLS(){ return QString::number(fouls); }
    QString get2PP(){ return QString::number((twoPointMade*100)/(twoPointMade+twoPointAtt));}
    QString get3PP(){ return QString::number((threePointMade*100)/(threePointMade+threePointAtt));}
    QString getFTP(){ return QString::number((freeThrowMade*100)/(freeThrowMade+freeThrowAtt));}
    QString getRBT(){ return QString::number(reboundDef+reboundOff);}

    void set2PA(){ twoPointAtt++;}
    void set2PM(){ twoPointMade++; points += 2;}
    void set3PA(){ threePointAtt++;}
    void set3PM(){ threePointMade++; points += 3;}
    void setFTA(){ freeThrowAtt++;}
    void setFTM(){ freeThrowMade++; points++; }
    void setRBO(){ reboundOff++;}
    void setRBD(){ reboundDef++;}
    void setAST(){ assists++;}
    void setSTL(){ steals++;}
    void setBLK(){ blocks++;}
    void setTRN(){ turnovers++;}
    void setFLS(){ fouls++;}

    void print(){
        std::cout << number.toStdString() << " " << name.toStdString() << " : " << points << " points" << std::endl;
    }
};

#endif // PLAYER_H
