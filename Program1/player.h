#ifndef PLAYER_H
#define PLAYER_H
#include "dsstring.h"

class Player
{
public:
    Player();
    int playerID;
    DSString playerName;
    int tags;
    int playerScore;
};

#endif // PLAYER_H
