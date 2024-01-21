#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "colors.h"

class BitcoinExchange
{
private:
	std::map <std::string, float> csv;

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange& operator=(BitcoinExchange const &var);
	BitcoinExchange(BitcoinExchange const &other);

	void readCsv();
	void printInstructions();
	void readInput(std::string inputFile);
};