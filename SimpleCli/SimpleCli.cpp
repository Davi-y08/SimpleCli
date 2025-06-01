#include <iostream>
#include "search.hpp"
using namespace std;
int main(int argc, char* argv[])
{
    if (argc != 3) {
        cerr << "Uso: SimpleCli <palavra> <arquivo>\n";
        return 1;
    }

    string palavra = argv[1];
    string arquivo = argv[2];

    search_in_file(palavra, arquivo);
}

