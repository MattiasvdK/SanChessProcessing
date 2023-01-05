#include "writer.ih"

namespace Mule::Chess
{

    // --- Copied from 'boardtofile.cc' ---
    // TODO: reuse functions, probably make them static members
    namespace
    {
        // TODO: Clean this up and make it nice

        inline uint8_t transform(uint8_t pos)
        {
            return 7 - pos;
        }

        void whiteToString(string &str, int8_t const *board, Move move)
        {
            for (uint8_t idx = 0; idx < 64; ++idx)
                str += board[idx];

            str += move.from.rank;
            str += move.from.file;
            str += move.to.rank;
            str += move.to.file;
        }

        // The -1 is not actually correct
        // Also need to transform the positions of the move

        void blackToString(string &str, int8_t const *board, Move move)
        {
            for (uint8_t idx = 64; idx--; )
                str += static_cast<int8_t>(board[idx] * -1);

            str += transform(move.from.rank);
            str += transform(move.from.file);
            str += transform(move.to.rank);
            str += transform(move.to.file);
        }
    }

    string Writer::dataToString(Colour colour) const
    {
        string ret{ };

        if (colour == WHITE)
            whiteToString(ret, d_board.board(), d_parser.move());
        else
            blackToString(ret, d_board.board(), d_parser.move());
        
        return ret;
    }

}