#pragma once	

#define VERBOSE 1

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

		int _straggler;


		int _getJacobstahlNumber( int n );


		std::vector<int> * _unsortedVector;
		std::vector<int> * _sortedVector;

		void _fillVectorFromArray( int * array );
		
		std::vector< std::pair<int, int> > _splitIntoPairs( std::vector<int> & unsortedVector );
		void _sortEachPair( std::vector< std::pair<int, int> > & splitVector );
		void _sortPairsByLargestValue( std::vector< std::pair<int, int> > &
		                               splitVector );
		void _insertionSortPairs( std::vector< std::pair<int, int> > &
		                          splitVector, int n );
		void _insertElement( std::vector< std::pair<int, int> > & splitVector,
		                     std::pair<int, int> element, int n );
		void _createSortedSequence( std::vector< std::pair<int, int> > & splitVector );
		std::vector<int> _createIndexInsertSequence( std::vector<int> pending );
		std::vector<int> _buildJacobstahlInsertionSequence( int size );
		void _insertAtBisectedIndex( std::vector<int> & vector, int element );
		int _bisect( std::vector<int> vector, int x );
		void _extractStraggler( std::vector<int> & unsortedVector );
		void _insertStraggler( std::vector<int> & sortedVector );

		template <typename T>
		void _printVector( std::vector<T> & vector, std::string name,
		                   std::string color );
		std::string _getVectorContentsAsString( std::vector<int> & vector );
		std::string _getVectorContentsAsString( std::vector< std::pair<int, int> > &
		                                        vector );


	public:
		PmergeMe( void );
		//PmergeMe( int* array, bool container );
		PmergeMe( PmergeMe & rhs );
		~PmergeMe( void );

		PmergeMe & operator=( PmergeMe & src );
		void sort( void );
		std::vector<int> & getSortedVector( void );
		std::list<int> & getSortedList( void );

		void fillContainers(int ac, char **av);

		template <typename T>
		void printContainer(const T& container);

		void _sortVector( void );

		void printPairs(const std::vector<std::pair<int, int> > &pairs, std::string str, std::string color);
};