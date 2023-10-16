#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	/*if (argc != 2)
	{
		std::cout << "Usage: ./bitcoin [dataBase]" << std::endl;
		return (1);
	}*/
	BitcoinExchange exchange;
	exchange.storeData();
	return (0);
}