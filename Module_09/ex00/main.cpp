#include "BitcoinExchange.hpp"


/* ABSTRACT:
	creating a program that will calculate the value of a bitcoin wallet at a certain date, based on a csv database.

	1. read the csv file and store the data in a map
	2. read the input file and extract the date and the wallet value
	3. calculate the value of the wallet at the given date
 */

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Usage: ./btc [inputFile]" << std::endl;
		return (1);
	}
	BitcoinExchange exchange;
	exchange.readCsv();
	exchange.printInstructions();
	exchange.readInput(argv[1]);

    // Input date as a string in the format "yyyy-mm-dd"
    std::string dateString = "2011-01-03";

    struct tm dateStruct;
    std::memset(&dateStruct, 0, sizeof(dateStruct)); // Initialize the struct to zero
    if (strptime(dateString.c_str(), "%Y-%m-%d", &dateStruct) != NULL) {
        time_t yourTimeTValue = mktime(&dateStruct);

        if (yourTimeTValue != -1) {
            struct tm* timeinfo;
            char buffer[80];

            timeinfo = localtime(&yourTimeTValue);
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

            std::cout << "Formatted Date: " << buffer << std::endl;
        } else {
            std::cout << "Invalid date format" << std::endl;
        }
    } else {
        std::cout << "Invalid date format" << std::endl;
    }

	return (0);
}