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

int Team::getTeamSize(int size){
    return size;
}

void Team::setTeamName(DSString name){
    teamName = name;
}

DSString Team::getTeamName(DSString name){
    return name;
}

void Team::setScore(int score){
    teamScore = score;
}

int Team::getScore(int score){
    return score;
}
int Team::incrementScore(int incrementSize){
    return teamScore += incrementSize;
}

