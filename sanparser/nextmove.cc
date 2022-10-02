#include "sanparser.ih"

namespace Mule::Chess
{
        // Should technically check if game is ready
    bool SANParser::nextMove()
    {
        if (!d_game)
            return false;

        if (d_colour *= BLACK; d_colour == WHITE)
        {
            ++d_nTurn;
            std::string tmp;    // Not a very clean solution but
            d_game >> tmp;      // Flush the turn counter
        }
        
        parse();
        return true;
    }

} // namespace Mule::Chess