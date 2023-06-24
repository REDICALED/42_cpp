#pragma once
#include <iostream>
#include <vector>
#include <deque>

class PmergeMe{
public:
	PmergeMe();
	~PmergeMe();
	bool int_checker(char **argv);
	void printseq(std::string str);
	void FoJosortVector(int left, int right);
	std::vector<int> getVector();
	std::deque<int> getDeque();
	void FoJosortDeque(int left, int right);

private:
	PmergeMe(PmergeMe& pmergeMe);
	PmergeMe& operator=(PmergeMe& pmergeMe);
	std::vector<int> vector;
	std::deque<int> deque;
	void mergeVector(int left, int half, int right);
	void insertionsortVector(int left, int right);


	void mergeDeque(int left, int half, int right);
	void insertionsortDeque(int left, int right);

};