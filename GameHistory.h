
#ifndef ASSIGN2_GAMEHOSTORY_H
#define ASSIGN2_GAMEHISTORY_H
#include "ActionNode.h"

class GameHistory{
public:
    GameHistory(Bag* bag, Board* board, Player* p1, Player* p2);
    ~GameHistory();

    void addAction(Action* action, PlayerNum playerNum);

    void replay();
    void undo(Bag* bag, Board* board, Player* playerOne, Player* playerTwo);


private:
    ActionNode* head;
    ActionNode* tail;
    int size;

    Bag iBag;
    Board iBoard;
    Player iPlayerOne;
    Player iPlayerTwo;

    /*
    Player* iPlayerOne;
    Player* iPlayerTwo;
    Bag* iBag;
*/
};

#endif // ASSIGN2_GAMEHISTORY_H