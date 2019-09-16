#ifndef PLAYER_H
#define PLAYER_H
#include "dsstring.h"

using namespace std;

class Player
{
private:
    DSString playerName;
    int playerID;
    int tags;
    int playerScore;

public:

    Player();

    void setPlayerName(DSString name);
    void setPlayerID(int id);
    void setPlayerTag(int tag);

    DSString getPlayerName();
    int getPlayerID();
    int getPlayerTag();
};

#endif // PLAYER_H
