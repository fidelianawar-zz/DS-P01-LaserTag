#include "lasertag.h"
#include <iostream>
#include <fstream>
#include "team.h"
#include "dsstring.h"

ifstream teamAFile;
ifstream teamBFile;
ifstream matchFile;
ofstream outputFile;

Player* teamA;
Player* teamB;

int teamAscore;
int teamBscore;

int main(int argc, char *argv[])
{
       argc = 6;
       laserTag newGame;

       for(int i = 0; i < argc; i++){
           if(i == 1){
                teamAFile.open(argv[i]);
                newGame.readTeamAFile();
           }
           else if(i == 2){
                teamBFile.open(argv[i]);
                newGame.readTeamBFile();
           }
           else if(i == 3){
                matchFile.open(argv[i]);
                newGame.readMatchFile();
           }
           else if(i == 5){
               if(argv[5][1] == 'l'){
                   newGame.createVLowFile(argv[4]);
               }
               else if(strcmp(argv[5],"vmed")){
                   newGame.createVMedFile();
               }
               else if(strcmp(argv[5],"vhigh")){
                   newGame.createVMedFile();
               }
           }
       }
}

laserTag::laserTag(){
    teamA = nullptr;
    teamB = nullptr;
}

void laserTag::readTeamAFile(){
    if (!teamAFile.is_open()) {
        cerr << "Unable to open TeamA file" << endl;
        exit(1);   // call system to stop
    }

    char teamNameA[256];
    int numLinesA;

    char playerNameBuffer[256];
    int ID;

    teamAFile.getline(teamNameA,256); //store team name
    teamAFile >> numLinesA;//store # members

    int *playerIDA = new int[numLinesA];
    DSString *playerNameA = new DSString[numLinesA];

    for(int i =0; i < numLinesA; i++){
        teamAFile >> ID;
        teamAFile >> playerNameBuffer;
        playerNameA[i] = playerNameBuffer;
        //cout << playerNameA[i] << endl;
        playerIDA[i] = ID;
        //cout << playerIDA[i] << endl;
    }

    DSString nameA(teamNameA);
    teamAFile.close();

    teamA = new Player[numLinesA];
    for(int i = 0; i < numLinesA; i++){
        teamA[i].setPlayerName(playerNameA[i]);
        teamA[i].setPlayerID(playerIDA[i]);
        //cout << teamA[i].getPlayerID() << endl;
    }
}

void laserTag::readTeamBFile(){
    if (!teamBFile) {
        cerr << "Unable to open TeamB file" << endl;
        exit(1);   // call system to stop
    }

    char teamNameB[256];
    int numLinesB;

    char playerNameBufferB[256];
    int IDb;

    teamBFile.getline(teamNameB,256); //store team name
    teamBFile >> numLinesB; //store # members

     int *playerIDB = new int[numLinesB];
     DSString *playerNameB = new DSString[numLinesB];

    for(int i =0; i < numLinesB; i++){
        teamBFile >> IDb;
        teamBFile >> playerNameBufferB;
        playerNameB[i] = playerNameBufferB;
        playerIDB[i] = IDb;
    }

    DSString nameB(teamNameB);

    teamBFile.close();

    teamB = new Player[numLinesB];
    for(int i = 0; i < numLinesB; i++){
        teamB[i].setPlayerName(playerNameB[i]);
        teamB[i].setPlayerID(playerIDB[i]);
        //cout << teamB[i].getPlayerID() << endl;
    }
}

void laserTag::incrementScore(int incrementSize){
    teamScore += incrementSize;
}

void laserTag::readMatchFile(){
    if (!matchFile.is_open()) {
        cerr << "Unable to open MatchFile" << endl;
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

    compareIDs(numTags, taggerID, tagLocations);
}

int laserTag::compareIDs(int numTags, int *taggerID, int *tagLocations){

    int tagLocation1 = 5;
    int tagLocation2 = 8;
    int tagLocation3 = 7;
    int tagLocation4 = 4;

    for(int i = 0; i < numTags; i++){
        if(taggerID[i] == teamA[i].getPlayerID()){
            cout << "playerA" << endl;
            if(tagLocations[i] == 1){
                teamAscore += tagLocation1;
            }
            else if(tagLocations[i] == 2){
                cout << "playerA" << endl;
                teamAscore += tagLocation2;
            }
            else if(tagLocations[i] == 3){
                cout << "playerA" << endl;
                teamAscore += tagLocation3;
            }
            else if(tagLocations[i] == 4){
                cout << "playerA" << endl;
                teamAscore += tagLocation4;
            }
        }

        else if(taggerID[i] ==  teamB[i].getPlayerID()){
            cout << "playerB" << endl;
            if(tagLocations[i] == 1){
                teamBscore += tagLocation1;
            }
            else if(tagLocations[i] == 2){
                cout << "playerB" << endl;
                teamBscore += tagLocation2;
            }
            else if(tagLocations[i] == 3){
                cout << "playerB" << endl;
                teamBscore += tagLocation3;
            }
            else if(tagLocations[i] == 4){
                cout << "playerB" << endl;
                teamBscore += tagLocation4;
            }
        }
    }

    cout << "Score of team A: " << teamAscore << endl;
        ATeam.setScore(teamAscore);
    cout << "Score of team B: " << teamBscore << endl;
        BTeam.setScore(teamBscore);
}

void laserTag::createVLowFile(char* input){
   ofstream outputFileVLow(input);
   outputFileVLow.open("OutputFile.txt");
   outputFileVLow << "hello";
   outputFileVLow << ATeam.getTeamName() << ": " << ATeam.getScore() << " points" << endl;
   outputFileVLow << BTeam.getTeamName() << ": " << BTeam.getScore() << " points" << endl;
   if(ATeam.getScore() > BTeam.getScore()){
        outputFileVLow << "Overall Winners: " << ATeam.getTeamName() << endl;
   }
   else if(BTeam.getScore() > ATeam.getScore()){
        outputFileVLow << "Overall Winners: " << BTeam.getTeamName() << endl;
   }
   else{
        outputFileVLow << "Overall Winners: There was a tie." << endl;
   }
}

void laserTag::createVMedFile(){

}
void laserTag::createVHighFile(){

}
