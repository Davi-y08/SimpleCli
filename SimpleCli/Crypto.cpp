#pragma once 
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
using namespace std;

std::string xorEncryptDecrypt(const std::string& input, const std::string& key) {
	string output = input;
	for (size_t i = 0; i < input.size(); ++i) {
		output[i] = input[i] ^ key[i % key.size()];
	}

	return output;
}