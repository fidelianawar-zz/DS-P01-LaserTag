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
int incrementVal;

Team::Team(){
    teamScore = 0;
    teamName = "";
}

int Team::getTeamSize(){
    return size;
}

void Team::setTeamName(DSString name){
    teamName = name;
}

DSString Team::getTeamName(){
    return teamName;
}

void Team::setScore(int score){
    teamScore = score;
}

int Team::getScore(){
    return teamScore;
}
int Team::incrementScore(int position){
    if(position == 1){
        incrementVal = 5;
    }
    else if(position == 2){
        incrementVal = 8;
    }
    else if(position == 3){
        incrementVal = 7;
    }
   else if(position == 4){
        incrementVal = 4;
    }
    teamScore += incrementVal;
    return teamScore;
}

