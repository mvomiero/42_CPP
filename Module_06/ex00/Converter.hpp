/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:31:15 by mvomiero          #+#    #+#             */
/*   Updated: 2023/08/12 16:31:16 by mvomiero         ###   ########.fr       */
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
    DOUBLE,
    LITERALS
};

class Converter {

private:
    char    _char;
    int     _int;
    float   _float;
    double  _double;

    bool    _impossible;

    std::string _str;
    e_type      _type;

public:
    Converter( void );
    Converter( const Converter& src );
    ~Converter( void );

    Converter& operator=( const Converter& rhs );

    char    getC( void ) const;
    void    setC( char c );

    int     getI( void ) const;
    void    setI( int n );

    float   getF( void ) const;
    void    setF( float f );

    double  getD( void ) const;
    void    setD( double d );

    void    convert( void );

    void    setStr( std::string str );
    std::string    getStr( void ) const;

    e_type  getType( void ) const;
    void    setType( void );

    bool    isChar( void ) const;
    bool    isInt( void ) const;
    bool    isFloat( void ) const;
    bool    isDouble( void ) const;

    bool    isImpossible( void );

    void    printChar( void ) const ;
    void    printInt( void ) const ;
    void    printFloat( void ) const ;
    void    printDouble( void ) const ;

    bool    isLiterals( void ) const;

    class ConverterException : public std::exception {
        virtual const char* what() const throw() { return "Unknown type"; }
    };
};

std::ostream& operator<<( std::ostream& out, const Converter& rhs );

#endif // CONVERTER_HPP