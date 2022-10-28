#include "chessboard.ih"

namespace Mule::Chess
{
    void ChessBoard::setKnight(Move move)
    {


        int8_t const piece = pieceToInt(move.piece, move.colour);

            // Locate knight based on given rank
        if (move.from.rank != Position::undefined)
        {
                // Could be localized but redundant
            auto [west, east] = getKnightMoves(move.to, RANK, move.from.rank);
            if (!checkAndMove(move.from.rank, west, piece))
                if (!checkAndMove(move.from.rank, east, piece))
                    throw string{"Piece not found in move of KNIGHT"};

            return;
        }

            // Locate knight based on given 
        if (move.from.file != Position::undefined)
        {
            auto [west, east] = getKnightMoves(move.to, Orientation::FILE, move.from.file);
            if (!checkAndMove(west, move.from.file, piece))
                if (!checkAndMove(east, move.from.file, piece))
                    throw string{"Piece not found in move of KNIGHT"};

            return;
        }

            // Consistent layout is overrated
            // Get possible positions within bounds
        for (uint8_t rank = max(move.to.rank - 2, 0), end = min(move.to.rank + 3, 8);
             rank < end; ++rank)
        {
            if (rank == move.to.rank)
                continue;

            auto [west, east] = getKnightMoves(move.to, Orientation::RANK, rank);
            if
            (
                checkAndMove(move.from.rank, west, piece) 
              || 
                checkAndMove(move.from.rank, east, piece)
            )
                return;

        }

    }

} // namespace Mule::Chess
