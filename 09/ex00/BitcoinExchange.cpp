#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::~BitcoinExchange(){

}

void BitcoinExchange::make_csv_map(){
		std::ifstream data_csv("data.csv");
		if(!data_csv.is_open())
		{
			std::cout << "data csv file open fail" << std::endl;
			exit(1);
		}
		std::string tmp_line;
		std::getline(data_csv, tmp_line);
		while (std::getline(data_csv, tmp_line) && !tmp_line.empty())
		{
    	char *temp = std::strtok(const_cast<char*>(tmp_line.c_str()),",");
			std::string map_in1 = temp;
			temp = strtok(NULL, ",");
			float map_in2 = std::atof(temp);
			csv_map[map_in1] = map_in2;
    }
		data_csv.close();
}

void BitcoinExchange::bit_checker(char *str){
	std::ifstream input_ifs(str);
		if(!input_ifs.is_open())
		{
			std::cout << "input file open fail" << std::endl;
			exit(1);
		}
		std::string tmp_line;
		std::getline(input_ifs, tmp_line);
		while (std::getline(input_ifs, tmp_line) && !tmp_line.empty())
		{
			if (tmp_line.find("|") == std::string::npos)
				std::cout<<"Error: bad input => "<<tmp_line <<std::endl;
			else
			{
				char *temp = std::strtok(const_cast<char*>(tmp_line.c_str()),"|");
				std::string map_in1 = temp;
				temp = strtok(NULL, "|");
				float map_in2;
				std::tm date = {};
				std::istringstream ss(map_in1);
				ss >> std::get_time(&date, "%Y-%m-%d");
				if (ss.fail()) {
					std::cout<<"Error: bad input => "<<map_in1 <<std::endl;
					continue;
				}
				if (temp)
					map_in2 = std::atof(temp);
				else
				{
					std::cout<<"Error: bad input => "<<tmp_line <<std::endl;
					continue;
				}
				std::map<std::string, float>::iterator itr = csv_map.lower_bound(map_in1);
				if (!itr->first.compare(map_in1))
				{
					if (map_in2 > 0 && map_in2 < 1000)		
						std::cout<< itr->first << " => "<< map_in2 << " = " << map_in2 * itr->second<<std::endl;
					else if(map_in2 <= 0)
						std::cout<<"Error: not a positive number."<<std::endl;
					else
						std::cout<<"Error: too large a number."<<std::endl;
				}
				else
				{
					itr--;
					if (map_in2 > 0 && map_in2 < 1000)		
						std::cout<< itr->first << " => "<< map_in2 << " = " << map_in2 * itr->second<<std::endl;
					else if(map_in2 <= 0)
						std::cout<<"Error: not a positive number."<<std::endl;
					else
						std::cout<<"Error: too large a number."<<std::endl;
				}
			}
    }
		input_ifs.close();
}


BitcoinExchange::BitcoinExchange(int argc, char **argv){
	if (argc <= 1)
		std::cout<<"Error: could not open file."<<std::endl;
	else if (argc == 2)
	{
		make_csv_map();
		bit_checker(argv[1]);
	}
	else
	{
		std::cout<<"Error: too many input files."<<std::endl;
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& bitcoinExchange){
	(void)bitcoinExchange;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& bitcoinExchange){
	if (this == &bitcoinExchange)
		return *this;
	return *this;
}