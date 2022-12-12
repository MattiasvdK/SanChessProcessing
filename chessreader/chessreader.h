#ifndef INCLUDED_CHESS_READER_H_
#define INCLUDED_CHESS_READER_H_

#include <string>
#include <cstdint>

/*
* This class reads lines of chess games that are represented by their moves
* and turns them into picture representation.
*/
class ChessReader
{
  private:

    using Board = uint8_t[8][8];

    std::istream &d_input;          // The input stream to read from
    std::string const d_destDir;    // The directory to put the games in
    std::string d_currDir;          // Directory of the current game

    size_t d_count = 0;             // Count the games processed so far
    
  public:

    enum Dimension
    {   
        BOARD_DIM = 8,
    };

    enum Pieces
    {
        EMPTY,
        W_KING,
        W_QUEEN,
        W_BISHOP,
        W_KNIGHT,
        W_ROOK,
        W_PAWN,
        B_KING,
        B_QUEEN,
        B_BISHOP,
        B_KNIGHT,
        B_ROOK,
        B_PAWN,
    };

    ChessReader(std::istream &input, std::string const &destDir);
    void readAllLines();

  private:
    void processGame(std::string const &line);
    void initializeBoard(Board board);
    std::string initializeDirectory();

};

inline ChessReader::ChessReader(std::istream &input, std::string const &destDir)
:
    d_input(input), d_destDir(destDir)
{}


#endif

