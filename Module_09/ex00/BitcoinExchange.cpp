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
        getline(file, line);
        while (getline(file, line))
        {
            size_t delimiterPos = line.find(',');
            if (delimiterPos != std::string::npos)
            {
                std::string dateString = line.substr(0, delimiterPos);
                std::string priceStr = line.substr(delimiterPos + 1);

                    struct tm date; // Create a tm struct to store the date
    				std::memset(&date, 0, sizeof(date)); // Initialize the tm struct

					// Parse the date string into the tm struct
					if (sscanf(dateString.c_str(), "%d-%d-%d", &date.tm_year, &date.tm_mon, &date.tm_mday) == 3) {
						date.tm_year -= 1900; // Adjust year
						date.tm_mon--; // Adjust month (0-11)

						// Convert the tm struct to a time_t
						time_t time = mktime(&date);

						// You now have a time_t representing the date with a precision of one day
						std::cout << "Date: " << asctime(&date);
						(void)time;
					} 
                    else
                    {
                        std::cout << "Error: Invalid date format => " << dateString << std::endl;
                    }
			}
            }
        }

        file.close();
    }





void BitcoinExchange::printInstructions()
{
	std::cout << PURPLE BOLD "Welcome to the Bitcoin Exchanger calculator" RESET << std::endl;
	std::cout << "Database ranges forom date: " << csv.begin()->first << " to date " << (--csv.end())->first << std::endl;
	std::cout << "everything out of this date range will be considered as a bad input error" << std::endl;
	std::cout << "Values accepted for 0 are just 0 or 0.0" << std::endl;
	std::cout << "everything else will be considered as a bad input error\n" << std::endl;
	std::cout << "Atoi-style conversion of the input values, so just the digits of this field will be considered" << std::endl;
}

static bool dateCheck(std::string date, time_t& timeValue)
{
    if (date.empty())
        return false;

    struct tm dateStruct;
    if (strptime(date.c_str(), "%Y-%m-%d", &dateStruct) == NULL) {
        return false;
    }

    timeValue = mktime(&dateStruct);
	if (timeValue == -1)
		std::cout << "Error: mktime() failed" << std::endl;

	struct tm* timeinfo;
	char buffer[80];

	// Use localtime to convert the time_t value to a tm structure
	timeinfo = localtime(&timeValue);

	// Use strftime to format it as a string
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

	// Now you can print the formatted date
	std::cout << "Formatted Date: " << buffer << std::endl;
    return (timeValue != -1);
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
}

void BitcoinExchange::readInput(std::string inputFile)
{
    // open the input file
    std::string line;
    std::ifstream file(inputFile.c_str());
    if (file.is_open())
    {
        getline(file, line); // skip the first line

        while (getline(file, line)) // read the file line by line
        {
            std::cout << "\n" << line << std::endl;

            size_t delimiterPos = line.find(" | ");
            if (delimiterPos != std::string::npos)
            {
                // Split the line into date and value
                std::string dateStr = line.substr(0, delimiterPos);
                std::string valueStr = line.substr(delimiterPos + 3);

                time_t date;
                if (!dateCheck(dateStr, date) || !valueCheck(valueStr))
                {
                    std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
                    continue;
                }
                else
                {
                    float value_float = atof(valueStr.c_str());
					
                    if (csv.find(date) != csv.end())  // Check if the date exists in the csv map
                    {
                        float csv_value = csv[date];
                        float result = csv_value * value_float;
                        std::cout << GREEN << "Date: " << dateStr << " | CSV Value: " << csv_value << " | Result: " << result << RESET << std::endl;
                    }
                    else
                    {
                        // If the date doesn't exist in the CSV, find the closest lower date
                        std::map<time_t, float>::iterator it = csv.lower_bound(date);
                        if (it != csv.begin() && it != csv.end()) // Check if the iterator is not at the beginning or at the end of the map (if it is, it means that the date is out of range)
                        {
                            it--; // Move to the lower date
                            float csv_value = it->second;
                            float result = csv_value * value_float;
                            std::cout << GREEN << "Date: " << dateStr << " | Closest Lower CSV Date: " << it->first << " | CSV Value: " << csv_value << " | Result: " << result << RESET << std::endl;
                        }
                        else
                            std::cout << RED << "Error: bad input => " << line << RESET << std::endl;
                    }
                }
            }
            else
                std::cout << RED << "Error: bad input line => " << line << RESET << std::endl;
        }
        file.close();
    }
}