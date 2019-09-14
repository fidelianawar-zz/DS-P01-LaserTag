#include <fstream>
#include <iostream>
#include "dsstring.h"
#include "player.h"

class Player;

Player::Player()
{
    playerID = 0;
    playerName = "";
    tags = 0;
    playerScore = 0;
}

