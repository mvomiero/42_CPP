#include "PmergeMe.hpp"

int main(int ac, char* av[])
{
	if (ac <= 1)
    {
        std::cerr << "error, no input" << std::endl;
        return 1;
    }
	PmergeMe merger;
	merger.fillContainers(ac, av);
	merger._sortVector();
}
