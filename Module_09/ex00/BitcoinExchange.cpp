#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	this->data = rhs.data;
	return (*this);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

void BitcoinExchange::storeData()
{
	std::string line;
	std::ifstream file("./data.csv");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			std::string date = line.substr(0, line.find(','));
			std::string price = line.substr(line.find(',') + 1, line.length());
			//float price_float = atof(price.c_str());
			this->data[date] = atof(price.c_str());
			/*if (price_float == 0.0)
				std::cout << date << " " << price << std::endl;*/
		}
		file.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
}