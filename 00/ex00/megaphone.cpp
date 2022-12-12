#include <iostream>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while(++i<argc)
	{
		int j = -1;
		while (argv[i][++j])
			argv[i][j] = std::toupper(argv[i][j]);
		std::cout<<argv[i];
	}
	std::cout<<std::endl;
	return (0);
}
