#include "chessboard.ih"

namespace Mule::Chess
{
    void ChessBoard::setQueen(Move move)
    {
        // The Queen Moves either as bishop or as rook
        // Therefore we can reuse those functions

        if (!setRook(move))
            setBishop(move);
    }

} // namespace Mule::Chess
