#include "sanparser.ih"

namespace Mule::Chess
{
    void SANParser::checkTake(std::string const &move, size_t &idx)
    {
        if (move[idx] == 'x')
        {
            d_move.take = true;
            ++idx;
        }
        else
            d_move.take = false;
    }

} // namespace Mule::Chess