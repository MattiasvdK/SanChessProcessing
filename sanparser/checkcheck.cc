#include "sanparser.ih"

namespace Mule::Chess
{
    void SANParser::checkCheck(std::string const &move, size_t idx)
    {
        if (move[idx] == '+')
            d_move.check = CHECK;
        else if (move[idx] == '#')
            d_move.check = CHECK_MATE;
        else
            d_move.check = NO_CHECK;

        // Last character so no increment needed
    }

} // namespace Mule::Chess