#ifndef TEAM_H
#define TEAM_H
#include <dsstring.h>
#include <fstream>
#include "player.h"

using namespace std;

class Team
{
private:
    //array of Players
    Player *player;
    int teamScoreA;
    int teamScoreB;

public:

    int size;
    DSString name;
    int score;

    Team();
    int getTeamSize();
    void setTeamName(DSString name);
    DSString getTeamName();
    void setScore(int score);
    int getScore();
    int incrementScore(int incrementAmount);


};
#endif // TEAM_H
