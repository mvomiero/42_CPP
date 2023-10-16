#include "BitcoinExchange.hpp"

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
	exchange.readInput(argv[1]);
	return (0);
}