#include "chessreader.ih"
#include <cstring>  // Kinda cheating but it works

namespace
{
    using cr = ChessReader;
    uint8_t const blackBase[cr::BOARD_DIM] = 
        { cr::B_ROOK, cr::B_KNIGHT, cr::B_BISHOP, cr::B_QUEEN, 
          cr::B_KING, cr::B_BISHOP, cr::B_KNIGHT, cr::B_ROOK };

    uint8_t const whiteBase[cr::BOARD_DIM] =
        { cr::W_ROOK, cr::W_KNIGHT, cr::W_BISHOP, cr::W_QUEEN, 
          cr::W_KING, cr::W_BISHOP, cr::W_KNIGHT, cr::W_ROOK };
}

void ChessReader::initializeBoard(ChessReader::Board board)
{
        // Set all squares to empty
    for (size_t row = 0; row != BOARD_DIM; ++row)
        for (size_t col = 0; col != BOARD_DIM; ++col)
            board[row][col] = EMPTY;

        // Copy the base lines (top and bottom row)
    memcpy(board[0], blackBase, BOARD_DIM * sizeof(uint8_t));
    memcpy(board[7], blackBase, BOARD_DIM * sizeof(uint8_t));

        // Set the pawns for black
    for (size_t idx = 0; idx != BOARD_DIM; ++idx)
        board[1][idx] = B_PAWN;
    
        // Set the pawns for white
    for (size_t idx = 0; idx != BOARD_DIM; ++idx)
        board[6][idx] = W_PAWN;
}
