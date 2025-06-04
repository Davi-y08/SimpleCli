#include "fileConfigs.hpp"
#include <fstream>
#include <iostream>
#include <string> 

namespace fs = std::filesystem;
using namespace std;
ifstream inf_file;

void delFile(fs::path& path) {
    std::error_code ec;
    if (fs::remove(path, ec)) {
        std::cout << "aquivo deletado com sucesso." << std::endl;
    }
    else {
        std::cerr << "Erro ao deletar arquivo: " << ec.message() << std::endl;
    }
}