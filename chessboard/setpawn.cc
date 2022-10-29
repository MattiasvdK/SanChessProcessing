#include "chessboard.ih"

namespace Mule::Chess
{
    /*
    * Note to self
    * This function has a lot of different checks...
    * Does not really look nice
    */
    void ChessBoard::setPawn(Move move)
    {
        // Pawn move direction is based on the colour
        // Pawn moves forward unless check

        int8_t const dir = move.colour;
        int8_t const piece = pieceToInt(move.piece, move.colour);

        uint8_t const rank = move.to.rank - dir;

        // cerr << "Pawn rank: " << static_cast<int>(rank) << '\n';
        // cerr << "Pawn rank: " << static_cast<int>(rank - 1) << '\n';

        if (!move.take)
        {   
                // Check if the pawn should be moved from one step back
            if (!checkAndMove(rank, move.to.file, piece))
                movePieceFrom(
                    Position{
                        static_cast<uint8_t>(rank - dir),
                        move.to.file
                    }
                );
                
            return;
        }

        // If the pawn took a piece it moved diagonally
        
            // In case of ambiguity 
        if (move.from.file != Position::undefined)
        {
            movePieceFrom(Position{rank, move.from.file});
            return;
        }

            // Ah yes.. clarity
            // We only need to check one file to find the piece
        movePieceFrom(
            Position{
                rank, 
                static_cast<uint8_t>(
                    move.to.file
                    + (checkPosition(rank, move.to.file + 1, piece) ? 1 : -1)
                )
            }
        );
        

    }

} // namespace Mule::Chess
