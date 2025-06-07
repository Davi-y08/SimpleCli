#include "fileConfigs.hpp"
#include <fstream>
#include <iostream>
#include <string> 

namespace fs = std::filesystem;
using namespace std;
ifstream file;

void delFile(const fs::path& path) {
    std::error_code ec;
    if (fs::remove(path, ec)) {
        std::cout << "aquivo deletado com sucesso." << std::endl;
    }
    else {
        std::cerr << "Erro ao deletar arquivo: " << ec.message() << std::endl;
    }
}