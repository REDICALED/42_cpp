#include "Base.hpp"
#include <time.h>
#include <cstdlib>


int main(void) {
	srand((unsigned int)time(NULL));
	int loop;
	int i = -1;
	std::cin>>loop;
	while (++i < loop)
	{
		Base *base = generate();
		identify(base);
		identify(*base);
		delete(base);
	}
	return (0);
}
