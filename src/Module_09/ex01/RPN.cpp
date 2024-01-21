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

RPN::RPN(const RPN &other)
{
	*this = other;
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
			int number = c - '0'; // Convert char to int
			numbers.push(number);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			// Handle operators
			if (!performOperation(c))
				return;
		}
		else
		{
			// Invalid character
			std::cout << RED "Error - invalid character" RESET << std::endl;
			return;
		}
		if (VERBOSE)
			printStack(c);
	}

	// check for the result
	if (numbers.size() == 1)
	{
		double result = numbers.top();
		numbers.pop();
		std::cout << BG_GREEN "Result: " << result << RESET << std::endl;
	}
	else
	{
		// Insufficient operands
		std::cout << RED "Error - insufficient operators" RESET << std::endl;
	}
}

void RPN::printStack(char c)
{
	if (isdigit(c))
		std::cout << BLUE "operand: " << c << " pushed to stack --> " RESET << std::endl;
	else if (c == '+' || c == '-' || c == '*' || c == '/')
		std::cout << PURPLE "operator: " << c << " executes the operation --> " RESET << std::endl;

	std::cout << "\tstack: [";
	for (std::stack<double> dump = numbers; !dump.empty(); dump.pop())
	{
		std::cout << dump.top() << ", ";
	}
	std::cout << "]" << std::endl;
}

bool RPN::performOperation(char op)
{
	if (numbers.size() >= 2)
	{
		double b = numbers.top(); // Top element is right operand
		numbers.pop();
		double a = numbers.top(); // Next element is left operand
		numbers.pop();

		// Perform operation
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
		return true;
	}
	else
	{
		// Insufficient operands
		std::cout << RED "Error - insufficient operands" RESET << std::endl;
		return false;
	}
}