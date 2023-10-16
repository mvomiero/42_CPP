#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>

class BitcoinExchange
{
private:
	std::map <std::string, float> data;
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange& operator=(BitcoinExchange const &var);
	BitcoinExchange(BitcoinExchange const &other);

	void storeData();
};