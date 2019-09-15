#include "lasertag.h"
#include <iostream>
#include <fstream>
#include "team.h"
#include "dsstring.h"

ifstream matchFile;
Player* teamA;
Player* teamB;

laserTag::laserTag(){
    teamA = nullptr;
    teamB = nullptr;
}

void laserTag::readTeamFile(){

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

    DSString nameA(teamNameA);

    teamFileA.close();

    teamA = new Player[numLinesA];
    for(int i = 0; i < numLinesA; i++){
        teamA[i].setPlayerName(playerName[i]);
        teamA->setPlayerID(playerID[i]);
    }

    //--------------------------------------------------------------------

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
    teamFileB >> numLinesB; //store # members

     int *playerIDB = new int[numLinesB];
     DSString *playerNameB = new DSString[numLinesB];

    for(int i =0; i < numLinesB; i++){
        teamFileB >> IDb;
        teamFileB >> playerNameBufferB;
        playerNameB[i] = playerNameBufferB;
        playerIDB[i] = IDb;
        //cout << playerIDB[i] << endl;
    }

    DSString nameB(teamNameB);

    teamFileB.close();

    teamB = new Player[numLinesB];
    for(int i = 0; i < numLinesB; i++){
        teamB[i].setPlayerName(playerNameB[i]);
        teamB->setPlayerID(playerIDB[i]);
        cout << teamB[i].getPlayerID() << endl;
    }
}

//get input from match file
//compare IDs from input in match file to team player ID - tagging system

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
