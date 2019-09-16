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

    DSString nameA;
    DSString nameB;


    int teamScore;

    laserTag();
    void readTeamAFile();
    void readTeamBFile();
    void readMatchFile();
    int compareIDs(int tags, int *tagger, int *tagLocation);
    void createVLowFile(char *arg);
    void createVMedFile(char *arg);
    void createVHighFile(char *arg);
    void tagScoring();
    void incrementScore(int incrementSize);

};

#endif // LASERTAG_H
