#include "Span.hpp"
#include <exception>
#include <stdlib.h>

Span::Span() {
    std::cout<<"기본 생성자 쓰지마세요 헤헤"<<std::endl;
}

Span::Span(unsigned int N):max_size(N){
    
}

Span::~Span(){

}

Span::Span(const Span& span){
    this->set = span.set;
}

void Span::add_rand(unsigned int range, unsigned int gap){
    if (range > max_size)
        throw std::runtime_error("size over! *o*");
    unsigned int i = 0;
    if (set.size() == 0)
        set.insert(rand() % gap);
    std::set<int>::iterator end_iter = set.end();
    --end_iter;
    while (++ i <= range)
    {
        set.insert(*end_iter + (rand() % gap));
        ++end_iter;
    }
}

void Span::addNumber(int input){
    if (set.size() == max_size)
        throw std::runtime_error("size over! *o*");
    std::pair<std::set<int>::iterator ,bool> pair1;
    pair1 = set.insert(input);
    if (!pair1.second)
        throw std::runtime_error("already input detected !.!");
}

unsigned int Span::shortestSpan(){
    if (set.size() == 0 || set.size() == 1)
        throw std::runtime_error("no numbers stored, or only one -.-");
    int tmp_shortest;
    int return_shortest;
    std::set<int>::iterator begin_iter = set.begin();
    std::set<int>::iterator end_iter = set.end();
    return_shortest = abs(*begin_iter - *(++begin_iter));
    while (begin_iter != end_iter)
    {
        begin_iter ++;
        tmp_shortest = abs(*(begin_iter) - *(--begin_iter));
        if (tmp_shortest < return_shortest)
            return_shortest = tmp_shortest;
        begin_iter ++;
    }
    return (return_shortest);
}

unsigned int Span::longestSpan(){
    if (set.size() == 0 || set.size() == 1)
        throw std::runtime_error("no numbers stored, or only one -.-");
    std::set<int>::iterator begin_iter = set.begin();
    std::set<int>::iterator end_iter = set.end();
    --end_iter;
    return (*end_iter - *begin_iter);
}

Span& Span::operator=(Span& span){
	if (this == &span)
		return *this;
	this->set = span.set;
	return *this;
}

std::set<int> Span::get_set(void) const{
    return set;
}

std::ostream& operator<<(std::ostream& os, const Span& span){
    std::set<int> tmp_set = span.get_set();
    os <<tmp_set.size();
	return os;
}


const char* Span::AlreadyExist::what() const throw(){
    return "Already Exist value !<o.o>!";
}
