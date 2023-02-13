#pragma once
#include <iostream>
#include <set>

class Span{
public:
    Span(unsigned int N);
	~Span();
	Span(const Span& span);
	Span& operator=(Span& span);

    void addNumber(int input);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    void add_rand(unsigned int range, unsigned int gap);
    std::set<int> get_set(void) const;

    class AlreadyExist: public std::exception{
        const char* what() const throw();
    };

private:
    Span();
    std::set<int> set;
    unsigned int max_size;
};

std::ostream& operator<<(std::ostream& os, const Span& span);
