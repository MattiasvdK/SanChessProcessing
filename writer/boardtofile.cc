#include "writer.ih"

namespace Mule::Chess
{
    namespace
    {
        // TODO: Clean this up and make it nice

        void writeWhite(ostream &file, int8_t const *board)
        {
            for (uint8_t idx = 0; idx < 64; ++idx)
                file << board[idx];
        }   

        // The -1 is not actually correct
        // Also need to transform the positions of the move

        void writeBlack(ostream &file, int8_t const *board)
        {
            for (uint8_t idx = 64; idx--; )
                file << static_cast<int8_t>(board[idx] * -1);
        }

    }

    void Writer::boardToFile(ostream &file, Colour colour) const
    {   
        // MN: 64 amount of squares on chessboard.
        // is it nice? no. does it get the job done? yes

        int8_t const *board = d_board.board();

        if (colour == WHITE)
            writeWhite(file, board);
        else
            writeBlack(file, board);
        
    }
}
