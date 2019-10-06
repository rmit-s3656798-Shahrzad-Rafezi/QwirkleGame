#include "Board.h"
#include <iomanip>

#define EMPTY_TILE  ""

Board::Board(){
    for (row = 0; row < MAX_SIZE; row++) {
        for (column = 0; column < MAX_SIZE; column++) {
            board[row][column] = "  ";
        }
    }
}

Board::~Board() {
}

bool Board::canPieceBePlaced(Tile* piece, std::string pos){
    bool result = false;

    row = pos[0]-65; //shows 1,2,3,....

    //Converting Strings to Integers
    column = stoi(pos.substr(1)); // shows A,B,C,...

    if(row >= MAX_SIZE || column >= MAX_SIZE ){
      std::cout << "There are no more than 25 rows, therefore you cannot add the tile in this position" << std::endl;
    }

    else if(board[column][row].compare("") == 0){
      board[column][row] = piece->getTileName();
      result = true;
    }

    else{
      std::cout << "\n There is a tile already in that position" << std::endl;;
    }

    return result;
}

void Board::displayBoard(){
    std::cout << "\n ";

    //Sets the field width
    std::cout << std::setw(7);

    //Displays the top column numbers(0,2,4,...)
	  for(int col = 0; col < MAX_SIZE; col++) {
	    if(col % 2 == 0) {
	      std::cout << col << "      ";
	    }
	  }
	  std::cout << std::endl;


	  for(row = 0; row < MAX_SIZE; row++) {
          //Displays A, B, C, D, ... in each row
	      std::cout << (char) (65 + row) << "   ";

	      //Adjusts the "|" at
	      for (column = 0; column <= MAX_SIZE; column++) {
	        if(row % 2 == 0 && column % 2 == 0) {
	          std::cout << "|  ";
	        }
	        else if(row % 2 != 0 && column % 2 != 0){
	          std::cout << "  |";
	        }
	          std::cout << board[row][column];
	      }
	      std::cout << std::endl;
	  }

    //Sets the field width
	  std::cout << std::setw(6);

    //Displays the bottom column numbers(1,3,5,...)
	  for(int col = 0; col < MAX_SIZE; col++) {
	    if(col % 2 != 0) {
	      std::cout << col << "      ";
	    }

	  }
    std::cout << std::endl;
}

void Board::placeTile(Tile* piece, std::string pos){
  //Parsing pos to row and column
  row = pos[0]-65;
  column = stoi(pos.substr(1));

  if (canPieceBePlaced(piece, pos)){
    board[column][row] = piece->getTileName();
  }
}

void Board::removeTile(std::string pos){
  //Parsing pos to row and column
  row = pos[0]-65;
  column = stoi(pos.substr(1));

  board[column][row] = EMPTY_TILE;
}

// TODO: To be implemented
//std::string Board::toString(){
//
//}
