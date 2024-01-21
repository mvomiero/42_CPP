/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:59:57 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/13 12:02:35 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// default constructor
Span::Span(void) : _maxSize(0) {}

// parameter constructor
Span::Span(unsigned int n) : _maxSize(n) {}

// copy constructor
Span::Span(const Span &src) { *this = src; }

// destructor
Span::~Span(void) {}

// assignation operator
Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_vect = rhs._vect;
	}
	return *this;
}

// add a number to the vector
void Span::addNumber(int number)
{
	if (this->_vect.size() < this->_maxSize)
		this->_vect.push_back(number);
	else
		throw std::out_of_range("Vector is full");
}

// add a range of numbers to the vector
void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_vect.size() + std::distance(begin, end) <= this->_maxSize)
		this->_vect.insert(this->_vect.end(), begin, end);
	else
		throw std::out_of_range("Vector is full");
}

// find the longest span using the algorithm library
unsigned int Span::longestSpan(void) const
{
	if (_vect.size() < 2)
		throw std::out_of_range("Not enough elements in the vector");
	return (*std::max_element(_vect.begin(), _vect.end()) - *std::min_element(_vect.begin(), _vect.end()));
}

// find the shortest span using the algorithm library
unsigned int Span::shortestSpan(void) const
{
	if (_vect.size() < 2)
		throw std::out_of_range("Not enough elements in the vector");
	std::vector<int> tmp = _vect;
	std::sort(tmp.begin(), tmp.end());
	unsigned int shortest = UINT_MAX;
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end() - 1; it++)
	{
		unsigned int diff = static_cast<unsigned int>(*(it + 1) - *it);
		if (diff < shortest)
			shortest = *(it + 1) - *it;
	}
	return shortest;
}