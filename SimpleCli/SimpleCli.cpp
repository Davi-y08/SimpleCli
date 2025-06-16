#include <iostream>
#include "search.hpp"
#include "fileConfigs.hpp"
#include "Crypto.hpp"
#include <sstream>
#include <string>
#include <filesystem>
#include "json.hpp"
#include <fstream>
#include "Ethernet.hpp"
#include <string.h>
#include <stdlib.h>
#include <chrono>
#include <thread>

using namespace std;
namespace fs = std::filesystem;
using json = nlohmann::json;

void clearScreen() {
#if defined(__linux__) || defined(__APPLE__)
    system("clear");
#elif defined(_WIN32)
    system("cls");
#else
    cout << "Comando de limpeza não suportado neste sistema.\n";
#endif
}

struct NovoLogin
{
    string site;
    string usuario;
    string senhaCriptografada;
};

struct Credenciais {
    string site;
    string usuario;
    string senha;
};

Credenciais infoInput() {
    Credenciais c;
    cout << "Digite o site: ";
    getline(cin, c.site);

    cout << "Digite o usuario: ";
    getline(cin, c.usuario);

    cout << "Digite a senha: ";
    getline(cin, c.senha);

    return c;
}

void jsonSave(const NovoLogin& novo, const std::string& caminho) {
    json j;
    std::ifstream inFile(caminho);
    if (inFile.is_open()) {
        inFile >> j;
        inFile.close();
    }

    j.push_back({
        {"site", novo.site},
        {"user", novo.usuario},
        {"senhacriptografada", novo.senhaCriptografada}
        });

    std::ofstream outfile(caminho);
    outfile << j.dump(4);
    outfile.close();
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
                        string pathFileForDel = inputInterno.substr(8);
                        fs::path caminhoEnviado = pathFileForDel;
                        delFile(caminhoEnviado);
                    }
                }
            }
        }

        else if (input->rfind("ping ", 0) == 0) {
            string site = input->substr(5);
            pingSite(site);
        }

        else if (*input == "addPass") {
            Credenciais entrada = infoInput();
            NovoLogin novo;

            string chave;
            cout << "Digite a chave para a criptografia: ";
            getline(cin, chave);

            novo.site = entrada.site;
            novo.usuario = entrada.usuario;
            novo.senhaCriptografada = xorEncryptDecrypt(entrada.senha, chave);

            jsonSave(novo, "senhas.j    son");
        }

        else if (input->rfind("pomodoro ", 0) == 0) {
            string inputMin = input->substr(9);
            int minutos = stoi(inputMin);
            int segundos = 59;
            int segundosTotais = minutos * 60;

            minutos -= 1;
            while (segundosTotais >= 0) {
                if (segundos < 0) {
                    segundos = 59;
                    minutos--;
                }

                
                if (minutos < 0) {
                    minutos = 0;
                    segundos = 0;
                }

                system("cls");
                cout << "Cronômetro: "
                    << (minutos < 10 ? "0" : "") << minutos << ":"
                    << (segundos < 10 ? "0" : "") << segundos << endl;

                this_thread::sleep_for(chrono::seconds(1));

                segundos--;
                segundosTotais--;
            }
        }

        else {
            cout << "Comando nao reconhecido" << endl;
        }
    }

    return 0;
}

