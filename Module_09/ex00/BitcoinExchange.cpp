#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	this->csv = rhs.csv;
	return (*this);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

void BitcoinExchange::readCsv()
{
	std::string line;
	std::ifstream file("./data.csv");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			std::string date = line.substr(0, line.find(','));
			std::string price = line.substr(line.find(',') + 1, line.length());
			// float price_float = atof(price.c_str());
			this->csv[date] = atof(price.c_str());
			/*if (price_float == 0.0)
				std::cout << date << " " << price << std::endl;*/
		}
		file.close();
	}
	else
		std::cout << "Unable to open file" << std::endl;
}

static bool dateCheck(std::string date)
{
	if (date.empty())
		return (false);
	return (true);
	// check if string is empty
	// check if atof of string is > 1000 or the result is 0.0 (just if the string is not == 0.0)
}

static bool valueCheck(std::string valueStr)
{
	if (valueStr.empty())
		return (false);
	float value = atof(valueStr.c_str());
	if (value > 1000 || value < 0)
		return (false);
	if (value == 0.0 && valueStr != "0.0" && valueStr != "0")
		return (false);
	return (true);
	// check if string is empty
	// check if atof of string is > 1000 or the result is 0.0 (just if the string is not == 0.0)
}

void BitcoinExchange::readInput(std::string inputFile)
{
	// open the input file
	std::string line;
	std::ifstream file(inputFile.c_str());
	if (file.is_open())
	{
		getline(file, line);
		while (getline(file, line))
		{
			std::cout << line << std::endl;
			size_t delimiterPos = line.find(" | ");
			if (delimiterPos != std::string::npos)
			{
				// Split the line into date and value
				std::string date = line.substr(0, delimiterPos);
				std::string value = line.substr(delimiterPos + 3);
				if (!dateCheck(date) || !valueCheck(value))
				{
					std::cout << "Error: bad input => " << line << std::endl;
					continue;
				}
				else
				{
					float value_float = atof(value.c_str()); // Check if the date exists in the csv map
					if (csv.find(date) != csv.end())
					{
						float csv_value = csv[date];
						float result = csv_value * value_float;
						std::cout << "Date: " << date << " | CSV Value: " << csv_value << " | Result: " << result << std::endl;
					}
					else
					{
						// If the date doesn't exist in the CSV, find the closest lower date
						std::map<std::string, float>::iterator it = csv.lower_bound(date);
						if (it != csv.begin())
						{
							it--; // Move to the lower date
							float csv_value = it->second;
							float result = csv_value * value_float;
							std::cout << "Date: " << date << " | Closest Lower CSV Date: " << it->first << " | CSV Value: " << csv_value << " | Result: " << result << std::endl;
						}
					}
				}
			}
		}
			file.close();
	}
}
