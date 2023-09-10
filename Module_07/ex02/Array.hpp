/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:16:10 by mvomiero          #+#    #+#             */
/*   Updated: 2023/09/10 16:09:51 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template < typename T >
class Array {

private:
	T*	_array;
	unsigned int	_size;

public:
	// constructor no arguments
	Array( void ) : _array( new T() ), _size( 0 ) {};

	// constructor int as input
	Array( unsigned int n ) : _array( new T[n] ), _size( n ) {};
	
	// Copy constructor
	Array( const Array& other ) : _array( new T[other.size()]), _size( other.size() ) {
		for ( unsigned int i = 0; i < _size; i++ )
			_array[i] = other._array[i];
	}
	
	// Assignment operator
	Array& operator=( const Array& other ) {
		if (this != &other) {
			delete[] _array;
			_size = other.size();
			_array = new T[_size];
			for ( unsigned int i = 0; i < _size; i++ )
				_array[i] = other._array[i];
		}
		return ( *this );
	}

	// Subscript operator
	T& operator[]( unsigned int index ) const {
		if ( index >= _size )
			throw OutOfBoundsException();
		return ( _array[index] );
	}

	// getter size
	unsigned int  size( void ) const { return _size; }

	// Destructor
	~Array( void ) { delete[] _array; }

	// Exception
	class OutOfBoundsException : public std::exception {
		public:
			virtual const char* what() const throw() { return "Index is out of bounds!";}
	};
};

// operator overlod << for Array objects
template <typename T>
std::ostream&	operator<<(std::ostream& os, Array<T>& obj) {
	for (unsigned int i = 0; i < obj.size(); ++i) {
		os << "[" << obj[i] << "] ";
	}
	return (os);
}