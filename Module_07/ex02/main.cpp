/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:05:10 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/10 19:21:21 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "Array.hpp"
#include "colors.h"
#define SIZE 10*/

/* ABSTRACT:
	devoloping a template for a Class that stores an array of elements of type T.
	The array is dynamically allocated. The class has a constructor that accepts the size of the array
	(that is stored as private variable) and a size() method that returns the size of the array.
	the [] operator is overwritten in order to throw an exception if the index to access is out of
	bounds.
 */

/*int	main( void ) {
	// these two lines are from the assignment: the result is 0. That means that
	// to have an empty array in the default constructor you can just initiate T()
	std::cout << "-------------------------------------------------------------" << std::endl;
	std::cout << PURPLE "test instantiation empty array " << RESET ;
	int * a = new int();
	delete a;
	std::cout << " a = " << *a << std::endl;

	std::cout << "-------------------------------------------------------------" << std::endl;

	// float
	Array< float > floatArray(SIZE);
	for ( unsigned int i = 0; i < floatArray.size(); i++ )
		floatArray[i] = i * 2.3;
	std::cout << YELLOW "Float Array: " RESET << floatArray << std::endl;

	std::cout << "-------------------------------------------------------------" << std::endl;

	// int
	Array< int > intArray( SIZE );
	Array< int > intArrayCopy; // default constructor with no parameters

	for ( unsigned int i = 0; i < intArray.size(); i++ )
		intArray[i] = i * 2;

	std::cout << CYAN "Int Array:	" RESET << intArray << std::endl;

	// copy assignment
	intArrayCopy = intArray;

	std::cout << CYAN "int Array copy:	" RESET << intArrayCopy << std::endl;

	std::cout << "-------------------------------------------------------------" << std::endl;

	// accessing the elements, exception for index out of bounds
	try {
		std::cout << GREEN "Accessing a valid index (5): " << intArray[5] << RESET << std::endl;
		std::cout << RED "Accessing an invalid index: " << intArray[SIZE] << std::endl;
	} catch ( Array< int >::OutOfBoundsException& e ) {
		std::cout << "Error: " << e.what() << RESET << std::endl;
	}

	std::cout << "-------------------------------------------------------------" << std::endl;

	return ( 0 );
}*/

#include <iostream>
#include <cstdlib>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE --> to test with valgrind, copy constructor and assignment operator works fine and everything is freed 
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
		else if (i == MAX_VAL - 1 && mirror[i] == numbers[i])
			std::cout << "All values are the same!" << std::endl;
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}