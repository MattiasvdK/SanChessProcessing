#include "chessboard.ih"

namespace Mule::Chess
{
        // This function can be refactored
        // but first I'd like it to work
        // There is a lot of redundancy but that makes it easier to refactor
        // later in the clean up phase
    bool ChessBoard::
        checkRookPath(Position src, Orientation orient, uint8_t dst)
    {
        if (orient == RANK)
        {   
            // Get the direction we want to go in from dst to src
            int8_t const dir = (dst < src.rank) ? 1 : -1;

                // Add dir to dst as we don't want to check the spot itself
            for (uint8_t rank = dst + dir; rank != src.rank; rank += dir)
                if (d_board[rank][src.file] != 0)
                    return false;
            
            return true;
        }

        if (orient == FILE) // Redundant
        {
            // Get the direction we want to go in from dst to src
            int8_t const dir = (dst < src.file) ? 1 : -1;

            for (uint8_t file = dst + dir; file != src.file; file += dir)
                if (d_board[src.rank][file] != 0)
                    return false;
            return true;
        }

        return true;        // Redundant
    }

}   // namespace Mule::Chess