#include "chessboard.ih"

namespace Mule::Chess
{
        // bool so that it is usable by the Queen function
    bool ChessBoard::setRook(Move move)
    {
        // Refactorization comes later
        // First it needs to work

        int8_t const piece = pieceToInt(move.piece, move.colour);


        if (move.from.rank != Position::undefined)
        {
                // This check is needed to work with the Queen
            if (checkPosition(move.from.rank, move.to.file, piece))
            {
                movePieceFrom(Position{ move.from.rank, move.to.file });
                return true;
            }
            return false;
        }

        if (move.from.file != Position::undefined)
        {
            if (checkPosition(move.to.rank, move.from.file, piece))
            {
                movePieceFrom(Position{ move.to.rank, move.from.file });
                return true;
            }
            return false;
        }
            
        
            // Check if moved along file
        for (uint8_t file = 0; file < 8; ++file)
        {
            if (file == move.to.file)
                continue;

            if
            (
                checkPosition(move.to.rank, file, piece)
              && 
                checkRookPath(move.to, FILE, file)
            )
            {
                movePieceFrom(Position{ move.to.rank, file });
                return true;
            }
        }

            // Check if moved along rank
        for (uint8_t rank = 0; rank < 8; ++rank)
        {
            if (rank == move.to.rank)
                continue;

            if
            (
                checkPosition(rank, move.to.file, piece)
              &&
                checkRookPath(move.to, RANK, rank)
            )
            {
                movePieceFrom(Position{ rank, move.to.file });
                return true;
            }
        }

        return false;
    }

} // namespace Mule::Chess
