#include "BitcoinExchange.hpp"

int main(int argc, char **argv){
	if (argc <= 1)
		std::cout<<"Error: could not open file."<<std::endl;
	else if (argc == 2)
	{
		BitcoinExchange main_bt;
		main_bt.make_csv_map("data.csv");
		main_bt.bit_checker(argv[1]);
	}
	else
		std::cout<<"Error: too many input files."<<std::endl;
	return 0;
}