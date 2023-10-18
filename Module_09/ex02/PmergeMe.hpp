#pragma once

#define VERBOSE 1
#define VERBOSE_RECURSION 1

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


	int getJacobstahlNumber(int n);


	std::vector<std::pair<int, int> > splitIntoPairs();
	void sortPairs(std::vector<std::pair<int, int> > & splitVector);
	void sortPairsContainer(std::vector<std::pair<int, int> > & splitVector);

	void insertionSortPairs(std::vector<std::pair<int, int> > & splitVector, int n);
	void insertPair(std::vector<std::pair<int, int> > &splitVector, std::pair<int, int> element, int n);

	void splitIntoSortedandPending(std::vector<std::pair<int, int> > &splitVector);
	void createSortedSequence();
	std::vector<int> createIndexInsertSequence();
	std::vector<int> buildJacobstahlInsertionSequence(int size);
	void insertIntoSortedVector(int element);

	void extractOddNumber(std::vector<int> &unsortedVector);
	void insertOddNumber(std::vector<int> &sortedVector);

	template <typename T>
	void printVector(std::vector<T> &vector, std::string name, std::string color);

	void printPairs(const std::vector<std::pair<int, int> > &pairs, std::string str, std::string color);
	void printPairsRecursion(const std::vector<std::pair<int, int> > &pairs, std::string str, std::string color, int n);

public:
	PmergeMe(void);
	PmergeMe(PmergeMe &rhs);
	~PmergeMe(void);
	PmergeMe &operator=(PmergeMe &src);

	void fillContainers(int ac, char **av);

	void sort(void);

	void sortVector(void);

};