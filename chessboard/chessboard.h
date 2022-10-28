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

        /*
        * The iterator to loop over the chess board
        * from the top left to the bottom right.
        * Implements the bare necessities for an iterator to work
        */
        /*
        class const_iterator
        {
            friend ChessBoard;

            int8_t const *d_iter;
            const_iterator(int8_t const *iter);
          public:            
            const_iterator &operator++();
            bool operator!=(const_iterator const &other) const;
            int8_t operator*() const;
        };
        */

        /*
        * The iterator to loop over the chess board
        * from the bottom right to the top left.
        * Implements the bare necessities for an iterator to work
        */
        /*
        class const_reverse_iterator
        {
            friend ChessBoard;

            int8_t const *d_iter;
            const_reverse_iterator(int8_t const *iter);
          public:            
            const_reverse_iterator &operator++();
            bool operator!=(const_reverse_iterator const &other) const;
            int8_t operator*() const;
        };
        */

      private:
        int8_t d_board[BOARD_DIM][BOARD_DIM];    // The chess board representation

      public:
        ChessBoard();
        void processMove(Move move);
        int8_t const *board() const;
        
        /*
        const_iterator cbegin() const;
        const_iterator cend() const;

        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;
        */

      
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
        static int8_t pieceToInt(Pieces piece, Colour colour);
    };

    // Create insertion operator for ChessBoard class

    inline bool ChessBoard::checkPosition(uint8_t rank, uint8_t file, int8_t piece)
    {
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

    /*

    inline ChessBoard::const_iterator ChessBoard::cbegin() const
    {
        int8_t const *iter = &(d_board[0][0]);
        return const_iterator{ iter };
    }

    inline ChessBoard::const_iterator ChessBoard::cend() const
    {
        int8_t const *iter = &(d_board[0][0]);
        return const_iterator{ iter + BOARD_DIM * BOARD_DIM };
    }

    inline ChessBoard::const_reverse_iterator
        ChessBoard::crbegin() const
    {
        int8_t const *iter = &(d_board[0][0]);
        return const_reverse_iterator{ iter + BOARD_DIM * BOARD_DIM };
    }

    inline ChessBoard::const_reverse_iterator
        ChessBoard::crend() const
    {
        int8_t const *iter = &(d_board[0][0]);
        return const_reverse_iterator{ iter };
    }
    
    // ----- ITERATOR MEMBERS -----

    ChessBoard::const_iterator::const_iterator(int8_t const *iter)
    :
        d_iter(iter)
    {}


        // Loop over the chess board
    inline ChessBoard::const_iterator &
        ChessBoard::const_iterator::operator++()
    {
        ++d_iter;                     // Very complex function
        return *this;
    }

        // Compare the iterators for checking if we are there
    inline bool ChessBoard::const_iterator::
        operator!=(ChessBoard::const_iterator const &other) const
    {
        return d_iter != other.d_iter;
    }

    inline int8_t ChessBoard::const_iterator::operator*() const
    {
        return *d_iter;
    }

    // ----- REVERSE ITERATOR -----

    ChessBoard::const_reverse_iterator::
        const_reverse_iterator(int8_t const *iter)
    :
        d_iter(iter)
    {}


    inline ChessBoard::const_reverse_iterator &
        ChessBoard::const_reverse_iterator::operator++()
    {
        --d_iter;                     // Go the other way
        return *this;
    }

    inline bool ChessBoard::const_reverse_iterator::
        operator!=(ChessBoard::const_reverse_iterator const &other) const
    {
        return d_iter != other.d_iter;
    }

    inline int8_t ChessBoard::const_reverse_iterator::operator*() const
    {
        return *d_iter;
    }

    */

} // namespace Mule::Chess


#endif
