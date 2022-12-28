#include "writer.ih"

namespace Mule::Chess
{
    
    namespace 
    {
        inline int8_t transform(int8_t pos)
        {
            return 7 - pos;
        }
    }
    
    void Writer::moveToFile(ostream &file, Colour colour)
    {
        if (colour == WHITE)
            file << d_board.from().rank << d_board.from().file
                 << d_parser.move().to.rank << d_parser.move().to.file;
        else
            file << transform(d_board.from().rank)
                 << transform(d_board.from().file)
                 << transform(d_parser.move().to.rank)
                 << transform(d_parser.move().to.file);
    }
}
