#include <iostream>
#include <fstream>
#include "team.h"
#include "dsstring.h"
#include "player.cpp"
#include "player.h"

//array of Players
Player *team1;
Player *team2;
DSString teamName;

//how many players on team
int count;
int teamScore;

Team::Team(){
    teamScore = 0;
    teamName = "";
}

int getTeamSize(int size){
    return size;
}

void setTeamName(DSString name){
    teamName = name;
}

DSString getTeamName(DSString name){
    return name;
}

void setScore(int score){
    teamScore = score;
}

int getScore(int score){
    return score;
}
int incrementScore(int incrementSize){
    return teamScore += incrementSize;
}

