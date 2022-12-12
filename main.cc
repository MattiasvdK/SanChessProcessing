#include "main.ih"


void printBoard(int8_t const *board)
{
    for (uint8_t rank = 8; rank--; )
    {
        for (uint8_t file = 0; file < 8; ++file)
        {
            cout << setw(3) << static_cast<int>(board[8 * rank + file]);
        }
        cout << '\n';
    }
}


int main(int argc, char **argv)
{
    Writer writer{ argv[1], argv[2] };
    writer.write();

}
