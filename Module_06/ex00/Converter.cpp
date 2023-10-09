/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:31:05 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/09 15:04:18 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <cmath>

/* ORTHODOX CANONICAL FORM */

Converter::Converter(void)
{
	_char = '\0';
	_int = 0;
	_float = 0.0f;
	_double = 0.0;
}

Converter::Converter(const Converter &src)
{
	*this = src;
}

Converter::~Converter(void) {}

Converter &Converter::operator=(const Converter &rhs)
{
	if (this != &rhs)
	{
		_int = rhs._int;
		_float = rhs._float;
		_char = rhs._char;
		_double = rhs._double;
	}
	return *this;
}

/* SET STRING INPUT */

void Converter::setStr(std::string str)
{
	_str = str;
	this->setType();
	if (_type == NONE)
	{
		throw Converter::ConverterException();
	}
}

/* CHECK */

bool Converter::isChar(void) const
{
	return _str.length() == 1 && std::isprint(_str[0]);
}

bool Converter::isInt(void) const
{
	int j = 0;
	if (_str[j] == '-' || _str[j] == '+')
		j++;
	for (int i(j); i < (int)_str.length(); i++)
	{
		if (!std::isdigit(_str[i]))
			return false;
	}
	return true;
}

bool Converter::isDouble(void) const
{
	if (_str == "nan" || _str == "+inf" || _str == "-inf")
		return true;
	if (_str.find('.') == std::string::npos || _str.find('.') == 0 || _str.find('.') == _str.length() - 1)
		return false;
	int j = 0;
	int found = 0;
	if (_str[j] == '-' || _str[j] == '+')
		j++;
	for (int i(j); i < (int)_str.length(); i++)
	{
		if (_str[i] == '.')
			found++;
		if ((!std::isdigit(_str[i]) && _str[i] != '.') || found > 1)
			return false;
	}

	return true;
}

bool Converter::isFloat(void) const
{
	if (_str == "nanf" || _str == "+inff" || _str == "-inff")
		return true;
	if (_str.find('.') == std::string::npos || _str[_str.size() - 1] != 'f' || _str.find('.') == 0 || _str.find('.') == _str.length() - 2)
		return false;
	int found = 0;
	int j = 0;
	if (_str[j] == '-' || _str[j] == '+')
		j++;
	for (int i(j); i < (int)_str.length() - 1; i++)
	{
		if (_str[i] == '.')
			found++;
		if ((!std::isdigit(_str[i]) && _str[i] != '.') || found > 1)
			return false;
	}

	return true;
}

static bool isSpecialValue(const std::string &_str)
{
	if (_str == "nan" || _str == "+inf" || _str == "-inf")
		return true;
	if (_str == "nanf" || _str == "+inff" || _str == "-inff")
		return true;
	return false;
}

/* PRINT */

void Converter::printChar(void) const
{
	if (isSpecialValue(_str) || (!std::isprint(_int) && (_int >= 127 || _int < 0)) || _impossible)
	{
		std::cout << "Impossible";
	}
	else if (!std::isprint(_int))
	{
		std::cout << "Non displayable";
	}
	else
	{
		std::cout << "'" << _char << "'";
	}
	std::cout << std::endl;
}

void Converter::printInt(void) const
{
	if (_impossible || isSpecialValue(_str))
	{
		std::cout << "Impossible";
	}
	else
	{
		std::cout << _int;
	}
	std::cout << std::endl;
}

void Converter::printFloat(void) const
{
	if (_impossible)
	{
		std::cout << "Impossible";
	}
	else
	{
		if (_float - static_cast<int>(_float) == 0)
		{
			std::cout << _float << ".0f";
		}
		else
		{
			std::cout << _float << "f";
		}
	}
	std::cout << std::endl;
}

void Converter::printDouble(void) const
{
	if (_impossible)
	{
		std::cout << "Impossible";
	}
	else
	{
		if (_double - static_cast<int>(_double) == 0)
		{
			std::cout << _double << ".0";
		}
		else
		{
			std::cout << _double;
		}
	}
	std::cout << std::endl;
}

/* CONVERSION */

/* 1: checking the type of the input string
 */
void Converter::setType(void)
{
	if (isInt())
	{
		_type = INT;
	}
	else if (isChar())
	{
		_type = CHAR;
	}
	else if (isFloat())
	{
		_type = FLOAT;
	}
	else if (isDouble())
	{
		_type = DOUBLE;
	}
	else
	{
		_type = NONE;
	}
}

/* 2: checking if the conversion to the designated datatype is possible or if it fails.
	For example in case of overflow, a std::out_of_range& exception is thrown.
	without the try and catch blocks the program would crash but in this way it can just
	go on to the execution.
 */
bool Converter::isImpossible()
{
	if (_type == INT) {
		char *endptr;
		errno = 0; // Reset errno before the call
		long long_value = strtol(_str.c_str(), &endptr, 10);

		// Check for overflow and conversion errors
		if ((errno == ERANGE && (long_value == LONG_MAX || long_value == LONG_MIN)) || (errno != 0 && long_value == 0))
		{
			// Overflow or conversion error occurred
			_impossible = true;
			return true;
		}
		else if (endptr == _str.c_str())
		{
			// No digits were found in the input string
			_impossible = true;
			return true;
		}
		else
		{
			// Conversion succeeded
			if (long_value > INT_MAX || long_value < INT_MIN)
			{
				// Overflow for int
				_impossible = true;
				return true;
			}
			_int = static_cast<int>(long_value);
			_impossible = false;
			return false;
		}
	}
	else if (_type == FLOAT)
	{
		try
		{
			_float = static_cast<float>(atof(_str.c_str()));
		}
		catch (const std::exception &)
		{
			_impossible = true;
			return true;
		}
	}
	else if (_type == DOUBLE)
	{
		try
		{
			_double = atof(_str.c_str());
		}
		catch (const std::exception &)
		{
			_impossible = true;
			return true;
		}
	}

	_impossible = false;
	return false;
}

/* 3: conversion, using static_cast, depending the datatype.
 */
void Converter::convert(void)
{
	if (isImpossible())
		return;
	switch (_type)
	{
	case CHAR:
		_char = _str[0];
		_int = static_cast<int>(_char);
		_float = static_cast<float>(_char);
		_double = static_cast<double>(_char);
		break;
	case INT:
		_float = static_cast<float>(_int);
		_double = static_cast<double>(_int);
		if (_int >= CHAR_MIN && _int <= CHAR_MAX)
			_char = static_cast<char>(_int);
		else
			_char = static_cast<char>(0);
		std::cout << _char << std::endl;
		break;
	case FLOAT:
		_float = static_cast<float>(atof(_str.c_str()));
		_int = static_cast<int>(_float);
		_double = static_cast<double>(_float);
		_char = static_cast<char>(_float);
		break;
	case DOUBLE:
		_double = atof(_str.c_str());
		_int = static_cast<int>(_double);
		_float = static_cast<float>(_double);
		_char = static_cast<char>(_double);
		break;
	default:
		break;
	}
}

/* OPERATOR OVERLOAD */

std::ostream &operator<<(std::ostream &out, const Converter &rhs)
{
	out << "char: ";
	rhs.printChar();
	out << "int: ";
	rhs.printInt();
	out << "float: ";
	rhs.printFloat();
	out << "double: ";
	rhs.printDouble();
	return out;
}
