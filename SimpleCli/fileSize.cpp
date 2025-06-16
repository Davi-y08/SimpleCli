#include "fileConfigs.hpp"
#include <fstream>
#include <iostream>
#include <string> 
//**//
namespace fs = std::filesystem;
using namespace std;
ifstream inf_file;

float sizeFile(const fs::path& path) {
	fs::path pathFile(path);
	fs::recursive_directory_iterator end;
	float size = 0.f;

	for (fs::recursive_directory_iterator i(pathFile); i != end; i++)
	{
		if(fs::is_regular_file(*i)){
			size += fs::file_size(*i);
		}
	}

	return size;
}