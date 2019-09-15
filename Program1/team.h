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
    int teamScore;

public:

    Team();
    int getTeamSize(int size);
    void setTeamName(DSString name);
    DSString getTeamName(DSString name);
    void setScore(int score);
    int getScore(int score);
    int incrementScore(int incrementSize);


};
#endif // TEAM_H
