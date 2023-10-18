#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
}

PmergeMe::~PmergeMe(void)
{
}

template <typename T>
void PmergeMe::printVector(std::vector<T> &vector, std::string name, std::string color)
{
	std::cout << color << "[ ";
	for (typename std::vector<T>::const_iterator it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "]  -> " << name << RESET << std::endl;
}

template <typename T>
void PmergeMe::removeDuplicates(std::vector<T>& vec) {
    typename std::vector<T>::iterator it = std::unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
}

void PmergeMe::fillContainers(int ac, char **av)
{
	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "filling containers..." << RESET << std::endl;}
	for (int i = 1; i < ac; i++)
	{
		int num = atoi(av[i]);
		if (num <= 0)
		{
			std::cerr << RED << "Error: invalid input -> " << av[i] << RESET << std::endl;
			exit(1);
		}
		unsortedVector.push_back(num);
		unsortedList.push_back(num);
	}
	//removeDuplicates(unsortedVector);
	if (VERBOSE) {printVector(unsortedVector, "unsorted vector read", RED);}
}

void PmergeMe::sort()
{
	{
		if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "SORTING\n" << RESET << std::endl;}
		clock_t start = clock();
		sortVector();
		clock_t end = clock();
		// Calculate the time difference in microseconds
		double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

		// Print the time in the desired format
		std::cout << RED "Before: ";
		printVector(unsortedVector, "before", RED);
		std::cout << GREEN "After: ";
		printVector(sortedVector, "after", GREEN);
		std::cout << RESET "Time to process a range of " << sortedVector.size() << " elements with std::list : "<< elapsed_time << " us" << std::endl;
	}

	{
		if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "SORTING\n" << RESET << std::endl;}
		clock_t start = clock();
		sortList();
		clock_t end = clock();
		// Calculate the time difference in microseconds
		double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC * 1000000;

		// Print the time in the desired format
		std::cout << RED "Before: ";
		printList(unsortedList, "before", RED);
		std::cout << GREEN "After: ";
		printList(sortedList, "after", GREEN);
		std::cout << RESET "Time to process a range of " << sortedList.size() << " elements with std::list : "<< elapsed_time << " us" << std::endl;
	}

}

void PmergeMe::sortVector()
{
	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "sorting vector..." << RESET << std::endl;}

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "extracting odd number, if size is odd..." << RESET << std::endl;}

	if (unsortedVector.size() % 2 != 0)
	{
		oddNumber = unsortedVector.back();
		unsortedVector.pop_back();
		if (VERBOSE) { std::cout << PURPLE "\todd number " << oddNumber << " extracted from unsorted container" RESET << std::endl;}
	}
	else
		oddNumber = 0;

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "splitting vector into pairs..." << RESET << std::endl;}
	std::vector<std::pair<int, int> > splitVector = splitIntoPairs();

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "sorting each pair..." << RESET << std::endl;}
	sortPairs(splitVector);

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "sorting pairs by largest value..." << RESET << std::endl;}
	insertionSortPairs(splitVector, splitVector.size() - 1);
	if (VERBOSE) { printPairs(splitVector, "sorted array of pairs", GREEN); }

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "creating sorted sequence..." << RESET << std::endl;}
	splitIntoSortedandPending(splitVector);
	createSortedSequence();

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "inserting odd number, if any..." << RESET << std::endl;}
	if (oddNumber != 0)
	{
		insertIntoSortedVector(oddNumber);
		if (VERBOSE)
		{
			std::cout << BLUE "straggler number " << oddNumber << " inserted in sorted vector" RESET << std::endl;
		}
	}

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "sorted vector is ready!" << RESET << std::endl;}
	if (VERBOSE) { printVector(sortedVector, "SORTED!", BG_PURPLE); }
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

std::vector<std::pair<int, int> > PmergeMe::splitIntoPairs()
{
	std::vector<std::pair<int, int> > splitVector;

	for (size_t i = 0; i < unsortedVector.size(); i += 2)
	{
		splitVector.push_back(std::make_pair(unsortedVector[i], unsortedVector[i + 1]));
	}

	if (VERBOSE) {printPairs(splitVector, "split pairs", YELLOW);}

	return splitVector;
}

void PmergeMe::sortPairs(std::vector<std::pair<int, int> > &splitVector)
{

	for (std::vector<std::pair<int, int> >::iterator it = splitVector.begin(); it != splitVector.end(); it++)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	if (VERBOSE) {printPairs(splitVector, "sorted single pairs", PURPLE);}
}

void PmergeMe::insertionSortPairs(std::vector<std::pair<int, int> > & splitVector, int n)
{
	if (n == 0)
	{
		return;
	}
	else
	{
		insertionSortPairs(splitVector, n - 1);
		if (VERBOSE) {printPairsRecursion(splitVector, "insertion sort pairs recursive", CYAN, n);}
		insertPair(splitVector, splitVector[n], n - 1);
	}
}

void PmergeMe::printPairsRecursion(const std::vector<std::pair<int, int> > &pairs, std::string str, std::string color, int n)
{
	std::cout << color << "[ ";
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		const std::pair<int, int> &pair = pairs[i];
		if (static_cast<int>(i) == n)
			std::cout << RED "[" << pair.first << "-" << pair.second << "] " RESET;
		else
			std::cout << "[" << pair.first << "-" << pair.second << "] ";
	}
	std::cout << "]  -> " << str << RESET << std::endl;
}

void PmergeMe::insertPair(std::vector<std::pair<int, int> > &splitVector, std::pair<int, int> element, int n)
{
	if (n < 0)
	{
		if (VERBOSE_RECURSION)
		{
			std::cout << RED << " element [" << element.first << " " << element.second << "] has been set at position 0 -> " << n + 1 << RESET << std::endl;
		}
		splitVector[0] = element;
	}
	else if (element.second >= splitVector[n].second)
	{
		int size = splitVector.size();
		if (n == size - 1)
		{
			splitVector.push_back(element);
			if (VERBOSE_RECURSION)
			{
				std::cout << RED << "moving element [" << element.first << " " << element.second << "] to the END" << RESET << std::endl;
			}
		}
		else
		{
			splitVector[n + 1] = element;
			if (VERBOSE_RECURSION)
			{
				std::cout << RED << " element [" << element.first << " " << element.second << "] has been set at position " << n + 1 << RESET << std::endl;
			}
		}
	}
	else
	{
		int size = splitVector.size();
		if (n == size - 1)
		{
			splitVector.push_back(splitVector[n]);
			if (VERBOSE_RECURSION)
			{
				std::cout << RED << "element sent to the back" << RESET << std::endl;
			}
		}
		else
		{
			splitVector[n + 1] = splitVector[n];
			if (VERBOSE_RECURSION)
			{
				std::cout << RED << "moving element [" << element.first << " " << element.second << "] to position " << n << " from position " << n + 1 << RESET << std::endl;
			}

			insertPair(splitVector, element, n - 1);
		}
	}
}

void PmergeMe::splitIntoSortedandPending(std::vector<std::pair<int, int> > &
										 splitVector)
{
	std::vector<std::pair<int, int> >::iterator it = splitVector.begin();
	for (; it != splitVector.end(); it++)
	{
		sortedVector.push_back(it->second);
		pending.push_back(it->first);
	}
	if (VERBOSE) { printVector(sortedVector, "Sorted", GREEN); }
	if (VERBOSE) { printVector(pending, "Pending", CYAN); }

}

void PmergeMe::createSortedSequence()
{
	//std::vector<int> pending;


	std::vector<int> indexSequence = createIndexInsertSequence();

	if (VERBOSE) { printVector(indexSequence, "Index Seq", PURPLE); }


	for (std::vector<int>::iterator isit = indexSequence.begin(); isit != indexSequence.end(); isit++)
	{
		int numberToInsert = pending[*isit - 1];
		insertIntoSortedVector(numberToInsert);
		if (VERBOSE)
		{
			std::cout << BLUE " number " << numberToInsert << " inserted in sorted vector. sequence index is: " << *isit << "" RESET << std::endl;
		}
	}

	if (VERBOSE)
	{
		std::cout << RESET << std::endl;
		printVector(sortedVector, "Sorted", GREEN);
	}
}

int PmergeMe::getJacobstahlNumber(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (getJacobstahlNumber(n - 1) + 2 * getJacobstahlNumber(n - 2));
}

std::vector<int> PmergeMe::buildJacobstahlInsertionSequence(int size)
{
	std::vector<int> jacobSequence;
	int jacobIndex = 3;
	while (getJacobstahlNumber(jacobIndex) < size - 1)
	{
		jacobSequence.push_back(getJacobstahlNumber(jacobIndex));
		jacobIndex++;
	}
	return (jacobSequence);
}

std::vector<int> PmergeMe::createIndexInsertSequence()
{
	bool lastWasJacobNumber = false;
	int pendingSize = pending.size();
	std::vector<int> jacobSequence = buildJacobstahlInsertionSequence(pendingSize);

	if (VERBOSE) { printVector(jacobSequence, "Jacobstahl", PURPLE); }

	std::vector<int> indexSequence;

	indexSequence.push_back(1);
	int i = 1;
	while (i <= pendingSize)
	{
		if (jacobSequence.size() != 0 && lastWasJacobNumber == false)
		{
			indexSequence.push_back(jacobSequence[0]);
			jacobSequence.erase(jacobSequence.begin());
			lastWasJacobNumber = true;
			continue;
		}
		std::vector<int>::iterator iit = indexSequence.begin();
		for (; iit != indexSequence.end(); iit++)
		{
			if (*iit == i)
			{
				i++;
			}
		}
		indexSequence.push_back(i);
		lastWasJacobNumber = false;
		i++;
	}
	return (indexSequence);
}

void PmergeMe::insertIntoSortedVector(int element)
{
	if (VERBOSE)
	{
		std::cout << BLUE "[" << element << "]" RESET;
	}

	// Initialize the low and high indices for binary search.
	int lo = 0;
	int hi = sortedVector.size();

	// Perform binary search to find the correct position for the element.
	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (element < sortedVector[mid])
		{
			hi = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}

	// Insert the element into the sortedVector at the determined position.
	sortedVector.insert(sortedVector.begin() + lo, element);
}


/* LIST */

template <typename T>
void PmergeMe::printList(std::list<T> &list, std::string name, std::string color)
{
	std::cout << color << "[ ";
	for (typename std::list<T>::const_iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << "]  -> " << name << RESET << std::endl;
}

template <typename T>
void PmergeMe::removeDuplicatesList(std::list<T>& vec) {
    typename std::list<T>::iterator it = std::unique(vec.begin(), vec.end());
    vec.erase(it, vec.end());
}


void PmergeMe::sortList()
{
	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "sorting list..." << RESET << std::endl;}

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "extracting odd number, if size is odd..." << RESET << std::endl;}

	if (unsortedList.size() % 2 != 0)
	{
		oddNumber = unsortedList.back();
		unsortedList.pop_back();
		if (VERBOSE) { std::cout << PURPLE "\todd number " << oddNumber << " extracted from unsorted container" RESET << std::endl;}
	}
	else
		oddNumber = 0;

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "splitting list into pairs..." << RESET << std::endl;}
	std::list<std::pair<int, int> > splitList = splitIntoPairsList();

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "sorting each pair..." << RESET << std::endl;}
	sortPairsList(splitList);

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "sorting pairs by largest value..." << RESET << std::endl;}
	insertionSortPairsList(splitList, splitList.size() - 1);
	if (VERBOSE) { printPairsList(splitList, "sorted array of pairs", GREEN); }

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "creating sorted sequence..." << RESET << std::endl;}
	splitIntoSortedandPendingList(splitList);
	createSortedSequenceList();

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "inserting odd number, if any..." << RESET << std::endl;}
	if (oddNumber != 0)
	{
		insertIntoSortedList(oddNumber);
		if (VERBOSE)
		{
			std::cout << BLUE "straggler number " << oddNumber << " inserted in sorted list" RESET << std::endl;
		}
	}

	if (VERBOSE) { std::cout << BG_BRIGHT_BLACK << "sorted list is ready!" << RESET << std::endl;}
	if (VERBOSE) { printList(sortedList, "SORTED!", BG_PURPLE); }
}

void PmergeMe::printPairsList(const std::list<std::pair<int, int> > &pairs, std::string str, std::string color)
{
    std::cout << color << "[ ";
    for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        const std::pair<int, int> &pair = *it;
        std::cout << "[" << pair.first << "-" << pair.second << "] ";
    }
    std::cout << "]  -> " << str << RESET << std::endl;
}


std::list<std::pair<int, int> > PmergeMe::splitIntoPairsList()
{
    std::list<std::pair<int, int> > splitList;
    std::list<int>::const_iterator it = unsortedList.begin();

    while (it != unsortedList.end())
    {
        if (++it != unsortedList.end())
        {
            int first = *it;
            if (++it != unsortedList.end())
            {
                int second = *it;
                splitList.push_back(std::make_pair(first, second));
            }
        }
    }

    if (VERBOSE) { printPairsList(splitList, "split pairs", YELLOW); }

    return splitList;
}



void PmergeMe::sortPairsList(std::list<std::pair<int, int> > &splitList)
{

	for (std::list<std::pair<int, int> >::iterator it = splitList.begin(); it != splitList.end(); it++)
	{
		if (it->first > it->second)
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	if (VERBOSE) {printPairsList(splitList, "sorted single pairs", PURPLE);}
}

void PmergeMe::insertionSortPairsList(std::list<std::pair<int, int> > &splitList, int n)
{
    if (n == 0)
    {
        return;
    }
    else
    {
        std::list<std::pair<int, int> >::iterator it = splitList.begin();
        std::advance(it, n);

        insertionSortPairsList(splitList, n - 1);

        if (VERBOSE)
        {
            printPairsRecursionList(splitList, "insertion sort pairs recursive", CYAN, n);
        }

        std::pair<int, int> pairToInsert = *it; // Make a copy of the pair
        insertPairList(splitList, pairToInsert, n - 1);
    }
}



void PmergeMe::printPairsRecursionList(const std::list<std::pair<int, int> > &pairs, std::string str, std::string color, int n)
{
    std::cout << color << "[ ";
    std::list<std::pair<int, int> >::const_iterator it = pairs.begin();
    
    for (int i = 0; it != pairs.end(); ++i, ++it)
    {
        const std::pair<int, int> &pair = *it;
        
        if (i == n)
            std::cout << RED << "[" << pair.first << "-" << pair.second << "] " << RESET;
        else
            std::cout << "[" << pair.first << "-" << pair.second << "] ";
    }
    
    std::cout << "]  -> " << str << RESET << std::endl;
}


void PmergeMe::insertPairList(std::list<std::pair<int, int> > &splitList, std::pair<int, int> element, int n)
{
	std::list< std::pair<int, int> >::iterator it = splitList.begin();
	std::advance( it, n );
	std::list< std::pair<int, int> >::iterator next = it;
	next++;

	if ( n < 0 )
	{
		*splitList.begin() = element;
	}
	else if ( element.second >= it->second )
	{
		int size = splitList.size();
		if ( n == size - 1 )
		{
			splitList.push_back( element );
		}
		else
		{
			*next = element;
		}
	}
	else
	{
		int size = splitList.size();
		if ( n == size - 1 )
		{
			splitList.push_back( *it );
		}
		else
		{
			*next = *it;
			insertPairList( splitList, element, n - 1 );
		}
	}
}

void PmergeMe::splitIntoSortedandPendingList(std::list<std::pair<int, int> > &
										 splitList)
{
	std::list<std::pair<int, int> >::iterator it = splitList.begin();
	for (; it != splitList.end(); it++)
	{
		sortedList.push_back(it->second);
		pendingList.push_back(it->first);
	}
	if (VERBOSE) { printList(sortedList, "Sorted", GREEN); }
	if (VERBOSE) { printList(pendingList, "Pending", CYAN); }

}

void PmergeMe::createSortedSequenceList()
{
	//std::list<int> pending;


	std::list<int> indexSequence = createIndexInsertSequenceList();

	if (VERBOSE) { printList(indexSequence, "Index Seq", PURPLE); }


	for (std::list<int>::iterator isit = indexSequence.begin(); isit != indexSequence.end(); isit++)
	{
		std::list<int>::iterator pendingIt = pendingList.begin();
		std::advance(pendingIt, *isit - 1);

		int numberToInsert = *pendingIt;
		insertIntoSortedList(numberToInsert);

		if (VERBOSE)
		{
			std::cout << BLUE " number " << numberToInsert << " inserted in sorted list. sequence index is: " << *isit << "" RESET << std::endl;
		}
	}

	if (VERBOSE)
	{
		std::cout << RESET << std::endl;
		printList(sortedList, "Sorted", GREEN);
	}
}

int PmergeMe::getJacobstahlNumberList(int n)
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (getJacobstahlNumberList(n - 1) + 2 * getJacobstahlNumberList(n - 2));
}

std::list<int> PmergeMe::buildJacobstahlInsertionSequenceList(int size)
{
	std::list<int> jacobSequence;
	int jacobIndex = 3;
	while (getJacobstahlNumberList(jacobIndex) < size - 1)
	{
		jacobSequence.push_back(getJacobstahlNumberList(jacobIndex));
		jacobIndex++;
	}
	return (jacobSequence);
}

std::list<int> PmergeMe::createIndexInsertSequenceList()
{
    bool lastWasJacobNumber = false;
    int pendingSize = pendingList.size();
    std::list<int> jacobSequence = buildJacobstahlInsertionSequenceList(pendingSize);

    if (VERBOSE) { printList(jacobSequence, "Jacobstahl", PURPLE); }

    std::list<int> indexSequence;

    indexSequence.push_back(1);
    int i = 1;

    std::list<int>::iterator jacobIt = jacobSequence.begin();

    while (i <= pendingSize)
    {
        if (jacobIt != jacobSequence.end() && lastWasJacobNumber == false)
        {
            indexSequence.push_back(*jacobIt);
            jacobIt = jacobSequence.erase(jacobIt);
            lastWasJacobNumber = true;
            continue;
        }

        std::list<int>::iterator iit = indexSequence.begin();
        while (iit != indexSequence.end())
        {
            if (*iit == i)
            {
                i++;
            }
            ++iit;
        }

        indexSequence.push_back(i);
        lastWasJacobNumber = false;
        i++;
    }

    return indexSequence;
}


void PmergeMe::insertIntoSortedList(int element)
{
    if (VERBOSE)
    {
        std::cout << BLUE "[" << element << "]" RESET;
    }

    std::list<int>::iterator lo = sortedList.begin();
    std::list<int>::iterator hi = sortedList.end();

    while (lo != hi)
    {
        std::list<int>::iterator mid = lo;
        std::advance(mid, std::distance(lo, hi) / 2);

        if (element < *mid)
        {
            hi = mid;
        }
        else
        {
            lo = mid;
            ++lo; // Move lo one step right.
        }
    }

    // Insert the element into the sortedList at the determined position.
    sortedList.insert(lo, element);
}


