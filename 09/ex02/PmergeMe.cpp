#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {

}

PmergeMe::~PmergeMe(){

}

PmergeMe::PmergeMe(PmergeMe& pmergeMe){
(void)pmergeMe;
}

PmergeMe& PmergeMe::operator=(PmergeMe& pmergeMe){
	if (this == &pmergeMe)
		return *this;
	(void)pmergeMe;
 	return *this;
}