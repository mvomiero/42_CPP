#include <iostream>
//#include <cstdint>
#include "colors.h"


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


/* Static functions:
	using the static keyword before a member function in a C++ class changes its
	behavior to be associated with the class itself rather than with instances.
	(like you don't have to instanciate an object to use them, you don't have the 
	this pointer, ecc.) So they have a more general purpose.
*/
class Serializer {
public:

	static uintptr_t serialize(Data* ptr) {
		return reinterpret_cast<uintptr_t>(ptr);
	}

	static Data* deserialize(uintptr_t raw) {
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
	uintptr_t serializedPtr = Serializer::serialize(&dataObj);

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
