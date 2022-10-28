#include "chessboard.ih"

namespace Mule::Chess
{
    void ChessBoard::setBishop(Move move)
    {
            // Bishop can come from the diagonals

            int8_t const piece = pieceToInt(move.piece, move.colour);

            if (move.from.rank != Position::undefined)
            {
                int8_t diff = move.to.rank - move.from.rank;
                uint8_t file = move.to.file + diff;

                if (file < 8 && checkAndMove(move.from.rank, file, piece))
                    return;

                return movePieceFrom(
                    Position{
                        move.from.rank,
                        static_cast<uint8_t>(move.to.file - diff)
                    }
                );
            }

            if (move.from.file != Position::undefined)
            {
                int8_t diff = move.to.file - move.from.file;
                uint8_t rank = move.to.rank + diff;

                if (rank < 8 && checkAndMove(rank, move.from.file, piece))
                    return;
                    
                return movePieceFrom(
                    Position{ 
                        static_cast<uint8_t>(move.to.rank - diff),
                        move.from.rank
                    }
                );
            }


                // Check to top right
            for
            (
                uint8_t rank = move.to.rank,
                        file = move.to.file;
                ++rank < 8 && ++file < 8;
            )
                if (checkAndMove(rank, file, piece))
                    return;


                // Check to top left
            for
            (
                uint8_t rank = move.to.rank,
                         file = move.to.file;
                ++rank < 8 && --file >= 0;
            )
                if (checkAndMove(rank, file, piece))
                    return;


                // Check to bottom right
            for
            (
                uint8_t rank = move.to.rank,
                         file = move.to.file;
                --rank >= 0 && ++file < 8;
            )
                if (checkAndMove(rank, file, piece))
                    return;


                // Check to bottom left
            for
            (
                uint8_t rank = move.to.rank,
                         file = move.to.file;
                --rank >= 0 && --file >= 0;
            )
                if (checkAndMove(rank, file, piece))
                    return;

    }

} // namespace Mule::Chess
