#ifndef TEAM_H
#define TEAM_H
#include <dsstring.h>
#include <fstream>
#include "player.h"

using namespace std;

class Team
{
private:

    ifstream inFile;
    DSString teamName;
    int numPlayers;
    int idNum;
    DSString* memberName;
    int* points;

    //array of Players
    Player *player;
    int teamScore;


public:

    Team();
    int getTeamSize(int size);
    DSString getTeamName(DSString *name);


};
#endif // TEAM_H
