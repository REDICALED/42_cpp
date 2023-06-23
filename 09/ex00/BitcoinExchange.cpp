#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(){
}

int BitcoinExchange::date_checker(std::string str_date){
	std::istringstream iss(str_date);
	int tm_year;
	int tm_month;
	int tm_day;
	char minus1;
	char minus2;
	std::tm timeinfo = {};
	iss >> tm_year >> minus1 >> tm_month >> minus2 >> tm_day;
	timeinfo.tm_year = tm_year - 1900;
	timeinfo.tm_mon = tm_month - 1;
	timeinfo.tm_mday = tm_day;
	if (std::mktime(&timeinfo) == -1 || minus1 != '-' || minus2 != '-'|| timeinfo.tm_year != tm_year - 1900|| timeinfo.tm_mon != tm_month - 1|| timeinfo.tm_mday != tm_day)
		return 1;
	return 0;
}


void BitcoinExchange::make_csv_map(std:: string str){
		std::ifstream data_csv(str);
		if(!data_csv.is_open())
		{
			std::cout << "Error: data csv file open fail" << std::endl;
			exit(1);
		}
		std::string tmp_line;
		std::getline(data_csv, tmp_line);
		if (tmp_line != "date,exchange_rate")
		{
			std::cout << "Error: wrong csv file first line" << std::endl;
			exit(1);
		}
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
			std::cout << "Error: input file open fail" << std::endl;
			exit(1);
		}
		std::string tmp_line;
		std::getline(input_ifs, tmp_line);
		if (tmp_line != "date | value")
		{
			std::cout << "Error: wrong input file first line" << std::endl;
			exit(1);
		}
		while (std::getline(input_ifs, tmp_line) && !tmp_line.empty())
		{
			char *temp = std::strtok(const_cast<char*>(tmp_line.c_str()),"|");
			std::string map_in1 = temp;
			temp = strtok(NULL, "|");
			float map_in2;
			if(date_checker(map_in1))
			{
			std::cout<<"Error: bad input => "<<tmp_line <<std::endl;
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
		input_ifs.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange& bitcoinExchange):input_file(bitcoinExchange.input_file),csv_map(bitcoinExchange.csv_map){
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange& bitcoinExchange){
	if (this == &bitcoinExchange)
		return *this;
	this->input_file = bitcoinExchange.input_file;
	this->csv_map = bitcoinExchange.csv_map;
	return *this;
}