#include "Scala.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <cmath>
#include <errno.h>

Scala::Scala(){

}

Scala::~Scala(){

}

Scala::Scala(Scala& scala){
	(void)scala;
}

int Scala::is_float(double tmp_double, char* end_ptr)
{
	(void)tmp_double;
	if (end_ptr[0] == 'f' && end_ptr[1] == 0)
	{
		if (sc_str.find('.',0) != std::string::npos) //0f 예외처리
		{
			if ((tmp_double > FLT_MAX || tmp_double < -FLT_MAX))
				throw OverFlow();
			sc_float = tmp_double;
			return 1;
		}
		else
		{
			if ((std::isinf(tmp_double) || std::isnan(tmp_double)))
			{
				sc_float = tmp_double;
				return 1;
			}
		}
	}
	return 0;
}

int Scala::is_double(double tmp_double, char* end_ptr)
{
	(void)tmp_double;
	if (!*end_ptr) 
	{
		if ((std::isinf(tmp_double) || std::isnan(tmp_double)) && sc_str.length() > 4)
			throw OverFlow();
		if ((std::isinf(tmp_double) || std::isnan(tmp_double)))
			sc_inf = 1;
		sc_double = tmp_double;
		return 1;
	}
	return 0;
}

int Scala::is_int(double tmp_double, char* end_ptr)
{
	char *tol_ptr = NULL;
	if (*end_ptr)
		return 0;
	else
	{
		if (tmp_double == strtol(sc_str.c_str(), &tol_ptr, 10) && !*tol_ptr && tmp_double <= INT_MAX && tmp_double >= INT_MIN)
		{
			sc_int = strtol(sc_str.c_str(), &tol_ptr, 10);
			return 1;
		}
	}
	return 0;
}

int Scala::is_char(double tmp_double, char* end_ptr)
{
	if (sc_str.length() == 0)
	{
		sc_char = '\0';
		return 1;
	}

	if (sc_str.length() == 1 && tmp_double == 0 && isascii(end_ptr[0]) && !(isdigit(end_ptr[0])) && sc_str != "0")
	{
		sc_char = end_ptr[0];
		return 1;	
	}
	return 0;
}

void Scala::find_type(const std::string& str){
		char *end_ptr = NULL;
		tmp_double = std::strtod(str.c_str(), &end_ptr);
	
		//char먼저 검사.
		if (is_char(tmp_double, end_ptr))
		{
			sc_type = lchar;
			std::cout<<"input tpye is char!"<<std::endl;
		}
		else if (sc_type == 0 && is_int(tmp_double, end_ptr))
		{
			sc_type = lint;
			std::cout<<"input tpye is int!"<<std::endl;
		}
		else if (sc_type == 0 && is_double(tmp_double, end_ptr))
		{
			sc_type = ldouble;
			std::cout<<"input tpye is double!"<<std::endl;

		}
		else if (sc_type == 0 && is_float(tmp_double, end_ptr))
		{
			sc_type = lfloat;
			std::cout<<"input tpye is float!"<<std::endl;
			
		}
	std::cout<<"------------------------"<<std::endl;
}

Scala::Scala(const std::string& str):sc_type(0),sc_str(str),sc_inf(0),is_valid(0)
{	
	try{
		find_type(str);
		switch (sc_type)
		{
			case lNONE:
				throw BadInput();
			case lchar:
				sc_int = static_cast<int>(sc_char);
				sc_double = static_cast<double>(sc_char);
				sc_float = static_cast<float>(sc_char);
				break;
			case lint:
				sc_char = static_cast<char>(sc_int);
				sc_double = static_cast<double>(sc_int);
				sc_float = static_cast<float>(sc_int);
				break;
			case lfloat:
				sc_char = static_cast<char>(sc_float);
				sc_double = static_cast<double>(sc_float);
				sc_int = static_cast<int>(sc_float);
				break;
			case ldouble:
				sc_char = static_cast<char>(sc_double);
				sc_float = static_cast<float>(sc_double);
				sc_int = static_cast<int>(sc_double);
				break;
		}
		is_valid = 1;
	}
	catch(std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
}

void Scala::print_values(void){
	if(is_valid)
	{
		if (isprint(sc_char))
			std::cout<<"char: '"<<sc_char<<"'"<<std::endl;
		else if (tmp_double > CHAR_MAX || tmp_double < CHAR_MIN|| std::isinf(tmp_double) || std::isnan(tmp_double))
			std::cout<<"char: impossible"<<std::endl;
		else
			std::cout<<"char: Non displayable"<<std::endl;
		if(tmp_double > INT_MAX || tmp_double < INT_MIN || std::isinf(tmp_double) || std::isnan(tmp_double))
			std::cout<<"int: impossible"<<std::endl;
		else
			std::cout<<"int: "<<sc_int<<std::endl;
		if(((!std::isinf(tmp_double)) && std::isinf(sc_float)) || (!std::isnan(tmp_double) && std::isnan(sc_float)))
			std::cout<<"float: impossible"<<std::endl;
		else
			std::cout<<"float: "<<sc_float<<"f"<<std::endl;
		std::cout<<"double: "<<sc_double<<std::endl;
	}
}

const char* Scala::ParseError::what() const throw(){
	return "Parse Error.";
}

const char* Scala::BadInput::what() const throw(){
	return "BadInput";
}

const char* Scala::OverFlow::what() const throw(){
	return "OverlFlow.";
}

Scala& Scala::operator=(Scala& scala){
	if (this == &scala)
		return *this;
	sc_type = scala.sc_type;
	sc_char = scala.sc_char;
	sc_double = scala.sc_double;
	sc_float = scala.sc_float;
	sc_inf = scala.sc_inf;
	sc_int = scala.sc_int;
	sc_type = scala.sc_type;
	return *this;
}