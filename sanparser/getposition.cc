#include "sanparser.ih"

namespace Mule::Chess
{
    namespace
    {
        string u_rank = {"12345678"};
        string u_file = {"abcdefgh"};
    }

    bool SANParser::getPosition(string const &move, size_t &idx)
    {
        Position pos;
        d_move.from = Position{ Position::undefined, Position::undefined };

        if (u_file.find(move[idx]) != string::npos)
            pos.file = 7 - (move[idx++] - 'a');

        if (u_rank.find(move[idx]) != string::npos)
            pos.rank = move[idx++] - '1';
        
            // Another rank means another square specified
        if (move.find_first_of(u_rank, idx) != string::npos)
        {
            d_move.from = pos;
            return false;
        }

        d_move.to = pos;    // If there is no other move this is the
        return true;        // position the peace was moved to
    }

} // namespace Mule::Chess
