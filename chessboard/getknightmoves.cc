#include "chessboard.ih"


namespace Mule::Chess
{   
    /*
    * Params: src, the square where the knight is coming from
    *         constraint, rank or file to check, positive is rank, negative is file
    *
    * Return: Two positions on the contstrainted rank or file.
    */

    namespace
    {
        // Local helper function
        // TODO: clean up
        inline uint8_t independant(Position src, Orientation orient)
        {
            return (orient == Orientation::RANK) ? src.rank : src.file;
        }

        inline uint8_t dependant(Position src, Orientation orient)
        {
            return (orient == Orientation::RANK) ? src.file : src.rank;
        }
    }

    pair<uint8_t, uint8_t> ChessBoard::
        getKnightMoves(Position src, Orientation orient, uint8_t constraint)
    {
        int8_t dist = independant(src, orient) - constraint;

        dist = ((dist < 0) ? -3 : 3) - dist;

        return
            pair<uint8_t, uint8_t>
            { 
                dependant(src, orient) + dist, 
                dependant(src, orient) - dist
            };

    }


}   // namespace Mule::Chess
