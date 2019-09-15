#ifndef PLAYER_H
#define PLAYER_H
#include "dsstring.h"

using namespace std;

class Player
{
private:
    int playerID;
    DSString playerName;
    int tags;
    int playerScore;

public:

    Player();

    void setPlayerName(DSString name);
    void setPlayerID(int id);

    DSString getPlayerName();
    int getPlayerID();
};

#endif // PLAYER_H
