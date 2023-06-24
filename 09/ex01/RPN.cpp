#include "RPN.hpp"

RPN::RPN(){

}
void RPN::check_loop(){
	int i = 0;
	int index = 0;
	while(input_str[i])
	{
		if (input_str[i] >= '0' && input_str[i] <= '9' && index%2 == 0)
		{
			main_stack.push(input_str[i] - 48);
			index ++;
		}
		else if ((input_str[i] == '+' || input_str[i] == '/' || input_str[i] == '-' || input_str[i] == '*' ) && index%2 == 0)
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
			index ++;
		}
		else if (input_str[i] == ' ')
			index = 0;
		else
		{
			std::cout<<"Error"<<std::endl;
			exit(1);
		}
		i ++;
	}
	if (main_stack.size() > 1)
	{
			std::cout<<"Error"<<std::endl;
			exit(1);
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