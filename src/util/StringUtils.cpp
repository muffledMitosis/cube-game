#include "StringUtils.hpp"
#include <string>
#include <vector>
#include <regex>

namespace Utils {

std::vector<std::string> tokenize(const std::string& str)
{
	std::vector<std::string> ret;

	std::regex word_reg("(\\w+)");
	auto words_begin = std::sregex_iterator(
			str.begin(),
			str.end(), word_reg);
	auto words_end = std::sregex_iterator();

	for(auto i = words_begin; i!=words_end; i++)
	{
		std::smatch match = *i;
		ret.push_back(match.str());
	}
	return ret;
}

void tokenize(const std::string& str, std::vector<std::string>& vec)
{
	std::vector<std::string> ret;

	std::regex word_reg("(\\w+)");
	auto words_begin = std::sregex_iterator(
			str.begin(),
			str.end(), word_reg);
	auto words_end = std::sregex_iterator();

	for(auto i = words_begin; i!=words_end; i++)
	{
		std::smatch match = *i;
		vec.push_back(match.str());
	}
}

}
