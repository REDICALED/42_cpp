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
		if (s1.empty()) {
			std::cout<<"s1 is empty"<<std::endl;
			exit(1);
		}
		int find_pos;
		while (1)
		{
			find_pos = 0;
			std::string str_tmp = "";
			std::getline(ifs, str_tmp);
			if (!ifs.eof())
				str_tmp.push_back('\n');
			else
				break ;
			while ((find_pos = str_tmp.find(s1, find_pos)) != -1)
			{
				str_tmp.erase(find_pos, s1.length());
				str_tmp.insert(find_pos, s2);
				find_pos = find_pos + s2.length();
			}
			const char *output_tmp = str_tmp.c_str();
			ofs.write(output_tmp, str_tmp.length());
		}
		ifs.close();
		ofs.close();
		return (0);
	}
	else
	{
		std::cout<<"argc != 4~ ~ ~ ~ ~"<<std::endl;
		exit(1);
	}
}