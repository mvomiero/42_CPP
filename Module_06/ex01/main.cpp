/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:56:36 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/06 18:41:46 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "colors.h"

/* ABSTRACT:
	Creating the Serializer static class with the methods serialize() and deserialize()
	to reinterpret a pointer value to int and vice versa using reinterpret_cast.
	-- serialize() -> from pointer to int
	-- deserialize() -> from int to pointer
 */

/* REINTERPRET CAST:
	most powerful but most dangerous as well cast type in c++, it does a bitwise
	reinterpretation of the data. To use wit caution!
	some cases are for example to convert two pointers that are not realted or, like
	in this case, to convert a pointer to its numeric value or vice versa.
		E.g. int intValue = reinterpret_cast<int>(somePointer);
 */

/* uniptr_t:
	a datatype (unsigned int) that can store any valid pointer value (something like size_t)
 */

/* Data:
	Just the non-empty data structure where the functions of Serializer are applied
 */
class Data {
public:
	~Data( void ) {};
	Data(int value) : value(value) {}

	int getValue() const {
		return value;
	}

private:
	int value;
	Data( void );
	Data( const Data& src );

	Data& operator=( const Data& rhs );
};

/* Serializer:
	the two static functions required from the assignment
 */
class Serializer {
public:

	static __intptr_t serialize(Data* ptr) {
		return reinterpret_cast<__intptr_t>(ptr);
	}

	static Data* deserialize(__intptr_t raw) {
		return reinterpret_cast<Data*>(raw);
	}
private:
	~Serializer( void );
	Serializer( void );
	Serializer( const Serializer& src );

	Serializer& operator=( const Serializer& rhs );
};



int main() {
	// Create a Data object
	Data dataObj(42);

	// Serialize the pointer to the Data object
	__intptr_t serializedPtr = Serializer::serialize(&dataObj);

	// Deserialize the serialized pointer
	Data* deserializedPtr = Serializer::deserialize(serializedPtr);

	// Check if the deserialized pointer is equal to the original pointer
	if (deserializedPtr == &dataObj) {
		std::cout << BLUE BOLD "Deserialization successful. Original and deserialized pointers are equal." RESET << std::endl;
		std::cout << "Original Data value: " << dataObj.getValue() << std::endl;
	} else {
		std::cout << "Deserialization failed. Pointers are not equal." << std::endl;
	}

	return 0;
}
