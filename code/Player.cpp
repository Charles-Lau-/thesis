#include "Player.h"
#include "Board.h"
#include "piece.h"
#include "Constants.h"
#include <vector>
using namespace std;
Player::Player(char color){
	this->color =color;
}

bool Player::amICheckmated(Board &board){
	vector<Piece*> pieces = board.getPieces();
	vector<int*> opponentAttack;
	int * positionOfKing; 
	for(int i=0;i<pieces.size();i++){
		if((pieces.at(i)->getColor()==this->color) && (pieces.at(i)->getIdentifier() == KING)){
			positionOfKing = pieces.at(i)->getPosition();
			break;
			}
			
	}
	return board.isUnderAttack(positionOfKing,this->color);

}

char Player::getColor(){
	return color;
}
