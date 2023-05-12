
#ifndef PLEASE_MERGE_ME_HPP
#define PLEASE_MERGE_ME_HPP

#include "Colors.h"
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>
#include <list>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#define VERBOSE 1
#define VECTOR 0
#define LIST 1

class PmergeMe
{
	private:
		bool _container;

		std::vector<int> * _unsortedVector;
		std::vector<int> * _sortedVector;

		std::list<int> * _unsortedList;
		std::list<int> * _sortedList;

		int _straggler;

		void _fillVectorFromArray( int * array );
		void _fillListFromArray( int * array );
		void _sortVector( void );
		std::vector< std::pair<int, int> > _splitUnsortedVector( void );
		void _sortEachPair( std::vector< std::pair<int, int> > & splitVector );
		void _sortPairsByLargestValue( std::vector< std::pair<int, int> > &
		                               splitVector );
		void _insertionSortPairs( std::vector< std::pair<int, int> > &
		                          splitVector, int n );
		void _insertElement( std::vector< std::pair<int, int> > & splitVector,
		                     std::pair<int, int> element, int n );
		void _createSortedSequence( std::vector< std::pair<int, int> > & splitVector );
		std::vector<int> _createIndexInsertSequence(int pendingSize);
		std::vector<int> _buildJacobstahlInsertionSequence( int size );
		int _getJacobstahlNumber( int n );
		void _insertAtBisectedIndex( std::vector<int> & vector, int element );
		int _bisectVector( std::vector<int> vector, int x );
		void _extractStraggler( void );
		void _insertStraggler( void );

		void _sortList( void );

		template <typename T>
		void _printVector( std::vector<T> & vector, std::string name,
		                   std::string color );
		std::string _getVectorContentsAsString( std::vector<int> & vector );
		std::string _getVectorContentsAsString( std::vector< std::pair<int, int> > &
		                                        vector );

		PmergeMe( void );

	public:
		PmergeMe( int* array, bool container );
		PmergeMe( PmergeMe & src );
		~PmergeMe( void );

		PmergeMe & operator=( PmergeMe & src );
		void sort( void );
		std::vector<int> & getSortedVector( void );
};

#endif
