#pragma once
#include <iostream>
#include <exception>

class Scala{
public:
	Scala();
	~Scala();
	Scala(const std::string& str);
	Scala(Scala& scala);
	void print_values(void);
	Scala& operator=(Scala& scala);
	class ParseError: public std::exception{
		public:
			const char* what() const throw();
	};

	class BadInput: public std::exception{
		public:
			const char* what() const throw();
	};
	class OverFlow: public std::exception{
		public:
			const char* what() const throw();
	};
private:
	void	find_type(const std::string& str);
	int		is_char(double tmp_double, char* end_ptr);
	int		is_int(double tmp_double, char* end_ptr);
	int		is_double(double tmp_double, char* end_ptr);
	int		is_float(double tmp_double, char* end_ptr);
	enum LiteralType {
	lNONE,
	lchar = 1,
	lint = 2,
	lfloat = 3,
	ldouble = 4
	};

	int sc_type;
	const std::string sc_str;
	double sc_double;
	int sc_int;
	char sc_char;
	float sc_float;
	bool sc_inf;
	double tmp_double;
};