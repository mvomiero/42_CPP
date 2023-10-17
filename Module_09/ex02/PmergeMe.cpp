#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	_unsortedVector = new std::vector<int>();
}

PmergeMe::~PmergeMe(void)
{
	delete _unsortedVector;
}


template <typename T>
void PmergeMe::printContainer(const T& container)
{
	(void)container;
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::fillContainers(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		int num = atoi(av[i]);
		if (num <= 0)
		{
			std::cerr << RED << "Error: invalid input -> " << av[i] << RESET << std::endl;
			exit(1);
		}
		_unsortedVector->push_back(num);
	}
	printContainer(*_unsortedVector);
}

void PmergeMe::_sortVector( void )
{
	printContainer( *_unsortedVector );

	if ( _unsortedVector->size() % 2 != 0 )
	{
		_straggler = _unsortedVector->back();
		_unsortedVector->pop_back();
	}

	std::vector< std::pair<int, int> > splitVector = _splitIntoPairs( *_unsortedVector );

	//_sortEachPair( splitVector );
	//_sortPairsByLargestValue( splitVector );
	//_createSortedSequence( splitVector );
	/*if ( _straggler != 0 )
	{
		_insertStraggler( *_sortedVector );
	}*/
}

void printPairs(const std::vector<std::pair<int, int> > &pairs)
{
    std::cout << "[ ";
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        const std::pair<int, int> &pair = pairs[i];
        std::cout << "[" << pair.first << "-" << pair.second << "] ";
    }
    std::cout << "]" << std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::_splitIntoPairs(std::vector<int> &unsortedVector)
{
    std::vector<std::pair<int, int> > splitVector;
    
    for (size_t i = 0; i < unsortedVector.size(); i += 2)
    {
        splitVector.push_back(std::make_pair(unsortedVector[i], unsortedVector[i + 1]));
    }
    
    printPairs(splitVector);
    
    return splitVector;
}