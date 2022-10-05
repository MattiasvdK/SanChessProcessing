#include "chessboard.ih"


namespace Mule::Chess
{

    void ChessBoard::processMove(Move move)
    {
        switch (move.piece)
        {
            case PAWN:
                setPawn(move);
            break;

            case BISHOP:
                setBishop(move);
            break;

            case KNIGHT:
                setKnight(move);
            break;

            case ROOK:
                setRook(move);
            break;

            case QUEEN:
                setQueen(move);
            break;

            case KING:
                setKing(move);
            break;
        }
    }

} // namespace Mule::Chess
