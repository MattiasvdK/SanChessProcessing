#ifndef CHESS_BOARD_H_
#define CHESS_BOARD_H_

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

        /*
        * The iterator to loop over the chess board
        * from the bottom right to the top left.
        * Implements the bare necessities for an iterator to work
        */
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

      private:
        int8_t board[BOARD_DIM][BOARD_DIM];    // The chess board representation

      public:
        void processMove(Move move);
        
        const_iterator cbegin() const;
        const_iterator cend() const;

        const_reverse_iterator crbegin() const;
        const_reverse_iterator crend() const;

      
      private:
        /*
        * Helper functions to set the pieces
        */
        void setPawn(int8_t colour, Position movedTo, Position movedFrom);
        void setBishop(int8_t colour, Position movedTo, Position movedFrom);
        void setKnight(int8_t colour, Position movedTo, Position movedFrom);
        void setRook(int8_t colour, Position movedTo, Position movedFrom);
        void setQueen(int8_t colour, Position movedTo, Position movedFrom);
        void setKing(int8_t colour, Position movedTo, Position movedFrom);
    };

    // Create insertion operator for ChessBoard class


    inline ChessBoard::const_iterator ChessBoard::cbegin() const
    {
        int8_t const *iter = &(board[0][0]);
        return const_iterator{ iter };
    }

    inline ChessBoard::const_iterator ChessBoard::cend() const
    {
        int8_t const *iter = &(board[0][0]);
        return const_iterator{ iter + BOARD_DIM * BOARD_DIM };
    }

    inline ChessBoard::const_reverse_iterator
        ChessBoard::crbegin() const
    {
        int8_t const *iter = &(board[0][0]);
        return const_reverse_iterator{ iter + BOARD_DIM * BOARD_DIM };
    }

    inline ChessBoard::const_reverse_iterator
        ChessBoard::crend() const
    {
        int8_t const *iter = &(board[0][0]);
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


} // namespace Mule::Chess


#endif
