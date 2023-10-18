#pragma once

#define VERBOSE 1
#define VERBOSE_RECURSION 0

#include "colors.h"
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <list>

class PmergeMe
{
private:
	int oddNumber;

	std::list<int> unsortedList;
	std::list<int> sortedList;
	std::list<int> pendingList;



	template <typename T>
	void removeDuplicatesList(std::list<T>& vec);
	std::list<std::pair<int, int> > splitIntoPairsList();
	void sortPairsList(std::list<std::pair<int, int> > & splitList);
	void sortPairsContainerList(std::list<std::pair<int, int> > & splitList);

	void insertionSortPairsList(std::list<std::pair<int, int> > & splitList, int n);
	void insertPairList(std::list<std::pair<int, int> > &splitList, std::pair<int, int> element, int n);

	void splitIntoSortedandPendingList(std::list<std::pair<int, int> > &splitList);
	void createSortedSequenceList();
	std::list<int> createIndexInsertSequenceList();
	int getJacobstahlNumberList(int n);
	std::list<int> buildJacobstahlInsertionSequenceList(int size);
	void insertIntoSortedList(int element);

	template <typename T>
	void printList(std::list<T> &list, std::string name, std::string color);

	void printPairsList(const std::list<std::pair<int, int> > &pairs, std::string str, std::string color);
	void printPairsRecursionList(const std::list<std::pair<int, int> > &pairs, std::string str, std::string color, int n);

public:
	PmergeMe(void);
	PmergeMe(PmergeMe &rhs);
	~PmergeMe(void);
	PmergeMe &operator=(PmergeMe &src);

	void fillContainers(int ac, char **av);

	void sort(void);

	void sortList(void);

};