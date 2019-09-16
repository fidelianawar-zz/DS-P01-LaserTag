#ifndef LASERTAG_H
#define LASERTAG_H
#include "team.h"

class laserTag
{
private:
    ifstream teamFileA;
    ifstream teamFileB;

public:

    int *playerIDA;
    int *playerIDB;

    Team ATeam;
    Team BTeam;

    int teamScore;

    laserTag();
    void readTeamAFile();
    void readTeamBFile();
    void readMatchFile();
    int compareIDs(int tags, int *tagger, int *tagLocation);
    void createVLowFile(char *arg);
    void createVMedFile();
    void createVHighFile();
    void tagScoring();
    void incrementScore(int incrementSize);

};

#endif // LASERTAG_H
