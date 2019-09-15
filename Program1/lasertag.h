#ifndef LASERTAG_H
#define LASERTAG_H
#include "team.h"

class laserTag
{
private:
    ifstream teamFileA;
    ifstream teamFileB;

public:

    laserTag();
    void readTeamFile();
    void readMatchFile();
    void createVLowFile();
    void createVMedFile();
    void createVHighFile();
    void tagScoring();

};

#endif // LASERTAG_H
