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

	_sortEachPair( splitVector );

	//int length = splitVector.size();
	_insertionSortPairs( splitVector, splitVector.size() - 1 );
	printPairs( splitVector, "sorted array of pairs", GREEN );


	//_createSortedSequence( splitVector );
	/*if ( _straggler != 0 )
	{
		_insertStraggler( *_sortedVector );
	}*/
}

void PmergeMe::printPairs(const std::vector<std::pair<int, int> > &pairs, std::string str, std::string color)
{
    std::cout << color << "[ ";
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        const std::pair<int, int> &pair = pairs[i];
        std::cout << "[" << pair.first << "-" << pair.second << "] ";
    }
    std::cout << "]  -> " << str << RESET << std::endl;
}

std::vector<std::pair<int, int> > PmergeMe::_splitIntoPairs(std::vector<int> &unsortedVector)
{
    std::vector<std::pair<int, int> > splitVector;
    
    for (size_t i = 0; i < unsortedVector.size(); i += 2)
    {
        splitVector.push_back(std::make_pair(unsortedVector[i], unsortedVector[i + 1]));
    }
    
    printPairs(splitVector, "split pairs", YELLOW);
    
    return splitVector;
}

void PmergeMe::_sortEachPair( std::vector< std::pair<int, int> > & splitVector )
{
	
	for (std::vector< std::pair<int, int> >::iterator it = splitVector.begin(); it != splitVector.end(); it++ )
	{
		if( it->first > it->second )
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	printPairs(splitVector, "sorted single pairs", PURPLE);
}

void PmergeMe::_insertionSortPairs( std::vector< std::pair<int, int> > &
                                    splitVector, int n )
{
	if ( n == 0 )
	{
		return ;
	}
	else
	{
		_insertionSortPairs( splitVector, n - 1 );
		_insertElement( splitVector, splitVector[n], n - 1 );
		printPairs( splitVector, "insertion sort pairs recursive", CYAN );
	}
}

void PmergeMe::_insertElement( std::vector< std::pair<int, int> > & splitVector,
                               std::pair<int, int> element, int n )
{
	if ( n < 0 )
	{
		splitVector[0] = element;
	}
	else if ( element.second >= splitVector[n].second )
	{
		int size = splitVector.size();
		if ( n == size - 1 )
		{
			splitVector.push_back( element );
		}
		else
		{
			splitVector[n + 1] = element;
		}
	}
	else
	{
		int size = splitVector.size();
		if ( n == size - 1 )
		{
			splitVector.push_back( splitVector[n] );
		}
		else
		{
			splitVector[n + 1] = splitVector[n];
			_insertElement( splitVector, element, n - 1 );
		}
	}
}