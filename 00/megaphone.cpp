#include <iostream>

int main()
{
	std::string s;
	while (true)
	{
		std::cin >> s;
		std::cout << "word : " << s << std::endl;
		if (s == "as")
			return (0);
	}
}
