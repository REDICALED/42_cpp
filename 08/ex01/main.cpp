#include "Span.hpp"
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	try{
		Span sp = Span(10000);
		sp.add_rand(10000, 191111199);
		std::cout<<sp.shortestSpan() << std::endl;
		std::cout<<sp.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}