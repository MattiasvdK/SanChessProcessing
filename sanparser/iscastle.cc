#include "sanparser.ih"

namespace Mule::Chess
{
    bool SANParser::isCastle(std::string const &move)
    {
        if (move[0] != 'O')
        {
            d_move.castle = NO_CASTLE;
            return false;
        }

            // Set the rank based on colour
        uint8_t rank = (d_move.colour == WHITE) ? 0 : 7;
        d_move.piece = KING;

            // The files are the same for both colours
        d_move.from = { .file = 4, .rank = rank };

            // Resulting file depends on long or short castling
            // NMN, short castling
        if (move.length() < 5)
            d_move.to = { .file = 6, .rank = rank };

            // Long castling
        else
            d_move.to = { .file = 1, .rank = rank };
        
            // Check if the castle results in a check or mate
        checkCheck(move, move.length() - 1);
        return true;
    }

} // namespace Mule::Chess