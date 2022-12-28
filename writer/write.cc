#include "writer.ih"

namespace Mule::Chess
{
    void Writer::write()
    {
        while (d_parser.nextGame())
        try
        {
            //cont = false;

            if (d_parser.count() % 1000 == 0)
                cerr << d_parser.count() << '\n';

            string const gameDir{
                d_target //+ "/game" + to_string(d_parser.count())
            };
            filesystem::create_directory(gameDir);

            //d_nMove = 0;

            d_board = ChessBoard{};

            while (d_parser.nextMove())
            try
            {

                string const moveDir = gameDir + "/move" + to_string(d_nMove);
                filesystem::create_directory(moveDir);

                ofstream outBoard{ moveDir + "/board" };
                ofstream outMove{ moveDir + "/move"};

                // This needs to be processed before the move to have
                // the boardstate in which the move was made
                boardToFile(outBoard, d_parser.move().colour);

                d_board.processMove(d_parser.move());
                
                // This needs to be processed after the move to find the
                // source square
                moveToFile(outMove, d_parser.move().colour);


                ++d_nMove;
            }
            catch(string const &error)
            {
                cerr << error << '\n';
            }
            catch(...)
            {
                cerr << "Something with file writing\n";
            }
        }
        catch(...)
        {
            cerr << "Probably something in the output directory\n";
            return;
        }
    }
}
