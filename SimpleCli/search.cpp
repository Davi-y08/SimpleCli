#include "search.hpp"
#include <fstream>
#include <iostream>
#include <string> 
using namespace std;
void search_in_file(const string& palavra, const string& nome_arquivo) {
	ifstream arquivo(nome_arquivo);

	if (!arquivo) {
		cerr << "Erro ao abrir o arquivo";
		return;
	}

	string linha;

	int numero_linha = 1;

	while (std::getline(arquivo, linha)) {
		if (linha.find(palavra) != std::string::npos) {
			std::cout << numero_linha << ": " << linha << "\n";
		}
		numero_linha++;
	}
}