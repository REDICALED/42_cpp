#include "RPN.hpp"

RPN::RPN(){

}
void RPN::check_loop(){
	int i = 0;
	while(input_str[i])
	{
		if (input_str[i] >= '0' && input_str[i] <= '9')
			main_stack.push(input_str[i] - 48);
		else if (input_str[i] == '+' || input_str[i] == '/' || input_str[i] == '-' || input_str[i] == '*' )
		{
			if(main_stack.size() < 2)
			{
				input_str[i] = 'E';
				continue;
			}
			else
			{
				if (input_str[i] == '+')
				{
					int tmp = main_stack.top();
					main_stack.pop();
					tmp += main_stack.top();
					main_stack.pop();
					main_stack.push(tmp);
				}
				else if (input_str[i] == '-')
				{
					int tmp = main_stack.top();
					main_stack.pop();
					tmp = main_stack.top() - tmp;
					main_stack.pop();
					main_stack.push(tmp);
				}
				else if (input_str[i] == '*')
				{
					int tmp = main_stack.top();
					main_stack.pop();
					tmp = tmp * main_stack.top();
					main_stack.pop();
					main_stack.push(tmp);
				}
				else
				{
					int tmp = main_stack.top();
					main_stack.pop();
					tmp = main_stack.top() / tmp;
					main_stack.pop();
					main_stack.push(tmp);
				}
			}
		}
		else if (input_str[i] == ' ');
		else
		{
			std::cout<<"Error"<<std::endl;
			exit(1);
		}
		i ++;
	}
	std::cout<<main_stack.top()<<std::endl;
}


RPN::RPN(char **argv){
	this->input_str = argv[1];
}

RPN::~RPN(){

}

RPN::RPN(RPN& rpn):input_str(rpn.input_str){

}

RPN& RPN::operator=(RPN& rpn){
	if (this == &rpn)
		return *this;
		this->input_str = rpn.input_str;
	return *this;
}