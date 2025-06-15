#pragma once 
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

std::string xorEncryptDecrypt(const std::string& input, const std::string& key);