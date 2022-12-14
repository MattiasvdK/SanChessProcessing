#ifndef INCLUDED_CHESS_TYPES_H_
#define INCLUDED_CHESS_TYPES_H_

#include <cstddef>
#include <cstdint>

namespace Mule::Chess
{
    enum Colour         // Colour classification
    {
        NO_COLOUR  =  0,// Colour of empty squares
        WHITE =  1,  
        BLACK = -1,
    };

    enum Pieces         // Piece classification
    {
        EMPTY,          // Represents empty squares
        PAWN,
        BISHOP,
        KNIGHT,
        ROOK,
        QUEEN,
        KING,
    };

    enum Orientation
    {
        RANK,
        FILE,
    };

    enum Check
    {
        NO_CHECK,
        CHECK,
        CHECK_MATE,
    };

    enum Castle
    {
        NO_CASTLE,
        SHORT,
        LONG,
    };

    struct Position       // Square coordinates
    {
        inline static uint8_t undefined = -1;

        uint8_t rank = undefined;   // The column of the square
        uint8_t file = undefined;   // The row of the square
    };

    struct Square
    {
        int8_t colour;    // The colour of the moved piece
        int8_t piece;     // The piece that was moved
    };

    struct Move           // Representation of Moves
    {
        size_t nTurn;     // Turn in which the move is made

        Position from;    // The square that the piece was moved from
                          // when specified in SAN notation
        Position to;      // The square that the piece was moved to
        
        Colour colour;    // The colour of the moved piece
        Pieces piece;     // The piece that was moved

        bool take;        // If an opponents piece was taken
        Check check;      // Holds check info
        Castle castle;    // Holds castle info
    };


} // namespace Mule::Chess

#endif
