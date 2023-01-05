#ifndef INCLUDED_WRITER_H
#define INCLUDED_WRITER_H

#include "../sanparser/sanparser.h"
#include "../chessboard/chessboard.h"
#include <string>
#include <fstream>
#include <iostream>
#include <unordered_map>


// Error handling needs... improvement

namespace Mule::Chess
{

    class Writer
    {
        std::ifstream d_in;
        SANParser d_parser;
        ChessBoard d_board;
        std::string const d_target;

        // Stores whether a position + move combination is already written
        // to prevent duplicate data points.
        std::unordered_map<std::string, bool> d_written;

        size_t d_nMove;

      public:
        Writer(std::string const &in, std::string const &target);
        void write();

      private:
        void moveToFile(std::ostream &file, Colour colour) const;
        void boardToFile(std::ostream &file, Colour colour) const;

        std::string dataToString(Colour colour) const;

    };

    inline Writer::Writer(std::string const &in, std::string const &target)
    try
    : d_in(in), d_parser(d_in), d_target(target), d_nMove(0)
    {}
    catch(...)
    {
        std::cerr << "Kinda assuming the input file was wrong\n";
        throw;
    }

}



#endif
