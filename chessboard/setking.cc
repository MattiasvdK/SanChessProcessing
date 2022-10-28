#include "chessboard.ih"

namespace Mule::Chess
{
    /*
    *
    */
    void ChessBoard::setKing(Move move)
    {
        // If castle
        if (move.castle != NO_CASTLE)
        {
            movePieceFrom(move.from);

            // Only the rank changes with the colour and since that is
            // stored we don't need to check for it
            Position rookTo{ 
                move.to.rank,
                static_cast<uint8_t>(
                    move.to.file + (move.castle == SHORT ? 1: - 1)
                )
            };

            Position rookFrom{
                move.to.rank,
                static_cast<uint8_t>(move.castle == SHORT ? 0 : 7)
            };

            movePieceFrom(rookFrom);
            movePieceTo(move.colour, move.piece, rookTo);

            return;
        }
        
        int8_t const piece = pieceToInt(move.piece, move.colour);

        for
        (
            uint8_t brank = move.to.rank - 1, erank = move.to.rank + 1;
            brank < erank; ++brank
        )
            for
            (
                uint8_t bfile = move.to.file - 1, efile = move.to.rank + 1;
                bfile < efile; ++bfile
            )
            {
                    // Since the piece is moved to the position already
                    // skip the moved to position
                if (brank == move.to.rank && bfile == move.to.file)
                    continue;
    
                if (checkPosition(brank, bfile, piece))
                {
                    movePieceFrom(Position{ brank, bfile });
                    return;
                }
            }

    }

} // namespace Mule::Chess
