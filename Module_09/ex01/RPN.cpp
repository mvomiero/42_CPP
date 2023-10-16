#include "RPN.hpp"

RPN::RPN()
{
}

RPN::~RPN()
{
}

RPN::RPN(std::stack<double> number)
{
	this->numbers = number;
}

RPN::RPN(const RPN &var)
{
	*this = var;
}

RPN &RPN::operator=(const RPN &rhs)
{
	this->numbers = rhs.numbers;
	return (*this);
}

void RPN::calculate(const std::string &input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		char c = input[i];

		if (c == ' ')
		{
			continue; // Skip whitespace
		}
		else if (isdigit(c))
		{
			int number = c - '0';
			numbers.push(number);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			// Handle operators
			performOperation(c);
		}
		else
		{
			// Invalid character
			std::cout << "Invalid input." << std::endl;
			return;
		}
		printStack(c);
		// function to print the content of the stack
	}

	if (numbers.size() == 1)
	{
		double result = numbers.top();
		numbers.pop();
		std::cout << "Result: " << result << std::endl;
	}
	else
	{
		// Insufficient operands
		std::cout << "Invalid input." << std::endl;
	}
}

void RPN::printStack(char c)
{
	if (isdigit(c))
		std::cout << BLUE "operand: " << c << " pushed to stack --> " << std::endl;
	else if (c == '+' || c == '-' || c == '*' || c == '/')
		std::cout << GREEN "operator: " << c << " executes the operation --> " << std::endl;
	else
		std::cout << RED "Invalid input." << std::endl;
	std::cout << "\tstack: [";
	for (std::stack<double> dump = numbers; !dump.empty(); dump.pop())
	{
		std::cout << dump.top() << ", ";
	}
	std::cout << "]" << std::endl;
}

void RPN::performOperation(char op)
{
	if (numbers.size() >= 2)
	{
		double b = numbers.top();
		numbers.pop();
		double a = numbers.top();
		numbers.pop();
		switch (op)
		{
		case '+':
			numbers.push(a + b);
			break;
		case '-':
			numbers.push(a - b);
			break;
		case '*':
			numbers.push(a * b);
			break;
		case '/':
			numbers.push(a / b);
			break;
		}
	}
	else
	{
		// Insufficient operands
		std::cout << "Invalid input." << std::endl;
	}
}