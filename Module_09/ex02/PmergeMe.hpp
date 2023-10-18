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
#include <vector>

class PmergeMe
{
private:
	int oddNumber;

	std::vector<int> unsortedVector;
	std::vector<int> sortedVector;
	std::vector<int> pending;



	template <typename T>
	void removeDuplicates(std::vector<T>& vec);
	std::vector<std::pair<int, int> > splitIntoPairs();
	void sortPairs(std::vector<std::pair<int, int> > & splitVector);
	void sortPairsContainer(std::vector<std::pair<int, int> > & splitVector);

	void insertionSortPairs(std::vector<std::pair<int, int> > & splitVector, int n);
	void insertPair(std::vector<std::pair<int, int> > &splitVector, std::pair<int, int> element, int n);

	void splitIntoSortedandPending(std::vector<std::pair<int, int> > &splitVector);
	void createSortedSequence();
	std::vector<int> createIndexInsertSequence();
	int getJacobstahlNumber(int n);
	std::vector<int> buildJacobstahlInsertionSequence(int size);
	void insertIntoSortedVector(int element);

	template <typename T>
	void printVector(std::vector<T> &vector, std::string name, std::string color);

	void printPairs(const std::vector<std::pair<int, int> > &pairs, std::string str, std::string color);
	void printPairsRecursion(const std::vector<std::pair<int, int> > &pairs, std::string str, std::string color, int n);

	/* LIST */

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

	void sortVector(void);
	void sortList(void);

};