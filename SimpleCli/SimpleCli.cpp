#include <iostream>
#include "search.hpp"
#include "fileConfigs.hpp"
#include <sstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main()
{
    bool saida = false;
    string input = "";

    cout << "=----//----=";
    cout << "\n";
    cout << "SimpleCli";
    cout << "\n";
    cout << "=----//----=";  
    cout << "\n";

    while (!saida) {
        std::cout << fs::current_path() << "> ";
        getline(cin, input);

        if (input == "scape") {
            saida = true;
        }

        else if (input == "clean") {
            #if defined(__linux__) || defined(__APPLE__)
                system("clear");
            #elif defined(_WIN32)
                system("cls");
            #else
                std::cout << "Comando de limpeza não suportado neste sistema.\n";
            #endif
        }

        else if (input.rfind("ent ", 0) == 0) {
            string path = input.substr(4);
            error_code ec;
            fs::current_path(path, ec);
            bool saidaInterna = false;

            if (ec) {
                std::cerr << "Erro ao mudar de diretório: " << ec.message() << "\n";
            }

            else {
                while (!saidaInterna) {
                    string inputInterno = "";
                    cout << fs::current_path() << " (sub)> ";
                    getline(cin, inputInterno);
                    if (inputInterno == "back") {
                        fs::current_path("..");
                        saidaInterna = true;
                    }
                    else if (inputInterno == "where") {
                        cout << fs::current_path() << "\n";
                    }
                    else if ("veri") {
                        fs::path caminhoAtual = fs::current_path();
                        float retornoTamanho = sizeFile(caminhoAtual);
                        cout << "Size: " << retornoTamanho;
                    }
                }
            }
        }

        else {
            cout << "Comando nao reconhecido" << endl;
        }
    }

    return 0;
}

