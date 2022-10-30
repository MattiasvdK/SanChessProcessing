#include "writer.ih"

namespace Mule::Chess
{
    void Writer::boardToFile(ostream &file)
    {   
        // MN: 64 amount of squares on chessboard.
        // is it nice? no. does it get the job done? yes

        int8_t const *board = d_board.board();

        for (uint8_t idx = 0; idx < 64; ++idx)
            file << board[idx];
    }
}
