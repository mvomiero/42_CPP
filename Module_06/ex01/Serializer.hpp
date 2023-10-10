#pragma once

# include <iostream>
# include <stdint.h>

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

class Serializer
{
private:
    Serializer(void);
    ~Serializer(void);
    Serializer(const Serializer& copy);
    Serializer& operator=(const Serializer& copy);

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};