#pragma once
#include <iostream>
#include <stack>

class RPN{
public:
	RPN(char **argv);
	~RPN();
	RPN(RPN& rpn);
	RPN& operator=(RPN& rpn);
	void check_loop();

private:
	RPN();
	std::string input_str;
	std::stack<int> main_stack;
};

