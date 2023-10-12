/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:59:35 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/12 15:24:27 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>
# include <iostream>
# include <vector>
# include <stdexcept>
# include <climits>
# include <algorithm>

class Span
{
private:
	std::vector<int> _vect;
	unsigned int _maxSize;
	
public:
	Span(void);
	Span(unsigned int N);
	Span(const Span &src);

	~Span(void);
	
	Span& operator=(const Span &rhs);
	
	void addNumber(int number);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;
};