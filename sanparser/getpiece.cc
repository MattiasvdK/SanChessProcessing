#include "sanparser.ih"

namespace Mule::Chess
{

    void SANParser::getPiece(std::string const &move, size_t &idx)
    {
        switch (move[idx++])
        {
            case 'K':
                d_move.piece = KING;
            break;

            case 'Q':
                d_move.piece = QUEEN;
            break;

            case 'R':
                d_move.piece = ROOK;
            break;

            case 'N':
                d_move.piece = KNIGHT;
            break;

            case 'B':
                d_move.piece = BISHOP;
            break;

            default:
                d_move.piece = PAWN;
                --idx;                  // There was no character read
            break;
        }
    }


} // namespace Mule::Chess
