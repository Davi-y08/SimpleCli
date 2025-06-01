#pragma once
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

float sizeFile(const fs::path& path);