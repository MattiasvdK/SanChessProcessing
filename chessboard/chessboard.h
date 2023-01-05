#ifndef CHESS_BOARD_H_
#define CHESS_BOARD_H_

#include "../types/chesstypes.h"

#include <utility>
#include <cstdint>

namespace Mule::Chess
{
    class ChessBoard
    {
      public:
        enum Dimensions
        {
            BOARD_DIM = 8,
        };

      private:
        int8_t d_board[BOARD_DIM][BOARD_DIM];    // The chess board representation

        Position d_from;                         // Stores place the piece was moved from for logging

      public:
        ChessBoard();
        void processMove(Move move);
        int8_t const *board() const;
        Position from() const;
      
      private:
        /*
        * Helper functions to set the pieces
        */
        void setPawn(Move move);
        void setBishop(Move move);
        void setKnight(Move move);

        bool setRook(Move move);

        void setQueen(Move move);
        void setKing(Move move);

        void movePieceTo(Colour colour, Pieces piece, Position position);
        void movePieceFrom(Position position);

        bool checkPosition(uint8_t rank, uint8_t file, int8_t piece);

        bool checkAndMove(uint8_t rank, uint8_t file, int8_t piece);

        static std::pair<uint8_t, uint8_t> getKnightMoves(Position src, Orientation orient, uint8_t constr);
        
        bool checkRookPath(Position src, Orientation orient, uint8_t dst);
        
        static int8_t pieceToInt(Pieces piece, Colour colour);

    };

    // Create insertion operator for ChessBoard class

    inline bool ChessBoard::checkPosition(uint8_t rank, uint8_t file, int8_t piece)
    {
        if (rank < 0 || rank >= 8 || file < 0 || file >= 8)
            return false;
            
        return d_board[rank][file] == piece;
    }

    inline bool ChessBoard::checkAndMove(uint8_t rank, uint8_t file, int8_t piece)
    {
        if (checkPosition(rank, file, piece))
        {
            movePieceFrom(Position{ rank, file });
            return true;
        }
        return false;
    }

    inline int8_t ChessBoard::pieceToInt(Pieces piece, Colour colour)
    {
        return static_cast<int8_t>(piece) * static_cast<int8_t>(colour);
    }

    inline int8_t const *ChessBoard::board() const
    {
        return reinterpret_cast<int8_t const *>(d_board);
    }

    inline Position ChessBoard::from() const
    {
        return d_from;
    }

} // namespace Mule::Chess


#endif
