/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:31:05 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/12 16:36:22 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Converter.hpp"

Converter::Converter( void ) {
	this->_char = '\0';
	this->_int = 0;
	this->_float = 0.0f;
	this->_double = 0.0;
}

Converter::Converter( const Converter& src ) {
	*this = src;
}

Converter::~Converter( void ) {}

Converter& Converter::operator=( const Converter& rhs ) {
	if ( this != &rhs ) {
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_char = rhs._char;
	}
	return *this;
}

bool    Converter::isLiterals( void ) const {
	if ( ( _impossible ) || ( _str.compare( "nan" ) == 0 ) || ( _str.compare( "nanf" ) == 0 )
		|| ( _str.compare( "+inf" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) 
		|| ( _str.compare( "-inf" ) == 0 ) || ( _str.compare( "-inff" ) == 0 ) 
		|| ( _str.compare( "-inff" ) == 0 ) || ( _str.compare( "-inff" ) == 0 )  
		|| ( _str.compare( "+inff" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) ) {
			return true;
	} 
	return false;
}

void    Converter::printChar( void ) const {
	if ( this->isLiterals() || ( !std::isprint( _int ) && ( _int >= 127 ) ) ) {
		std::cout << "Impossible";
	} else if ( !std::isprint( this->_int ) ) {
		std::cout << "Non displayable";
	} else {
		std::cout << "'" << _char << "'";
	}
	std::cout << std::endl;
}

void    Converter::printInt( void ) const {
	//if ( this->isLiterals() || ( !std::isprint( _n ) && ( _n >= 127 ) ) ) {
	if ( this->isLiterals()  ) {
		std::cout << "Impossible";
	} else {
		std::cout << _int;
	}
	
	std::cout << std::endl;
}

void Converter::setStr( std::string str ) {
	this->_str = str;
	this->setType();
	if ( getType() == NONE ) {
		throw Converter::ConverterException();
	}
}

e_type  Converter::getType( void ) const {
	return this->_type;
}

bool    Converter::isChar( void ) const {
	//return _str.length() == 1 && std::isalpha( _str[0] ) && std::isprint( _str[0] );
	return _str.length() == 1 && std::isprint( _str[0] );
}

bool    Converter::isInt( void ) const {
	int    j = 0;
	if ( _str[j] == '-' || _str[j] == '+' )
		j++;
	for ( int i( j ); i < ( int ) _str.length(); i++ ) {
		if ( !std::isdigit( _str[i] ) )
			return false;
	}
	return true;
}

bool Converter::isDouble( void ) const {
	if ( _str == "nan" || _str == "+inf" || _str == "-inf" )
		return true;
	if ( _str.find( '.' ) == std::string::npos || _str.find( '.' ) == 0 
		|| _str.find( '.' ) == _str.length() - 1 )
		return false;
	int j = 0;
	int found = 0;
	if ( _str[j] == '-' || _str[j] == '+' )
		j++;
	for ( int i( j ); i < ( int ) _str.length(); i++ ) {
		if ( _str[i] == '.' )
			found++;
		if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
			return false;
	}

	return true;
}

bool    Converter::isFloat ( void ) const {
	if ( _str == "nanf" || _str == "+inff" || _str == "-inff" )
		return true;
	if ( _str.find( '.' ) == std::string::npos || _str.back() != 'f' 
		|| _str.find( '.' ) == 0 || _str.find( '.' ) == _str.length() - 2 )
		return false;
	int found = 0;
	int j = 0;
	if ( _str[j] == '-' || _str[j] == '+' )
		j++;
	for ( int i( j ); i < ( int ) _str.length() - 1; i++ ) {
		if ( _str[i] == '.' )
			found++;
		if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
			return false;
	}

	return true;
}

void    Converter::printFloat( void ) const {
	/* if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
		std::cout << "nanf";
	} else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
		std::cout << "+inff";
	} else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
		std::cout << "-inff";
	} else if ( _impossible ) {
		std::cout << "Impossible";
	} else */ {
		if ( _float - static_cast< int > ( _float ) == 0 ) {
			std::cout << _float << ".0f";
		} else {
			std::cout << _float << "f";
		}
	}
	std::cout << std::endl;
}

void    Converter::printDouble( void ) const {
	/* if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
		std::cout << "nan";
	} else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
		std::cout << "+inf";
	} else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
		std::cout << "-inf";
	} else if ( _impossible ) {
		std::cout << "Impossible";
	} else  */{
		if ( _double - static_cast< int > ( _double ) == 0 ) {
			std::cout << _double << ".0";
		} else {
			//std::cout << _double << "f";
			std::cout << _double ;
		}
	}
	std::cout << std::endl;
	std::cout << "type: " << _type << std::endl;

}

void    Converter::setType( void ) {
	 if ( isInt() ) {
		_type = INT;
	} else if ( isChar() ) {
		_type = CHAR;
	} else if ( isFloat() ) {
		_type = FLOAT;
	} else if ( isDouble() ) {
		_type = DOUBLE;
	} else if ( isLiterals() ) {
		_type = LITERALS;
	} else {
		_type = NONE;
	}
}

bool    Converter::isImpossible( void ) {
	try
	{
		if ( _type == INT ) {
			_int = std::stoi( _str );
		} else if ( _type == FLOAT ) {
			_float = std::stof( _str );
		} else if ( _type == DOUBLE ) {
			_double = std::stod( _str );
		}
	}
	catch ( std::exception& e )
	{
		_impossible = true;
		return true;
	}
	return false;
}

void    Converter::convert( void ) {
	if ( isImpossible() )
		return;
	switch ( _type ) {
	case CHAR:
		_char = _str[0];
		_int = static_cast< int >( _char );
		_float = static_cast< float >( _char );
		_double = static_cast< double >( _char );
		break;
	case INT:
		_int = std::stoi( _str );
		_float = static_cast< float >( _int );
		_double = static_cast< double >( _int );
		_char = static_cast< char >( _int );
		break;
	case FLOAT:
		_float = std::stof( _str );
		_int = static_cast< int >( _float );
		_double = static_cast< double >( _float );
		_char = static_cast< char >( _float );
		break;
	case DOUBLE:
		_double = std::stod( _str );
		_int = static_cast< int >( _double );
		_float = static_cast< float >( _double );
		_char = static_cast< char >( _double );
		break;
	default:
		break;
	}
}

std::ostream&    operator<<( std::ostream& out, const Converter& rhs ) {
	out << "char: "; rhs.printChar();
	out << "int: "; rhs.printInt();
	out << "float: "; rhs.printFloat();
	out << "double: "; rhs.printDouble();
	return out;
}
