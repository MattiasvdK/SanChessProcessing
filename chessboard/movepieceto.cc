#include "chessboard.ih"

namespace Mule::Chess
{

        // Parameter order ignores standard order used in rest of class
    void ChessBoard::
        movePieceTo(Colour colour, Pieces piece, Position position)
    {
        d_board[position.rank][position.file] = pieceToInt(piece, colour);
    }

} // namespace Mule::Chess
