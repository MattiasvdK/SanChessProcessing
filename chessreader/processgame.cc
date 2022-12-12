#include "chessreader.ih"

/*
* Process line for both white and black or as one?
* Two extra files for which piece was selected and which square targeted.
* How to specify the piece?
* 
*/
void ChessReader::processGame(string const &line)
{
    string dir = initializeDirectory();

    //size_t movecount = 0;
    Board board;

    // Initialize the current board state
    initializeBoard(board);
    
    // Process move
    
    // How to process black moves / board state
}