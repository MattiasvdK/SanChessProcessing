#include "chessboard.ih"


namespace Mule::Chess
{

    void ChessBoard::processMove(Move move)
    {
            // Piece can always be moved to the target square
        movePieceTo(move.colour, move.piece, move.to);

            // If there the full square was defined in SAN
            // the piece is not relevant unless we castle
        if
        (
            move.castle == NO_CASTLE
          &&
            move.from.rank != Position::undefined
          &&
            move.from.file != Position::undefined
        )
        {
            movePieceFrom(move.from);
            return;
        }

            // It depends on the piece where it can come from
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

            default:
                throw string{ "Incorrect Piece value" };
            break;
        }
    }

} // namespace Mule::Chess
