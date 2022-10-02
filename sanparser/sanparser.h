#ifndef INCLUDED_SAN_PARSER_H_
#define INCLUDED_SAN_PARSER_H_

#include <string>
#include <sstream>
#include <iostream>

#include "../types/chesstypes.h"

namespace Mule::Chess
{
    class SANParser
    {
        // TODO: next function for getting next move
        // 
      private:
        std::istream &d_in;
        //std::string d_game;

        std::stringstream d_game;

        size_t d_nTurn;

        int8_t d_colour;

        //bool d_ready = false;

        Move d_move;        // Holds the current move

      public:
        SANParser(std::istream &in = std::cin);

        bool nextMove();    // Prepares the next move made
        bool nextGame();    // Prepares the next game

        Move const &move() const;

      private:
        // bool findMove(std::string &move) const;
        void parse();

            // parse helper functions
        bool isCastle(std::string const &move);
        bool getPosition(std::string const &move, size_t &idx);

        void getPiece(std::string const &move, size_t &idx);
        void checkTake(std::string const &move, size_t &idx);
        void checkCheck(std::string const &move, size_t idx); // No ref
                                                              // is last char

    };

    inline SANParser::SANParser(std::istream &in)
    :
        d_in(in)
    {}

/*
    inline bool SANParser::nextGame()
    {
        d_move = 0;
        d_ready = getline(d_in, d_game);

        if ()
    }
*/

    inline Move const &SANParser::move() const
    {
        return d_move;
    }

}   // Mule::Chess


#endif
