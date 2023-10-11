/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:06:37 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/11 15:56:39 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "colors.h"
#define SIZE 4

/* ABSTRACT:
	using function templates to apply the same function to all the elements of an
	array. 
	The tests in the main show that the template is very versatile, you can use it 
	for example for int, char, double, std::string.
	The functions to apply, developed by me are a print and an increment one. 
	The increment is not suitable for all the datatypes (doesen't work with strings,
	you get a compilation error).
 */

/*// a print function to do some testing
template < typename T >
void	print( T& i ) {
	std::cout << i << std::endl;
}

// an increment function to do some testing
template < typename T >
void	increment( T& i ) {
	i++;
}

int	main( void ) {

	int numbers[] = { 1, 2, 3, 4 };
	std::cout << BLUE "numbers:" RESET << std::endl;
	iter(numbers, SIZE, print< int >);
	std::cout << BLUE "numbers increment:" RESET << std::endl;
	iter(numbers, SIZE, increment< int >);
	iter(numbers, SIZE, print< int >);

	double fractionals[] = { 1.2, 2.3, 3.4, 4.5 };
	std::cout << BLUE "fractionals:" RESET << std::endl;
	iter(fractionals, SIZE, print< double >);
	std::cout << BLUE "fractionals increment:" RESET << std::endl;
	iter(fractionals, SIZE, increment< double >);
	iter(fractionals, SIZE, print< double >);

	char characters[] = { 'a', 'b', 'c', 'd' };
	std::cout << BLUE "characters:" RESET << std::endl;
	iter(characters, SIZE, print< char >);
	std::cout << BLUE "characters increment:" RESET << std::endl;
	iter(characters, SIZE, increment< char >);
	iter(characters, SIZE, print< char >);

	std::string strings[] = { "ciao", "come", "va", "marco" };
	std::cout << BLUE "strings:" RESET << std::endl;
	iter(strings, SIZE, print< std::string >);
	// the increment doesen't work for the strings, you get a compilation error!
	// std::cout << BLUE "strings increment:" RESET << std::endl;
	// iter(strings, SIZE, &increment);
	
}*/

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<const int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}