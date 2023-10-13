/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvomiero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:17:31 by mvomiero          #+#    #+#             */
/*   Updated: 2023/10/13 11:36:22 by mvomiero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "colors.h"
#include <vector>


template <typename Iterator>
void printContainer(Iterator begin, Iterator end) {
	std::cout << "\tContainer: ";
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
	std::cout << std::endl;
}

int main()
{
	std::cout << BG_BRIGHT_PURPLE << "------------------- TEST ASSIGNMENT -------------------" << RESET << std::endl;
	std::cout << PURPLE << "\nMutantStack\n" << RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
		//return 0;
	}
	std::cout << BG_BRIGHT_PURPLE << "------------------- TEST ASSIGNMENT -------------------" << RESET << std::endl;
	std::cout << PURPLE << "\nstd::list\n" << RESET << std::endl;
	{
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		//std::stack<int> s(mstack); // not compatible
		//return 0;
	}
	{
		std::cout << BG_BRIGHT_BLUE << "\n\tCUSTOM TESTS" << RESET << std::endl;
		std::cout << BG_BRIGHT_PURPLE << "------------------- TEST 1 -------------------" << RESET << std::endl;

		MutantStack<int> mstack;

		std::cout << PURPLE << "\nCreating a stack with three elements\n" << RESET << std::endl;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		std::cout << ITAL << "\tstack top is: " << mstack.top() << " and stack size is: " << mstack.size() << RESET << std::endl;
		MutantStack<int>::iterator it = mstack.begin(), ite = mstack.end();
		printContainer(it, ite);

		std::cout << PURPLE << "\nPopping one element" << RESET << std::endl;
		std::cout << PURPLE << "\tLIFO strategy: Last In is the First out (a property of stacks)\n" << RESET << std::endl;
		mstack.pop();
		std::cout << ITAL << "\tstack top is: " << mstack.top() << " and stack size is: " << mstack.size() << RESET << std::endl;
		it = mstack.begin(), ite = mstack.end();
		printContainer(it, ite);

		std::cout << BG_BRIGHT_PURPLE << "\n------------------- TEST 2 -------------------" << RESET << std::endl;
		std::cout << PURPLE << "\nInstantiating a std::stack with the copy constructor of Mutantstack\n" << RESET << std::endl;
		std::stack<int> s(mstack);
		s.push(42);
		s.push(21);
		s.pop();
		std::cout << ITAL << "\tstack top is: " << s.top() << " and stack size is: " << s.size() << RESET << std::endl;
		std::cout << PURPLE << "\tcan't print the content since a stack type has no iterators" << RESET << std::endl;

		std::cout << BG_BRIGHT_PURPLE << "\n------------------- TEST 3 -------------------" << RESET << std::endl;
		std::cout << PURPLE << "\nInstantiating a Mutantstack with the copy constructor\n" << RESET << std::endl;
		MutantStack<int> c = mstack;

		std::cout << ITAL << "\tstack top is: " << c.top() << " and stack size is: " << c.size() << RESET << std::endl;
		MutantStack<int>::iterator c_it = c.begin(), c_ite = c.end();
		printContainer(c_it, c_ite);

		
		
		//return 0;
	}
	{
		std::cout << BG_BRIGHT_PURPLE << "------------------- TEST 4 -------------------" << RESET << std::endl;
		std::cout << PURPLE << "\nInstantiating a Mutantstack from a std::stack casted from a vector container (instead of the default deque)\n" << RESET << std::endl;
		MutantStack<int, std::vector<int> > mstack;

		std::cout << PURPLE << "\nCreating a vector derived stack with three elements\n" << RESET << std::endl;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		std::cout << ITAL << "\tstack top is: " << mstack.top() << " and stack size is: " << mstack.size() << RESET << std::endl;
		MutantStack<int, std::vector<int> >::iterator it = mstack.begin(), ite = mstack.end();
		printContainer(it, ite);
	}
	return 0;
}