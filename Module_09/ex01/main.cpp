#include "RPN.hpp"

/* ABSTRACT:
	using reverse polish notation, calculate the result of a mathematical expression.
	RPN is tipically used for stack-based programming languages.
	So of course, we will use a stack to store the numbers.
 */

/* RPN (reverse polish notation):
	1. read the expression from left to right
	2. if the current character is a number, push it to the stack
	3. if the current character is an operator, pop two numbers from the stack, perform the operation and push the result back to the stack
	4. repeat until the end of the expression
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./RPN [expression]" << std::endl;
		return 1;
	}

	std::string input = argv[1];
	RPN calculator;
	calculator.calculate(input);

	return 0;
}