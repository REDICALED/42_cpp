#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::ifstream ifs;
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		ifs.open(argv[1]);
		if(!ifs.is_open())
		{
			std::cout << "infile open fail" << std::endl;
			exit(1);
		}
		std::strcat(argv[1], ".replace");
		std::ofstream ofs;
		ofs.open(argv[1]);
		if(!ofs.is_open())
		{
			std::cout << "outfile open fail" << std::endl;
			exit(1);
		}
		if (s1.empty() || s2.empty()) {
			std::cout<<"s1 or s2 is empty"<<std::endl;
			exit(1);
		}
		while (!ifs.eof())
		{
			std::string str_tmp = "";
			std::getline(ifs, str_tmp);
			int i = 0;
			while ((i = str_tmp.find(s1)) != -1)
			{
				str_tmp.erase(i, s1.length());
				str_tmp.insert(i, s2);
			}
			const char *output_tmp = str_tmp.c_str();
			ofs.write(output_tmp, str_tmp.length());
			ofs.write("\n", 1);
		}
		ifs.close();
		ofs.close();
	}
	else
	{
		std::cout<<"argc != 4~ ~ ~ ~ ~"<<std::endl;
		exit(1);
	}
}