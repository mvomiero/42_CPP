/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:31:15 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/14 15:59:16 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERTER_HPP
# define CONVERTER_HPP

#include <iostream>
#include <fstream>
#include <limits>

enum e_type {
	NONE,
	INT,
	FLOAT,
	CHAR,
	DOUBLE
};

class Converter {

private:
	char	_char;
	int		_int;
	float	_float;
	double	_double;

	bool	_impossible;

	std::string	_str;	// input string
	e_type		_type;	// input type - result of setType()

public:
	Converter( void );
	Converter( const Converter& src );
	~Converter( void );

	Converter& operator=( const Converter& rhs );

	void	convert( void ); // function to convert

	void	setStr( std::string str ); // input string

	void	setType( void ); // to determine the type

	/* CHECK */
	bool	isChar( void ) const;
	bool	isInt( void ) const;
	bool	isFloat( void ) const;
	bool	isDouble( void ) const;

	bool	isImpossible( void );

	/* PRINT */
	void	printChar( void ) const ;
	void	printInt( void ) const ;
	void	printFloat( void ) const ;
	void	printDouble( void ) const ;

	/* EXCEPTIONS */
	class ConverterException : public std::exception {
		virtual const char* what() const throw() { return "Unknown type"; }
	};
};

/* Operator overload */

std::ostream& operator<<( std::ostream& out, const Converter& rhs );

#endif