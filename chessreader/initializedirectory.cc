#include "chessreader.ih"

namespace fs = std::filesystem;

string ChessReader::initializeDirectory()
try
{
    string dir = d_destDir + "/game" + std::to_string(d_count);
    fs::create_directory(dir);
    fs::create_directory(dir + "/boards");
    fs::create_directory(dir + "/selected");
    fs::create_directory(dir + "/target");

    return dir;
}
catch(exception &error)
{
    cout << "Directory creation gone wrong " << error.what() << '\n';
    return string{}; // This needs to rethrow..
}

