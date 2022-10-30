#include "chessboard.ih"

namespace Mule::Chess
{
    void ChessBoard::movePieceFrom(Position position)
    {
        if (d_board[position.rank][position.file] == 0)
        {
            cerr << "Moved from: "
                 << static_cast<int>(position.rank) << ' '
                 << static_cast<int>(position.file) << '\n';

            throw std::string{"Piece removed illegally"};
        }
        d_board[position.rank][position.file] = 0;
        d_from = position;
    }

} // namespace Mule::Chess
