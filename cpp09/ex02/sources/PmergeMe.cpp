#include "PmergeMe.hpp"
#include <ios>
#include <sstream>
#include <utility>
#include <vector>

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( int* array, bool container ) : _container( container )
{
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

PmergeMe::~PmergeMe( void ) {}

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

void PmergeMe::_sortVector( void )
{
	_printVector( _unsortedVector, "Unsorted", RED );
	bool hasStraggler = _unsortedVector.size() % 2 != 0;
	std::cout << CYAN "Vector has straggler = " << std::boolalpha <<
	          hasStraggler << RESET << std::endl;
	int straggler = 0;
	if ( hasStraggler )
	{
		straggler = _unsortedVector.back();
		_unsortedVector.pop_back();
		std::cout << CYAN "Straggler = " << straggler << std::endl;
		_printVector( _unsortedVector, "Unsorted", RED );
	}
	std::vector< std::pair<int, int> > splitVector = _splitUnsortedVector();
	_printVector( splitVector, "Split pair", YELLOW );
	_sortEachPair( splitVector );
	_printVector( splitVector, "Split pair", YELLOW );
	_sortPairsByLargestValue( splitVector );
	_printVector( splitVector, "Split pair", YELLOW );
	_createSortedSequence( splitVector );
	if ( hasStraggler )
	{
		std::cout << "Inserting straggler " << straggler << std::endl;
		_insertAtBisectedIndex( _sortedVector, straggler );
	}
	_printVector( _sortedVector, "Sorted", GREEN );
}

std::vector< std::pair<int, int> > PmergeMe::_splitUnsortedVector( void )
{
	std::vector< std::pair<int, int> > splitVector;
	int first = 0;
	std::vector<int>::iterator it = _unsortedVector.begin();
	for ( ; it != _unsortedVector.end(); it++ )
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
}

void PmergeMe::_sortPairsByLargestValue( std::vector< std::pair<int, int> > &
        splitVector )
{
	int length = splitVector.size();
	_insertionSortPairs( splitVector, length - 1 );
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
	_printVector( _sortedVector, "Sorted", GREEN );
	_printVector( pending, "Pending", CYAN );

	std::vector< std::pair<int, int> >::iterator it = splitVector.begin();
	for ( ; it != splitVector.end(); it++ )
	{
		_sortedVector.push_back( it->second );
		pending.push_back( it->first );
	}
	_sortedVector.insert( _sortedVector.begin(), pending[0] );
	pending.erase( pending.begin() );
	_printVector( _sortedVector, "Sorted", GREEN );
	_printVector( pending, "Pending", CYAN );

	bool lastWasJacobNumber = false;
	std::vector<int> jacobSequence = _buildJacobstahlInsertionSequence(
	                                     pending.size() );
	_printVector( jacobSequence, "Jacobstahl", PURPLE );
	std::vector<int> indexSequence;
	int numberToInsert = -1;

	int pendingSize = pending.size();

	for ( int i = 1; i <= pendingSize; i++ )
	{
		if ( jacobSequence.size() != 0 && lastWasJacobNumber == false )
		{
			indexSequence.push_back( jacobSequence[0] );
			numberToInsert = pending[jacobSequence[0] - 1];
			jacobSequence.erase( jacobSequence.begin() );
			lastWasJacobNumber = true;
		}
		else
		{
			std::vector<int>::iterator iit = indexSequence.begin();
			for ( ; iit != indexSequence.end(); iit++ )
			{
				if ( *iit == i )
				{
					i++;
				}
			}
			numberToInsert = pending[i - 1];
			indexSequence.push_back( i );
			lastWasJacobNumber = false;
		}
		_insertAtBisectedIndex( _sortedVector, numberToInsert );
		_printVector( _sortedVector, "Sorted", GREEN );
	}
}

void PmergeMe::_insertAtBisectedIndex( std::vector<int> & vector, int element )
{
	int index = _bisectVector( vector, element );
	vector.insert( vector.begin() + index, element );
}

std::vector<int> PmergeMe::_buildJacobstahlInsertionSequence( int size )
{
	std::cout << "Jacobstahl pending array is size " << size << std::endl;
	std::vector<int> jacobSequence;
	int jacobIndex = 3;
	while ( _getJacobstahlNumber( jacobIndex ) < size - 1 )
	{
		jacobSequence.push_back( _getJacobstahlNumber( jacobIndex ) );
		jacobIndex++;
	}
	return ( jacobSequence );
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

int PmergeMe::_bisectVector( std::vector<int> vector, int x )
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

void PmergeMe::_sortList( void )
{
}

void PmergeMe::_fillVectorFromArray( int * array )
{
	for ( int i = 0; array[i]; i++ )
	{
		_unsortedVector.push_back( array[i] );
	}
}

void PmergeMe::_fillListFromArray( int * array )
{
	/* TODO: implement */
	( void )array;
}

template <typename T>
void PmergeMe::_printVector( std::vector<T> & vector, std::string name,
                             std::string color )
{
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
