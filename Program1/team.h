#ifndef TEAM_H
#define TEAM_H
#include <dsstring.h>
#include <fstream>

using namespace std;

class Team
{
private:

    ifstream inFile;

    Team* teamA;
    Team* teamB;
    DSString* teamName;
    int numPlayers;
    int idNum;
    DSString* memberName;
    int* points;


public:
    void readTeamAFile();
    void readTeamBFile();
    void readMatchFile();
    int getSize();
    Team();
    void tagScoring();

};
#endif // TEAM_H
