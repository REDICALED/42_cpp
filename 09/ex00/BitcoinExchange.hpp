#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <ctime>
#include <iomanip>
#include <sstream>
class BitcoinExchange{
public:
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange& bitcoinExchange);
	BitcoinExchange(int argc, char **argv);

private:
	BitcoinExchange();
	BitcoinExchange& operator=(BitcoinExchange& bitcoinExchange);
	std::string input_file;
	std::map<std::string, float> csv_map;
	void make_csv_map();
	void bit_checker(char *str);
};
