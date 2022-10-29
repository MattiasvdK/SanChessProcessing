#include "chessboard.ih"

namespace Mule::Chess
{
    ChessBoard::ChessBoard()
    {
        d_board[0][0] = d_board[0][7] = pieceToInt(ROOK, WHITE);
        d_board[0][1] = d_board[0][6] = pieceToInt(KNIGHT, WHITE);
        d_board[0][2] = d_board[0][5] = pieceToInt(BISHOP, WHITE);
        d_board[0][4] = pieceToInt(KING, WHITE);
        d_board[0][3] = pieceToInt(QUEEN, WHITE);

        d_board[7][0] = d_board[7][7] = pieceToInt(ROOK, BLACK);
        d_board[7][1] = d_board[7][6] = pieceToInt(KNIGHT, BLACK);
        d_board[7][2] = d_board[7][5] = pieceToInt(BISHOP, BLACK);
        d_board[7][4] = pieceToInt(KING, BLACK);
        d_board[7][3] = pieceToInt(QUEEN, BLACK);

        for (uint8_t file = 0; file < 8; ++file)
        {
            d_board[1][file] = pieceToInt(PAWN, WHITE);
            d_board[6][file] = pieceToInt(PAWN, BLACK);

            d_board[2][file] = d_board[3][file] 
                             = d_board[4][file] 
                             = d_board[5][file] = 0;
        }

    }

};
