#pragma once
#include <vector>
#include <string>
namespace Utils {
	void tokenize(const std::string& str, std::vector<std::string>& vec);
	std::vector<std::string> tokenize(const std::string& str);
}
