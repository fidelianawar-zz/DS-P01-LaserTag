#include <fstream>
#include <iostream>
#include "dsstring.h"
#include "player.h"

using namespace std;

Player::Player()
{
    playerID = 0;
    playerName = "";
    tags = 0;
    playerScore = 0;
}

void Player::setPlayerName(DSString name){
    playerName = name;
}

DSString Player::getPlayerName(){
    return playerName;
}
void Player::setPlayerID(int id){
    playerID = id;
}

int Player::getPlayerID(){
    return playerID;
}


