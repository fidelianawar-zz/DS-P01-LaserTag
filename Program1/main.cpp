#include "main.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    ifstream inFile;
    string line;
    string teamName;
    string numMembers;
    string idNum;
    string memberName;

    inFile.open(argv[1]);
    if(!inFile.is_open()){
        cout << "Could not open file";
        return -1;
    }

    getline(inFile, teamName, '\n');
    getline(inFile, numMembers, '\n');

    while(!inFile.eof()){
        getline(inFile, idNum, '\n');
        getline(inFile, memberName, '\n');
    }
    return 0;
}
