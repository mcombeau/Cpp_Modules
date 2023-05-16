#include "PmergeMe.hpp"
#include "Colors.h"
#include <ios>
#include <iterator>
#include <list>
#include <sstream>
#include <utility>
#include <vector>

/* ---------------------------------------------------------- SHARED */
PmergeMe::PmergeMe( void ) {}

PmergeMe::~PmergeMe( void ) {
	delete _unsortedVector;
	delete _sortedVector;
	delete _unsortedList;
	delete _sortedList;
}

PmergeMe::PmergeMe( int* array, bool container ) : _container( container )
{
	_unsortedVector = new std::vector<int>();
	_sortedVector = new std::vector<int>();
	_unsortedList = new std::list<int>();
	_sortedList = new std::list<int>();
	if ( container == VECTOR )
	{
		_fillVectorFromArray( array );
	}
	else if ( container == LIST )
	{
		_fillListFromArray( array );
	}
}

PmergeMe::PmergeMe( PmergeMe & src )
{
	( void )src;
}

PmergeMe & PmergeMe::operator=( PmergeMe & src )
{
	( void )src;
	return ( *this );
}

void PmergeMe::sort( void )
{
	if ( _container == VECTOR )
	{
		_sortVector();
	}
	else if ( _container == LIST )
	{
		_sortList();
	}
}

int PmergeMe::_getJacobstahlNumber( int n )
{
	if ( n == 0 )
	{
		return ( 0 );
	}
	if ( n == 1 )
	{
		return ( 1 );
	}
	return ( _getJacobstahlNumber( n - 1 ) + 2 * _getJacobstahlNumber( n - 2 ) );
}

/* ---------------------------------------------------------- VECTOR */

std::vector<int> & PmergeMe::getSortedVector( void )
{
	return (*_sortedVector);
}

void PmergeMe::_fillVectorFromArray( int * array )
{
	for ( int i = 0; array[i]; i++ )
	{
		_unsortedVector->push_back( array[i] );
	}
}

void PmergeMe::_sortVector( void )
{
	_printVector( *_unsortedVector, "Unsorted", PURPLE );
	bool hasStraggler = _unsortedVector->size() % 2 != 0;
	if ( hasStraggler )
	{
		_extractStraggler( *_unsortedVector );
	}
	std::vector< std::pair<int, int> > splitVector = _splitIntoPairs( *_unsortedVector );
	_sortEachPair( splitVector );
	_sortPairsByLargestValue( splitVector );
	_createSortedSequence( splitVector );
	if ( hasStraggler )
	{
		_insertStraggler( *_sortedVector );
	}
}

std::vector< std::pair<int, int> > PmergeMe::_splitIntoPairs( std::vector<int> & unsortedVector )
{
	std::vector< std::pair<int, int> > splitVector;
	int first = 0;
	std::vector<int>::iterator it = unsortedVector.begin();
	for ( ; it != unsortedVector.end(); it++ )
	{
		if ( first == 0 )
		{
			first = *it;
		}
		else
		{
			splitVector.push_back( std::make_pair( first, *it ) );
			first = 0;
		}
	}
	_printVector( splitVector, "Split pair", YELLOW );
	return ( splitVector );
}

void PmergeMe::_sortEachPair( std::vector< std::pair<int, int> > & splitVector )
{
	std::vector< std::pair<int, int> >::iterator it = splitVector.begin();
	for ( ; it != splitVector.end(); it++ )
	{
		if( it->first > it->second )
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	_printVector( splitVector, "Split pair", YELLOW );
}

void PmergeMe::_sortPairsByLargestValue( std::vector< std::pair<int, int> > &
        splitVector )
{
	int length = splitVector.size();
	_insertionSortPairs( splitVector, length - 1 );
	_printVector( splitVector, "Split pair", YELLOW );
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
	std::vector<int> indexSequence = _createIndexInsertSequence(pending.size());

	_printVector( indexSequence, "Index Seq", PURPLE );
	std::vector<int>::iterator isit = indexSequence.begin();
	if (VERBOSE)
	{
		std::cout << CYAN "Inserting...\t\t\t\t";
	}
	for (; isit != indexSequence.end(); isit++)
	{
		int numberToInsert = pending[*isit - 1];
		if (VERBOSE)
		{
			std::cout << "[" << numberToInsert << "]";
		}
		_insertAtBisectedIndex( *_sortedVector, numberToInsert );
	}
	if (VERBOSE)
	{
		std::cout << RESET << std::endl;
		_printVector( *_sortedVector, "Sorted", GREEN );
	}
}

std::vector<int> PmergeMe::_createIndexInsertSequence( int pendingSize )
{
	bool lastWasJacobNumber = false;
	std::vector<int> jacobSequence = _buildJacobstahlInsertionSequence(
	                                     pendingSize);
	_printVector( jacobSequence, "Jacobstahl", PURPLE );
	std::vector<int> indexSequence;

	indexSequence.push_back(1);
	int i = 1;
	while (i <= pendingSize)
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

void PmergeMe::_insertAtBisectedIndex( std::vector<int> & vector, int element )
{
	int index = _bisect( vector, element );
	vector.insert( vector.begin() + index, element );
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

int PmergeMe::_bisect( std::vector<int> vector, int x )
{
	int lo = 0;
	int hi = vector.size();

	while ( lo < hi )
	{
		int mid = ( lo + hi ) / 2;
		if ( x  < vector[mid] )
		{
			hi = mid;
		}
		else
		{
			lo = mid + 1;
		}
	}
	return ( lo );
}

void PmergeMe::_extractStraggler( std::vector<int> & unsortedVector )
{
	_straggler = unsortedVector.back();
	unsortedVector.pop_back();
	if (VERBOSE)
	{
		std::cout << CYAN "Straggler = " << _straggler << std::endl;
		_printVector( *_unsortedVector, "Unsorted", PURPLE );
	}
}

void PmergeMe::_insertStraggler( std::vector<int> & sortedVector )
{
	_insertAtBisectedIndex( sortedVector, _straggler );
	if (VERBOSE)
	{
		std::cout << CYAN "Inserting straggler...\t\t\t[" << _straggler << "]" RESET << std::endl;
		_printVector( sortedVector, "Sorted", GREEN );
	}
}

template <typename T>
void PmergeMe::_printVector( std::vector<T> & vector, std::string name,
                             std::string color )
{
	if (!VERBOSE)
	{
		return ;
	}
	std::cout << color << name
	          << " vector (size " << vector.size() << ") contains:\t"
	          << _getVectorContentsAsString( vector ) << RESET << std::endl;
}

std::string PmergeMe::_getVectorContentsAsString( std::vector<int> & vector )
{
	std::stringstream ss;
	if ( vector.empty() )
	{
		return ( "" );
	}
	std::vector<int>::iterator it = vector.begin();
	for ( ; it != vector.end(); it++ )
	{
		ss << "[" << *it << "]";
	}
	return ( ss.str() );
}

std::string PmergeMe::_getVectorContentsAsString(
    std::vector< std::pair<int, int> > & vector )
{
	std::stringstream ss;
	if ( vector.empty() )
	{
		return ( "" );
	}
	std::vector< std::pair<int, int> >::iterator it = vector.begin();
	for ( ; it != vector.end(); it++ )
	{
		std::cout << "[" << it->first << "--"  << it->second << "]";
	}
	return ( ss.str() );
}

/* ---------------------------------------------------------- LIST */

std::list<int> & PmergeMe::getSortedList( void )
{
	return (*_sortedList);
}

void PmergeMe::_fillListFromArray( int * array )
{
	for ( int i = 0; array[i]; i++ )
	{
		_unsortedList->push_back( array[i] );
	}
}

void PmergeMe::_sortList( void )
{
	_printList( *_unsortedList, "Unsorted", PURPLE );
	bool hasStraggler = _unsortedList->size() % 2 != 0;
	if ( hasStraggler )
	{
		_extractStraggler( *_unsortedList );
	}
	std::list< std::pair<int, int> > splitList = _splitIntoPairs( *_unsortedList );
	_sortEachPair( splitList );
	_sortPairsByLargestValue( splitList );
	/* _createSortedSequence( splitList ); */
	/* if ( hasStraggler ) */
	/* { */
	/* 	_insertStraggler( *_sortedList ); */
	/* } */
}

std::list< std::pair<int, int> > PmergeMe::_splitIntoPairs( std::list<int> & unsortedList )
{
	std::list< std::pair<int, int> > splitList;
	int first = 0;
	std::list<int>::iterator it = unsortedList.begin();
	for ( ; it != unsortedList.end(); it++ )
	{
		if ( first == 0 )
		{
			first = *it;
		}
		else
		{
			splitList.push_back( std::make_pair( first, *it ) );
			first = 0;
		}
	}
	_printList( splitList, "Split pair", YELLOW );
	return ( splitList );
}

void PmergeMe::_sortEachPair( std::list< std::pair<int, int> > & splitList )
{
	std::list< std::pair<int, int> >::iterator it = splitList.begin();
	for ( ; it != splitList.end(); it++ )
	{
		if( it->first > it->second )
		{
			int tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	_printList( splitList, "Split pair", YELLOW );
}

void PmergeMe::_sortPairsByLargestValue( std::list< std::pair<int, int> > &
        splitList )
{
	int length = splitList.size();
	_insertionSortPairs( splitList, length - 1 );
	_printList( splitList, "Split pair", YELLOW );
}

void PmergeMe::_insertionSortPairs( std::list< std::pair<int, int> > &
                                    splitList, int n )
{
	if ( n == 0 )
	{
		return ;
	}
	else
	{
		_insertionSortPairs( splitList, n - 1 );
		std::list< std::pair<int, int> >::iterator it = splitList.begin();
		std::advance( it, n );
		_insertElement( splitList, *it, n - 1 );
	}
}

void PmergeMe::_insertElement( std::list< std::pair<int, int> > & splitList,
                               std::pair<int, int> element, int n )
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
			_insertElement( splitList, element, n - 1 );
		}
	}
}

/* void PmergeMe::_createSortedSequence( std::list< std::pair<int, int> > & */
/*                                       splitList ) */
/* { */
/* 	std::list<int> pending; */

/* 	std::list< std::pair<int, int> >::iterator it = splitList.begin(); */
/* 	for ( ; it != splitList.end(); it++ ) */
/* 	{ */
/* 		_sortedList->push_back( it->second ); */
/* 		pending.push_back( it->first ); */
/* 	} */
/* 	_printList( *_sortedList, "Sorted", GREEN ); */
/* 	_printList( pending, "Pending", CYAN ); */
/* 	std::list<int> indexSequence = _createIndexInsertSequence(pending.size()); */

/* 	_printList( indexSequence, "Index Seq", PURPLE ); */
/* 	std::list<int>::iterator isit = indexSequence.begin(); */
/* 	if (VERBOSE) */
/* 	{ */
/* 		std::cout << CYAN "Inserting...\t\t\t\t"; */
/* 	} */
/* 	for (; isit != indexSequence.end(); isit++) */
/* 	{ */
/* 		int index = *isit; */
/* 		std::list<int>::iterator pit = pending.begin(); */
/* 		std::advance(pit, index - 1); */
/* 		int numberToInsert = *pit; */
/* 		if (VERBOSE) */
/* 		{ */
/* 			std::cout << "[" << numberToInsert << "]"; */
/* 		} */
/* 		_insertAtBisectedIndex( *_sortedList, numberToInsert ); */
/* 	} */
/* 	if (VERBOSE) */
/* 	{ */
/* 		std::cout << RESET << std::endl; */
/* 		_printVector( *_sortedVector, "Sorted", GREEN ); */
/* 	} */
/* } */

/* std::list<int> PmergeMe::_createIndexInsertSequence( int pendingSize ) */
/* { */
/* 	bool lastWasJacobNumber = false; */
/* 	std::list<int> jacobSequence = _buildJacobstahlInsertionSequence( */
/* 	                                     pendingSize); */
/* 	_printList( jacobSequence, "Jacobstahl", PURPLE ); */
/* 	std::list<int> indexSequence; */

/* 	indexSequence.push_back(1); */
/* 	int i = 1; */
/* 	while (i <= pendingSize) */
/* 	{ */
/* 		/1* if ( jacobSequence.size() != 0 && lastWasJacobNumber == false ) *1/ */
/* 		/1* { *1/ */
/* 		/1* 	indexSequence.push_back( jacobSequence[0] ); *1/ */
/* 		/1* 	jacobSequence.erase( jacobSequence.begin() ); *1/ */
/* 		/1* 	lastWasJacobNumber = true; *1/ */
/* 		/1* 	continue; *1/ */
/* 		/1* } *1/ */
/* 		/1* std::vector<int>::iterator iit = indexSequence.begin(); *1/ */
/* 		/1* for ( ; iit != indexSequence.end(); iit++ ) *1/ */
/* 		/1* { *1/ */
/* 		/1* 	if ( *iit == i ) *1/ */
/* 		/1* 	{ *1/ */
/* 		/1* 		i++; *1/ */
/* 		/1* 	} *1/ */
/* 		/1* } *1/ */
/* 		/1* indexSequence.push_back( i ); *1/ */
/* 		/1* lastWasJacobNumber = false; *1/ */
/* 		/1* i++; *1/ */
/* 	} */
/* 	return (indexSequence); */
/* } */

/* void PmergeMe::_insertAtBisectedIndex( std::list<int> & list, int element ) */
/* { */
/* 	/1* int index = _bisect( list, element ); *1/ */
/* 	/1* list.insert( list.begin() + index, element ); *1/ */
/* } */

/* std::list<int> PmergeMe::_buildJacobstahlInsertionSequence( int size ) */
/* { */
/* 	std::list<int> jacobSequence; */
/* 	int jacobIndex = 3; */
/* 	while ( _getJacobstahlNumber( jacobIndex ) < size - 1 ) */
/* 	{ */
/* 		jacobSequence.push_back( _getJacobstahlNumber( jacobIndex ) ); */
/* 		jacobIndex++; */
/* 	} */
/* 	return ( jacobSequence ); */
/* } */

/* int PmergeMe::_bisect( std::list<int> list, int x ) */
/* { */
/* 	int lo = 0; */
/* 	int hi = list.size(); */

/* 	while ( lo < hi ) */
/* 	{ */
/* 		int mid = ( lo + hi ) / 2; */
/* 		if ( x  < list[mid] ) */
/* 		{ */
/* 			hi = mid; */
/* 		} */
/* 		else */
/* 		{ */
/* 			lo = mid + 1; */
/* 		} */
/* 	} */
/* 	return ( lo ); */
/* } */

void PmergeMe::_extractStraggler( std::list<int> & unsortedList )
{
	_straggler = unsortedList.back();
	unsortedList.pop_back();
	if (VERBOSE)
	{
		std::cout << CYAN "Straggler = " << _straggler << std::endl;
		_printList( *_unsortedList, "Unsorted", PURPLE );
	}
}

/* void PmergeMe::_insertStraggler( std::list<int> & sortedList ) */
/* { */
/* 	_insertAtBisectedIndex( sortedList, _straggler ); */
/* 	if (VERBOSE) */
/* 	{ */
/* 		std::cout << CYAN "Inserting straggler...\t\t\t[" << _straggler << "]" RESET << std::endl; */
/* 		_printList( sortedList, "Sorted", GREEN ); */
/* 	} */
/* } */

template <typename T>
void PmergeMe::_printList( std::list<T> & list, std::string name,
                             std::string color )
{
	if (!VERBOSE)
	{
		return ;
	}
	std::cout << color << name
	          << " list (size " << list.size() << ") contains:\t"
	          << _getListContentsAsString( list ) << RESET << std::endl;
}

std::string PmergeMe::_getListContentsAsString( std::list<int> & list )
{
	std::stringstream ss;
	if ( list.empty() )
	{
		return ( "" );
	}
	std::list<int>::iterator it = list.begin();
	for ( ; it != list.end(); it++ )
	{
		ss << "[" << *it << "]";
	}
	return ( ss.str() );
}

std::string PmergeMe::_getListContentsAsString(
    std::list< std::pair<int, int> > & list )
{
	std::stringstream ss;
	if ( list.empty() )
	{
		return ( "" );
	}
	std::list< std::pair<int, int> >::iterator it = list.begin();
	for ( ; it != list.end(); it++ )
	{
		std::cout << "[" << it->first << "--"  << it->second << "]";
	}
	return ( ss.str() );
}
