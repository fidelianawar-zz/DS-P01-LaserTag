#include "main.h"
#include <iostream>
#include <fstream>
#include <team.cpp>
#include <lasertag.h>

int main()
{
       laserTag newGame;
       newGame.readTeamFile();

//    for(int i = 0; i < argc; i++){
//        if(atoi(argv[i]) == 1){
//            teamA->readTeamAFile();
//        }
//        else if(atoi(argv[i]) == 2){
//            teamB->readTeamBFile();
//        }
//        else if(atoi(argv[i]) == 3){
//            match->readMatchFile();
//        }
//        if((strncmp(argv[5], "vlow", 4) == 1)){
//            ofstream outFile("LowVerbosity.txt");
//        }
//        if((strncmp(argv[5], "vmed", 4) == 1)){
//            ofstream outFile("MediumVerbosity.txt");
//        }
//        if((strncmp(argv[5], "vhigh", 5) == 1)){
//            ofstream outFile("HighVerbosity.txt");
//        }
//    }

}
