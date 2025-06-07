#include <iostream>
#include "search.hpp"
#include "fileConfigs.hpp"
#include <sstream>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void clearScreen() {
#if defined(__linux__) || defined(__APPLE__)
    system("clear");
#elif defined(_WIN32)
    system("cls");
#else
    cout << "Comando de limpeza não suportado neste sistema.\n";
#endif
}

int main()
{
    bool saida = false;
    std::unique_ptr<string> input = std::make_unique<string>();

    cout << "=----//----=";
    cout << "\n";
    cout << "SimpleCli";
    cout << "\n";
    cout << "=----//----=";  
    cout << "\n";

    while (!saida) {
        std::cout << fs::current_path() << "> ";
        getline(cin, *input);

        if (*input == "scape") {
            saida = true;
        }

        else if (*input == "clean") {
            clearScreen();
        }

        else if (input->rfind("ent ", 0) == 0) {
            string path = input->substr(4);
            error_code ec;
            fs::current_path(path, ec);
            bool saidaInterna = false;

            if (ec) {
                std::cerr << "Erro ao mudar de diretório: " << ec.message() << "\n";
            }

            else {
                while (!saidaInterna) {
                    string inputInterno = "";
                    fs::path caminhoAtual = fs::current_path();
                    cout << fs::current_path() << " (sub)> ";
                    getline(cin, inputInterno);
                    if (inputInterno == "back") {
                        fs::current_path("..");
                        saidaInterna = true;
                    }
                    else if (inputInterno == "where") {
                        cout << fs::current_path() << "\n";
                    }
                    else if (inputInterno == "veri") {
                        
                        float retornoTamanho = sizeFile(caminhoAtual);
                        cout << "Size: " << retornoTamanho << endl;
                    }
                    else if (inputInterno == "del") {
                        delFile(caminhoAtual);
                    }
                    else if (inputInterno.rfind("delFile ", 0) == 0) {
                          
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

