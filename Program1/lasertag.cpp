#include <iostream>
#include <fstream>
#include "team.h"
#include "dsstring.h"
#include "lasertag.h"

ifstream teamAFile;
ifstream teamBFile;
ifstream matchFile;
ofstream outputFile;

Player* teamA;
Player* teamB;

int teamAscore;
int teamBscore;

//main method to run program execution
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
           //trying to see if fifth argument is vlow, creating output file
           else if(i == 5){
               if(argv[5][1], 'l'){
                   newGame.createVLowFile(argv[4]);
               }
               else if(argv[5][1], 'm'){
                   newGame.createVMedFile(argv[4]);
               }
               else if(argv[5][1], 'h'){
                   newGame.createVHighFile(argv[4]);
               }
           }
       }
}

//initializing variables to null
laserTag::laserTag(){
    teamA = nullptr;
    teamB = nullptr;
    teamAscore = 0;
    teamBscore = 0;
}

//this method reads in the teamA file and stores player information
//into a Player object called teamA
void laserTag::readTeamAFile(){
    if (!teamAFile.is_open()) {
        cerr << "Unable to open TeamA file" << endl;
        exit(1);   // call system to stop
    }

    //creating character buffer arrays to be able to read in from file w/o cin
    char teamNameA[256];
    int numLinesA;

    char playerNameBuffer[256];
    int ID;

    //store team name (up to 256 characters)
    teamAFile.getline(teamNameA,256);

    //store # lines which represents # members
    teamAFile >> numLinesA;

    int *playerIDA = new int[numLinesA];
    DSString *playerNameA = new DSString[numLinesA];

    //grabbing and storing elements of each line
    for(int i =0; i < numLinesA; i++){
        teamAFile >> ID;
        teamAFile >> playerNameBuffer;
        playerNameA[i] = playerNameBuffer;
        playerIDA[i] = ID;
    }

    //assigning value to DSString nameA
    nameA = teamNameA;

    teamAFile.close();

    //populating players of team with personal info
    teamA = new Player[numLinesA];
    for(int i = 0; i < numLinesA; i++){
        teamA[i].setPlayerName(playerNameA[i]);
        teamA[i].setPlayerID(playerIDA[i]);
    }
}

//same as for readTeamAFile, but with TeamB information now
void laserTag::readTeamBFile(){
    if (!teamBFile) {
        cerr << "Unable to open TeamB file" << endl;
        exit(1);   //call system to stop
    }

    //buffer to read in line
    char teamNameB[256];
    int numLinesB;

    char playerNameBufferB[256];
    int IDb;

    teamBFile.getline(teamNameB,256); //stores team name
    teamBFile >> numLinesB; //store # members

    //creating int array with size of num players
     int *playerIDB = new int[numLinesB];
     DSString *playerNameB = new DSString[numLinesB];

    for(int i =0; i < numLinesB; i++){
        teamBFile >> IDb;
        teamBFile >> playerNameBufferB;
        playerNameB[i] = playerNameBufferB;
        playerIDB[i] = IDb;
    }

    //assigning team name to global DSString variable
    nameB = teamNameB;
    teamBFile.close();

    //populating player object with personal info
    teamB = new Player[numLinesB];
    for(int i = 0; i < numLinesB; i++){
        teamB[i].setPlayerName(playerNameB[i]);
        teamB[i].setPlayerID(playerIDB[i]);
    }
}

//reading and storing elements of match file
void laserTag::readMatchFile(){
    if (!matchFile.is_open()) {
        cerr << "Unable to open MatchFile" << endl;
        exit(1);   // call system to stop
    }

    //store # lines which represents num of tags within match
    int numTags;
    matchFile >> numTags;

    //new integer arrays for various elements
    int *taggerID = new int[numTags];
    int *targetID = new int[numTags];
    int *milliseconds = new int[numTags];
    int *tagLocations = new int[numTags];

    //storing each element of line into separate int[]
    for(int i = 0; i < numTags; i++){
        matchFile >> taggerID[i];
        matchFile >> targetID[i];
        matchFile >> milliseconds[i];
        matchFile >> tagLocations[i];
    }

    matchFile.close();

    //calling method to compare tagger vs player ID
    compareIDs(numTags, taggerID, tagLocations);
}

//checks the matchFile tagger ID against teamA/teamB playerID to see if they're the same
int laserTag::compareIDs(int numTags, int *taggerID, int *tagLocations){

    int tagLocation1 = 5;
    int tagLocation2 = 8;
    int tagLocation3 = 7;
    int tagLocation4 = 4;

    //if they are the same, add value to their team score
    for(int i = 0; i < numTags; i++){
        if(taggerID[i] == teamA[i].getPlayerID()){
            if(tagLocations[i] == 1){
                teamAscore += tagLocation1;
            }
            else if(tagLocations[i] == 2){
                teamAscore += tagLocation2;
            }
            else if(tagLocations[i] == 3){
                teamAscore += tagLocation3;
            }
            else if(tagLocations[i] == 4){
                teamAscore += tagLocation4;
            }
        }

        //checking to see if TeamB player ID matches tagger ID
        else if(taggerID[i] ==  teamB[i].getPlayerID()){
            if(tagLocations[i] == 1){
                teamBscore += tagLocation1;
            }
            else if(tagLocations[i] == 2){
                teamBscore += tagLocation2;
            }
            else if(tagLocations[i] == 3){
                teamBscore += tagLocation3;
            }
            else if(tagLocations[i] == 4){
                teamBscore += tagLocation4;
            }
        }
    }

    //assigning end score to the team
    ATeam.setScore(teamAscore);
    BTeam.setScore(teamBscore);
}

//creation of low verbosity file
void laserTag::createVLowFile(char* input){
    ofstream outputFileVLow;
    outputFileVLow.open(input);

    //alphabetizing team name display info
    if(nameA < nameB){
        outputFileVLow << nameB << ": " << BTeam.getScore() << " points" << endl;
        outputFileVLow << nameA << ": " << ATeam.getScore() << " points" << endl;
    }
    else{
        outputFileVLow << nameA << ": " << ATeam.getScore() << " points" << endl;
        outputFileVLow << nameB << ": " << BTeam.getScore() << " points" << endl;
    }
    if(BTeam.getScore() > ATeam.getScore()){
        outputFileVLow << "Overall Winners: " << BTeam.getTeamName() << endl;
    }
    else if(ATeam.getScore() > BTeam.getScore()){
        outputFileVLow << "Overall Winners: " << ATeam.getTeamName() << endl;
    }
    else{
        outputFileVLow << "Overall Winners: There was a tie." << endl;
    }
    outputFileVLow.close();
}

void laserTag::createVMedFile(char* input){
    ofstream outputFileVMed;
    outputFileVMed.open(input);
    outputFileVMed << nameA << endl;

    int teamASize = ATeam.getTeamSize();
    for(int i = 0; i < teamASize-1; i++){
        for(int j = 0; j < teamASize-1; j++){
            Player playerAtemp = teamA[j];
            if(teamA[j].getPlayerTag() > teamA[j+1].getPlayerTag()){
                //did not have enough time to implement :(
            }
        }
    }

}
void laserTag::createVHighFile(char* input){

}
