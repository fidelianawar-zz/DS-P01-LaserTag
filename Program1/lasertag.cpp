#include "lasertag.h"
#include <iostream>
#include <fstream>
#include "team.h"
#include "dsstring.h"


ifstream matchFile;

int numTags;
int tagArea;

//int backPoints = 5;
//int chestPoints = 8;
//int shoulderPoints = 7;
//int laser = 4;

int milliseconds;
int personTagged;
int personTagging;

Team * teamA;
Team * teamB;
Team * match;

laserTag::laserTag()
{
    numTags = 0;
    milliseconds = 0;
    personTagged = 0;
    personTagging = 0;
}

void readTeamFile(){

    ifstream teamFileA;

    teamFileA.open("TeamA.txt");
    if (!teamFileA) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    char teamNameA[256];
    int numLinesA;

    char playerNameBuffer[256];
    int ID;

    teamFileA.getline(teamNameA,256); //store team name
    teamFileA >> numLinesA;//store # members


     int *playerID = new int[numLinesA];
     DSString *playerName = new DSString[numLinesA];

    for(int i =0; i < numLinesA; i++){
        teamFileA >> ID;
        teamFileA >> playerNameBuffer;
        playerName[i] = playerNameBuffer;
        playerID[i] = ID;
    }

    DSString teamA(teamNameA);

    teamFileA.close();

    //--------------------------------------------------------------------

    ifstream teamFileB;

    teamFileB.open("TeamB.txt");
    if (!teamFileB) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    char teamNameB[256];
    int numLinesB;

    char playerNameBufferB[256];
    int IDb;

    teamFileB.getline(teamNameB,256); //store team name
    teamFileB >> numLinesB;//store # members

     int *playerIDB = new int[numLinesB];
     DSString *playerNameB = new DSString[numLinesB];

    for(int i =0; i < numLinesB; i++){
        teamFileB >> IDb;
        teamFileB >> playerNameBufferB;
        playerNameB[i] = playerNameBufferB;
        playerIDB[i] = IDb;
    }

    DSString teamB(teamNameB);

    teamFileB.close();
}


void readMatchFile(){
    matchFile.open("MatchFile.txt");
    if (!matchFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    int numTags;
    matchFile >> numTags;//store # members

    int *taggerID = new int[numTags];
    int *targetID = new int[numTags];
    int *milliseconds = new int[numTags];
    int *tagLocations = new int[numTags];

    for(int i = 0; i < numTags; i++){
        matchFile >> taggerID[i];
        matchFile >> targetID[i];
        matchFile >> milliseconds[i];
        matchFile >> tagLocations[i];
    }
    matchFile.close();
}

void populateTeam(){
    Team A = new Player[numLinesA]
}

void tagScoring(){


}
void createVLowFile(){
   //output team name A
   //team name B

}
void createVMedFile(){

}
void createVHighFile(){

}



