#include "writer.ih"

namespace Mule::Chess
{
    void Writer::write()
    {

        string const gameDir{
            d_target //+ "/game" + to_string(d_parser.count())
        };
        filesystem::create_directory(gameDir);

        while (d_parser.nextGame())
        try
        {
            if (d_parser.count() % 1000 == 0)
                cout << d_parser.count() << '\n';

            d_board = ChessBoard{};

            while (d_parser.nextMove())
            try
            {
                if (d_written.contains(dataToString(d_parser.move().colour)))
                {
                    d_board.processMove(d_parser.move());
                    continue;
                }

                d_written[dataToString(d_parser.move().colour)] = true;

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
                cerr << "Move " << d_nMove << ": " << error << '\n';
                break;
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

        cout << "Written " << d_nMove << " total moves\n";
    }
}
