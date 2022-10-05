#include "sanparser.ih"

namespace Mule::Chess
{
        // Should technically check if game is ready
    bool SANParser::nextMove()
    {
        switch (d_colour)
        {
            case WHITE:
                d_colour = BLACK;
            break;
            
            case NO_COLOUR:
            case BLACK:
                ++d_nTurn;

                std::string tmp;    // Flush the turn counter
                d_game >> tmp;      // but not very clean

                d_colour = WHITE;
            break;

        }

        return parse();
    }

} // namespace Mule::Chess