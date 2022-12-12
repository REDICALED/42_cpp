#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	int i = 0;
	if (argc == 1)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while(++i<argc)
	{
		int j = -1;
		while (argv[i][++j])
			argv[i][j] = toupper(argv[i][j]);
		std::cout<<argv[i];
	}
	std::cout<<std::endl;
}
