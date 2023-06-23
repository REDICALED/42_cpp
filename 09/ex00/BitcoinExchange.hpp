#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <sstream>

class BitcoinExchange{
public:
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange& bitcoinExchange);
	BitcoinExchange& operator=(BitcoinExchange& bitcoinExchange);
	void bit_checker(char *str);
	BitcoinExchange();
	void make_csv_map(std::string str);

private:
	std::string input_file;
	std::map<std::string, float> csv_map;
	int date_checker(std::string str_date);
};
