#include "PmergeMe.hpp"

int main(int ac, char* av[])
{
	if (ac <= 1)
    {
        std::cerr << "error, wrong input" << std::endl;
        return 1;
    }
	if (ac == 2)
	{
		std::cerr << "error, just one argument" << std::endl;
		return 1;
	}
	PmergeMe merger;
	merger.fillContainers(ac, av);
	merger.sort();
}
