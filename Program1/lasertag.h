#ifndef LASERTAG_H
#define LASERTAG_H
#include "team.h"

class laserTag
{
public:
    laserTag();

    Team * A;
    Team * B;

    void readTeamAFile();
    void readTeamBFile();
    void readMatchFile();
    void createVLowFile();
    void createVMedFile();
    void createVHighFile();
    void tagScoring();
};

#endif // LASERTAG_H
