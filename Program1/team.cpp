#include <iostream>
#include <fstream>
#include <string>
#include "team.h"
#include "dsstring.h"

ifstream inFile;
int numTags;
int * tagArea;
int backPoints = 5;
int chestPoints = 8;
int shoulderPoints = 7;
int laser = 4;
int milliseconds;
int personTagged;
int personTagging;
Team * teamA;
Team * teamB;

void readTeamFile(){
    inFile.open("TeamA.txt");
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    char teamName[256];
    char numMembers[3];
    char teamMemberInfo[256];
    while(inFile.eof()) // To get you until end of line
    {
        inFile.getline(teamName,256,'\n'); //store team name
        inFile.getline(numMembers, 3,'\n');
        //inFile.getline(teamMemberInfo, 2, " ");
    }
    inFile.close();
}


void readMatchFile(){
    inFile.open("MatchFile.txt");
    if (!inFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    char taggerID[4];
    char targetID[3];
    char milliseconds[256];
    char tagArea[1];
    while(inFile.eof()) // To get you until end of line
    {
        inFile.getline(taggerID,4,'\n'); //store team name
        inFile.getline(targetID, 3,'\n');
        inFile.getline(milliseconds, 2,'\n');
        inFile.getline(tagArea, 1,'\n');
    }
    inFile.close();
}

void tagScoring(){

}
Team::Team()
{

      DSString line;
      inFile.

//    inFile.open(argv[1]);
//    if(!inFile.is_open()){
//        cout << "Could not open file";
//        return -1;
//    }

//    getline(inFile, teamName, '\n');
//    getline(inFile, numMembers, '\n');

//    while(!inFile.eof()){
//        getline(inFile, idNum, ' ');
//        getline(inFile, memberName);
}

