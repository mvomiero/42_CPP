#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	_unsortedVector = new std::vector<int>();
	_sortedVector = new std::vector<int>();
}

PmergeMe::~PmergeMe(void)
{
	delete _unsortedVector;
	delete _sortedVector;
}


template <typename T>
void PmergeMe::printContainer(const T& container)
{
	(void)container;
	for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

    template <typename T>
    void PmergeMe::_printVector(std::vector<T> &vector, std::string name, std::string color) {
        std::cout << color << "[ ";
        for (typename std::vector<T>::const_iterator it = vector.begin(); it != vector.end(); it++) {
            std::cout << *it << " ";
        }
        std::cout << "]  -> " << name << "\x1B[0m" << std::endl;  // Reset color
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


	_createSortedSequence( splitVector );
	if ( _straggler != 0 )
	{
		insertIntoSortedVector( *_sortedVector , _straggler );
	}
	printContainer( *_sortedVector );
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
		printPairsRecursion( splitVector, "insertion sort pairs recursive", CYAN , n);
		_insertElement( splitVector, splitVector[n], n - 1 );
		//std::cout << CYAN << "n = " << n << " element is: " <<splitVector[n].second << RESET << std::endl;
	}
}

void PmergeMe::printPairsRecursion(const std::vector<std::pair<int, int> > &pairs, std::string str, std::string color, int n)
{
    std::cout << color << "[ ";
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        const std::pair<int, int> &pair = pairs[i];
		if ( static_cast<int>(i) == n )
			std::cout << RED "[" << pair.first << "-" << pair.second << "] " RESET;
		else
        std::cout << "[" << pair.first << "-" << pair.second << "] ";
    }
    std::cout << "]  -> " << str << RESET << std::endl;
}

void PmergeMe::_insertElement( std::vector< std::pair<int, int> > & splitVector,
                               std::pair<int, int> element, int n )
{
	if ( n < 0 )
	{
		if (VERBOSE_RECURSION) {std::cout << RED << " element [" << element.first << " " << element.second << "] has been set at position 0 -> " << n+1 << RESET << std::endl;}
		splitVector[0] = element;
	}
	else if ( element.second >= splitVector[n].second )
	{
		int size = splitVector.size();
		if ( n == size - 1 )
		{
			splitVector.push_back( element );
			if (VERBOSE_RECURSION) {std::cout << RED << "moving element [" << element.first << " " << element.second << "] to the END" << RESET << std::endl;}
		}
		else
		{
			splitVector[n + 1] = element;
			if (VERBOSE_RECURSION) {std::cout << RED << " element [" << element.first << " " << element.second << "] has been set at position " << n+1 << RESET << std::endl;}
		}
	}
	else
	{
		int size = splitVector.size();
		if ( n == size - 1 )
		{
			splitVector.push_back( splitVector[n] );
			if (VERBOSE_RECURSION) {std::cout << RED << "element sent to the back" << RESET << std::endl;}
		}
		else
		{
			splitVector[n + 1] = splitVector[n];
			if (VERBOSE_RECURSION) {std::cout << RED << "moving element [" << element.first << " " << element.second << "] to position " << n << " from position " << n+1 << RESET << std::endl;}

			_insertElement( splitVector, element, n - 1 );
		}
	}
}

void PmergeMe::_createSortedSequence( std::vector< std::pair<int, int> > &
                                      splitVector )
{
	std::vector<int> pending;

	std::vector< std::pair<int, int> >::iterator it = splitVector.begin();
	for ( ; it != splitVector.end(); it++ )
	{
		_sortedVector->push_back( it->second );
		pending.push_back( it->first );
	}
	_printVector( *_sortedVector, "Sorted", GREEN );
	_printVector( pending, "Pending", CYAN );

	std::vector<int> indexSequence = _createIndexInsertSequence( pending );

	_printVector( indexSequence, "Index Seq", PURPLE );

	//if (VERBOSE)
	//{
	//	std::cout << CYAN << std::setw( 35 ) << std::left << "Inserting...";
	//}

	
	for (std::vector<int>::iterator isit = indexSequence.begin(); isit != indexSequence.end(); isit++)
	{
		int numberToInsert = pending[*isit - 1];
		insertIntoSortedVector( *_sortedVector, numberToInsert );
	}

	//if (VERBOSE)
	//{
	//	std::cout << RESET << std::endl;
	//	_printVector( *_sortedVector, "Sorted", GREEN );
	//}
}

int PmergeMe::_getJacobstahlNumber( int n )
{
	if ( n == 0 )
		return ( 0 );
	else if ( n == 1 )
		return ( 1 );
	else
		return ( _getJacobstahlNumber( n - 1 ) + 2 * _getJacobstahlNumber( n - 2 ) );
}

std::vector<int> PmergeMe::_buildJacobstahlInsertionSequence( int size )
{
	std::vector<int> jacobSequence;
	int jacobIndex = 3;
	while ( _getJacobstahlNumber( jacobIndex ) < size - 1 )
	{
		jacobSequence.push_back( _getJacobstahlNumber( jacobIndex ) );
		jacobIndex++;
	}
	return ( jacobSequence );
}

std::vector<int> PmergeMe::_createIndexInsertSequence( std::vector<int> pending )
{
	bool lastWasJacobNumber = false;
	int pendingSize = pending.size();
	std::vector<int> jacobSequence = _buildJacobstahlInsertionSequence(pendingSize);

	_printVector( jacobSequence, "Jacobstahl", PURPLE );

	std::vector<int> indexSequence;

	indexSequence.push_back( 1 );
	int i = 1;
	while ( i <= pendingSize )
	{
		if ( jacobSequence.size() != 0 && lastWasJacobNumber == false )
		{
			indexSequence.push_back( jacobSequence[0] );
			jacobSequence.erase( jacobSequence.begin() );
			lastWasJacobNumber = true;
			continue;
		}
		std::vector<int>::iterator iit = indexSequence.begin();
		for ( ; iit != indexSequence.end(); iit++ )
		{
			if ( *iit == i )
			{
				i++;
			}
		}
		indexSequence.push_back( i );
		lastWasJacobNumber = false;
		i++;
	}
	return (indexSequence);
}

    void PmergeMe::insertIntoSortedVector(std::vector<int> &vector, int element) {
        if (VERBOSE) {
            std::cout << BLUE "[" << element << "]" RESET;
        }

        int lo = 0;
        int hi = vector.size();

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (element < vector[mid]) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        vector.insert(vector.begin() + lo, element);
    }


