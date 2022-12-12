#include "chessreader.ih"

void ChessReader::readAllLines()
{
    while (true)
    {
        string line;

        if (!getline(d_input, line) || line.empty())
            break;

        processGame(line);
        ++d_count;
    }
}


