#include <iostream>
#include <fstream>
#include <string>
#include "team.h"
#include "dsstring.h"

ifstream teamFile;
ifstream matchFile;
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

void readTeamAFile(){
    teamFile.open("TeamA.txt");
    if (!teamFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    char nameA[256];
    char numberA[3];
    char memInfoA[256];

    while(teamFile.eof()) // To get you until end of fo;e
    {
        teamFile.getline(nameA,256); //store team name
        teamFile.getline(numberA, 3); //store # members
        for(int i =0; i < atoi(numberA); i++){
            if(i == ' '){

            }
        }
    }

    DSString teamNameA(nameA);
    DSString numMembersA(numberA);
    DSString teamMemberInfoA(memInfoA);

    teamFile.close();
}

void readTeamBFile(){
    teamFile.open("TeamA.txt");
    if (!teamFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    char nameB[256];
    char numberB[3];
    char memInfoB[256];

    while(teamFile.eof()) // To get you until end of fo;e
    {
        teamFile.getline(nameB,256); //store team name
        teamFile.getline(numberB, 3); //store # members
        for(int i =0; i < atoi(numberB); i++){
            if(i == ' '){

            }
        }
    }

    DSString teamNameB(nameB);
    DSString numMembersB(numberB);
    DSString teamMemberInfoB(memInfoB);

    teamFile.close();
}


void readMatchFile(){
    matchFile.open("MatchFile.txt");
    if (!matchFile) {
        cerr << "Unable to open file datafile.txt";
        exit(1);   // call system to stop
    }

    char tagger[4];
    char target[3];
    char time[256];
    char area[1]; //area of tagging
    char areaSum[5];
    char line[256];
    cout<<"delete this";
    DSString taggerID();

    while(matchFile.getline())
    while(matchFile.eof()) // To get you until end of file
    {

        matchFile.getline(tagger,4); //store tagger name
        matchFile.getline(target, 3);
        matchFile.getline(time, 2);
        matchFile.getline(area, 1);
    }

    //storing all the loaded values into DSString containers
    DSString taggerID(tagger);
    DSString targetID(target);
    DSString milliseconds(time);
    DSString tagArea(area);

    matchFile.close();
}

void tagScoring(){


}


