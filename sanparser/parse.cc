#include "sanparser.ih"

namespace Mule::Chess
{
    void SANParser::parse()
    {

        std::string move;
        d_game >> move;     // Note: this might go wrong

        d_move.colour = d_colour;
        d_move.nTurn = d_nTurn;

        if (isCastle(move))
            return;
        
        size_t idx = 0;

        getPiece(move, idx);

            // This happens if there is no ambiguity and a take
            // or when there is ambiguity
        if (!getPosition(move, idx))
        {
            checkTake(move, idx);
            getPosition(move, idx);
        }
        checkCheck(move, idx);
    }


} // namespace Mule::Chess