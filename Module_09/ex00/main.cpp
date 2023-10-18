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

	return (0);
}