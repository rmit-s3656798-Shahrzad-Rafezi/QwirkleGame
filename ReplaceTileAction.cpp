#include "ReplaceTileAction.h"
#include "Action.h"

ReplaceTileAction::ReplaceTileAction(Tile* replacedTile):Action(){
        this->replacedTile = replacedTile;
        newTile = nullptr;
}

ReplaceTileAction::~ReplaceTileAction(){
    if( newTile != nullptr)
        delete newTile;
}

//***No validation*** expects a correct and legal move
void ReplaceTileAction::doAction(Bag* bag, Board* board,Player* player){
    //removing tile from players hand and returning it to bag
    player->removeTile(replacedTile);
    bag->replaceBack(replacedTile);

    //Getting new tile from bag and adding to players hand
    newTile = bag->getFront();
    player->addTile(new Tile(*newTile));
}

//***No validation*** excpects bag,player to be in the state left by doAction 
void ReplaceTileAction::undoAction(Bag* bag, Board* board,Player* player){
    //Remove new tile from players hand and replacing it in bag
    std::cout << newTile->getTileName() << std::endl;
    player->removeTile(newTile);
    bag->replaceFront(new Tile(*newTile));

    //Removing tile from back of bag and returning back to players hand
    player->addTile(new Tile(*bag->getBack()));
}