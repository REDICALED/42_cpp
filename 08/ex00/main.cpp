#include "easyfind.hpp"
#include <time.h>

int main(int argc, char **argv) {

	if (argc == 2)
	{
		std::vector<int> v;
		srand(time(NULL));
		int i = -1;
		while (++i < atoi(argv[1]))
			v.push_back(i);
		easyfind(v, rand()%atoi(argv[1]));
	}
	else
		std::cout<<"인자 2개 ㄱㄱ"<<std::endl;
}
