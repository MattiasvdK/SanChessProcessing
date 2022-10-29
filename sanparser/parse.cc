#include "sanparser.ih"

namespace Mule::Chess
{
    bool SANParser::parse()
    {
        
        std::string move;
        if (!(d_game >> move))     // Note: this might go wrong
            return false;

        d_move.colour = d_colour;
        d_move.nTurn = d_nTurn;
        d_move.take = false;
        d_move.from = Position{ Position::undefined, Position::undefined };

        if (isCastle(move))
            return true;
        
        size_t idx = 0;

        getPiece(move, idx);

            // This happens if there is no ambiguity and a take
            // or when there is ambiguity
        if (!getPosition(move, idx))
        {
            cerr << "Source position found\n";

            checkTake(move, idx);
            getPosition(move, idx);
        }
        checkCheck(move, idx);

        return true;
    }


} // namespace Mule::Chess