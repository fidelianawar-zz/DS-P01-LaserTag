#include <iostream>
#include <fstream>
#include <string>
#include "team.h"
#include "dsstring.h"

Team::Team()
{
    ifstream inFile;
    DSString line;
    DSString teamName;
    DSString numMembers;
    DSString idNum;
    DSString memberName;

    inFile.open(argv[1]);
    if(!inFile.is_open()){
        cout << "Could not open file";
        return -1;
    }

    getline(inFile, teamName, '\n');
    getline(inFile, numMembers, '\n');

    while(!inFile.eof()){
        getline(inFile, idNum, ' ');
        getline(inFile, memberName);
    }
}
