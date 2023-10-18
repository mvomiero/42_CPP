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
#include <cstring>

#define VERBOSE 0

class BitcoinExchange
{
private:
    std::map <time_t, float> csv; // Change the map's key type to time_t

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange& operator=(BitcoinExchange const &var);
    BitcoinExchange(BitcoinExchange const &other);

    void readCsv();
    void printInstructions();
    void readInput(std::string inputFile);
};
