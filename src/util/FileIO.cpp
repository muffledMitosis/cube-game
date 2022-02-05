#include "FileIO.hpp"
#include <fstream>
#include <sstream>

namespace Utils {
	
std::string fileToString(std::string filePath)
{
	std::ifstream f(filePath);
	std::stringstream buff;
	buff << f.rdbuf();
	return buff.str();
}

}
