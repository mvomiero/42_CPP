/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 12:19:03 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/11 15:57:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

/* ABSTRACT:
	using function templates to implement min, max and swap functions
 */

/* TEMPLATES:
	templates are used in c++ to create data structures and algorithms that can
	be used with various data types.
	the syntax starts with the line "template <typename T>", where T is convention
	but could be anything, and is the datatype that is going to be used along all the 
	function.
 */

/*int main( void )
{
	int a = 2;
	int b = 3;

	swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min( a, b ) = " << min( a, b ) << std::endl;	// Implicit instantiation
	std::cout << "max( a, b ) = " << max<int&>( a, b ) << std::endl; // Explicit instantiation

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "before swap: " "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "after swap: " "c = " << c << ", d = " << d << std::endl;

	std::cout << "min( c, d ) = " << min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << max( c, d ) << std::endl;

	return 0;
}*/

class Awesome
{
  public:
    Awesome(void) : _n(0) {}
    Awesome( int n ) : _n( n ) {}
    Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
    bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
    bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
    bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
    bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
    bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
    bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
    int get_n() const { return _n; }
  private:
    int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
	Awesome a(2), b(4);

        swap(a, b);
        std::cout << a << " " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << min(a, b) << std::endl;
        return (0);
}