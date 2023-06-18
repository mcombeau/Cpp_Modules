/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:16:16 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/18 15:16:16 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLEASE_MERGE_ME_HPP
#define PLEASE_MERGE_ME_HPP

#include "utils.hpp"

#define VECTOR 0
#define LIST 1

class PmergeMe
{
	private:
		/* SHARED */
		bool _container;
		int _straggler;

		PmergeMe( void );
		int _getJacobstahlNumber( int n );

		/* VECTOR */
		std::vector<int> * _unsortedVector;
		std::vector<int> * _sortedVector;

		void _fillVectorFromArray( int * array, int array_size );
		void _sortVector( void );
		bool _isVectorAlreadySorted( void );
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

		/* LIST */
		std::list<int> * _unsortedList;
		std::list<int> * _sortedList;

		void _fillListFromArray( int * array, int array_size );
		void _sortList( void );
		bool _isListAlreadySorted( void );
		std::list< std::pair<int, int> > _splitIntoPairs( std::list<int> & unsortedList );
		void _sortEachPair( std::list< std::pair<int, int> > & splitList );
		void _sortPairsByLargestValue( std::list< std::pair<int, int> > &
		                               splitList );
		void _insertionSortPairs( std::list< std::pair<int, int> > &
		                          splitList, int n );
		void _insertElement( std::list< std::pair<int, int> > & splitList,
		                     std::pair<int, int> element, int n );
		void _createSortedSequence( std::list< std::pair<int, int> > & splitList );
		std::list<int> _createIndexInsertSequence( std::list<int> pending );
		std::list<int> _buildJacobstahlInsertionSequence( std::list<int> pending );
		void _insertAtBisectedIndex( std::list<int> & list, int element );
		int _bisect( std::list<int> list, int x );
		void _extractStraggler( std::list<int> & unsortedList );
		void _insertStraggler( std::list<int> & sortedList );

		template <typename T>
		void _printList( std::list<T> & list, std::string name,
		                   std::string color );
		std::string _getListContentsAsString( std::list<int> & list );
		std::string _getListContentsAsString( std::list< std::pair<int, int> > &
		                                        list );

	public:
		PmergeMe( int* array, int array_size, bool container );
		PmergeMe( PmergeMe & src );
		~PmergeMe( void );

		PmergeMe & operator=( PmergeMe & src );
		void sort( void );
		std::vector<int> & getSortedVector( void );
		std::list<int> & getSortedList( void );
};

#endif
