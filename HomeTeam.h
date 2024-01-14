#ifndef HOMETEAM_H
#define HOMETEAM_H

#include "AbstractTeam.h"
#include "team.h"

class HomeTeam : public AbstractTeam{
public:
    HomeTeam(){}
    int teamSize(){
        return players.size();
    }
};

#endif // HOMETEAM_H
