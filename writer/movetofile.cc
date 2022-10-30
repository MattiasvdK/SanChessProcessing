#include "writer.ih"

namespace Mule::Chess
{
    void Writer::moveToFile(ostream &file)
    {
        file << d_board.from().rank << d_board.from().file
             << d_parser.move().to.rank << d_parser.move().to.file;
    }
}
