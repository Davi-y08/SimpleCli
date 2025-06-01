#pragma once
#include <string>
#include <filesystem>;
using namespace std;
namespace fs = std::filesystem;
void search_in_file(const string& palavra, const string& nome_arquivo);