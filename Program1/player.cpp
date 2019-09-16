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

//setting name of player
void Player::setPlayerName(DSString name){
    playerName = name;
}

DSString Player::getPlayerName(){
    return playerName;
}

//setting ID of player
void Player::setPlayerID(int id){
    playerID = id;
}

int Player::getPlayerID(){
    return playerID;
}

//setting # of tags player has
void Player::setPlayerTag(int playerTag){
    tags = playerTag;
}

int Player::getPlayerTag(){
    return tags;
}


