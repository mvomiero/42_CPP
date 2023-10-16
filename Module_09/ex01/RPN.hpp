#pragma once

#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <functional>
#include <cctype>
#include "colors.h"

#define VERBOSE false

class RPN
{
private:
	std::stack<double> numbers;


public:
	RPN();
	RPN(std::stack<double> number);
	RPN(const RPN &other);
	~RPN();
	RPN &operator=(const RPN &rhs);
	void calculate(const std::string &input);
	bool performOperation(char operation);
	void printStack(char c);
};