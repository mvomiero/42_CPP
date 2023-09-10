# CPP Modules

## Module 00
Namespaces, classes, member functions, stdio streams,
initialization lists, static, const

* ex00 > **Megaphone** - *standard output*
* ex01 > **My Awesome PhoneBook** - *classes, member functions, stdio streams*
* ex02 > **The Job Of Your Dreams** - *initialization lists, static, const*

## Module 01
Memory allocation, pointers to members,
references, switch statement

* ex00 > **BraiiiiiiinnnzzzZ** - *object allocations and pointers*
* ex01 > **Moar brainz!** - *allocation of an array of objects, corresponding free*
* ex02 > **HI THIS BRAIN** - *pointer vs reference*
* ex03 > **Unnecessary violence** - *difference between a pointer and a reference (ref can be assigned only to a defined element with a defined address)*
* ex04 > **Sed is for losers** - *filestream i/o, string manipulation (emulates sed replacing one word with another)*
* ex05 > **Harl 2.0** - *pointers to member functions (creating an array of pointers to function)*
* ex06 > **Harl filter** - *switch statement*

## Module 02
Ad-hoc polymorphism *(function overloading)*, operator overloading
and Orthodox Canonical class form *(default methods, see ex00)*, fixed-point numbers

* ex00 > **My First Class in Orthodox Canonical Form** - *Fixed-point numbers (representation of real numbers in computing that have a fixed number of digits for the fractional part)*
* ex01 > **Towards a more useful fixed-point number class** - *function overload, operator overload, conversion functions*
* ex02 > **Now we’re talking** - *several types of operator overload*
* ex03 > **BSP** - *use of the class created before for a pratctical application (calculating if a point is inside a triangle)*

## Module 03
Inheritance

* ex00 > **Aaaaand... OPEN! (ClapTrap)** - 
*implementing a class (ClapTrap) with variables and member functions*
* ex01 > **Serena, my love! (ScavTrap)** - *inheritance (creation of a subclass), member functions overload*
* ex02 > **Repetitive work (FragTrap)** - *same as the previous exercise, just different values*
* ex03 > **Now it’s weird! (DiamondTrap)** - *diamond inheritance: inheritance from classes that have a common base class*

## Module 04
Subtype polymorphism, abstract classes, interfaces

* ex00 > **Polymorphism** - *Run-time Polymorphism (Dynamic Polymorphism, the choice of which overloaded function to choose im made at run time depending from the object calling it and not at compile time depending on the input parameters). Declaring a function virtual and implementing its polymorphism in the subclasses*
* ex01 > **I don’t want to set the world on fire** - *memory leaks, allocation and free*
* ex02 > **Abstract class** - *same as ex01, but the base class is abstract (one function is set = 0). Abstrac means objects of the base class can't be instantiated*
* ex03 > **Interface & recap** - *general recap with different classes, subclasses and interfaces*

## Module 05
Repetition and Exceptions

* ex00 > **Mommy, when I grow up, I want to be a bureaucrat!** - *Exceptions: using try and catch, declaring subclasses of std::exception, etc.*
* ex01 > **Form up, maggots!** - *like the exercise before, just more complex*
* ex02 > **No, you need form 28B, not 28C...** - *like the exercise before, just more complex, different exceptions thrown depending the properties of the objects*

## Module 06
C++ casts

* ex00 > **Conversion of scalar types** - *A converter from a string input to char, int, float, double using static casting. (too much parsing and sting manipulation in my opinion)*
* ex01 > **Serialization** - *Creating the Serializer static class with the methods serialize() and deserialize() to reinterpret a pointer value to int and vice versa using reinterpret_cast.*
* ex02 > **Identify real type** - *two functions to generate and identify an object: generate() --> just returns a pointer to a new element of the derived class; identify() -> static polymorphism depending the input, which is either a pointer of a reference. With this two functions we see how dynamic_casting can be useful to identify the class of a given element.*

## Module 07
C++ templates

* ex00 > **Start with a few functions** - *function templates to implement min, max and swap functions*
* ex01 > **Iter** - *using function templates to apply the same function to all the elements of an array*
* ex02 > **Array** - *devoloping a template for a Class that stores a dynamically allocated array of elements of type T. The constructor accepts as parameter the size of the array.The [] operator is overloadedto throw an exception, if the index is out of the bounds.*