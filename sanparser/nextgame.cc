#include "sanparser.ih"

namespace Mule::Chess
{
    bool SANParser::nextGame()
    {
        d_nTurn = 0;
        d_colour = NO_COLOUR;
        
        string line;
        if (!getline(d_in, line))
            return false;

        d_game.clear();
        d_game << line;

        ++d_count;

        return true;
    }

} // namespace Mule::Chess

