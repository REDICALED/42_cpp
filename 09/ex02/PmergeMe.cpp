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

void	PmergeMe::printseq(std::string str){
	std::cout << str;
	for (std::vector<int>::iterator itr = vector.begin(); itr != vector.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

bool	PmergeMe::int_checker(char** argv){
	int i = 0;
	unsigned int value;

	while (argv[++i])
	{
		value = std::strtol(argv[i], NULL, 10);
		if (value < 1 || value > 2147483647)
		{
			std::cout << "Error: Must use positive integer sequence" << std::endl;
			return false;
		}
		else
		{
			vector.push_back(static_cast<int>(value));
			deque.push_back(static_cast<int>(value));
		}
	}
	return true;
}

std::vector<int> PmergeMe::getVector(){
	return vector;
}

std::deque<int> PmergeMe::getDeque(){
	return deque;
}

void    PmergeMe::FoJosortVector(int left, int right){
	if (right - left + 1 > 10)
	{
		int half = (left + right) / 2;

		FoJosortVector(left, half);
		FoJosortVector(half + 1, right);
		mergeVector(left, half, right);
	}
	else
		insertionsortVector(left, right);
}

void	PmergeMe::insertionsortVector(int left, int right)
{
	int i =left;
	while(i < right)
	{
		int j = i + 1;
		int temp = vector[j];
  	while (j > left && vector[j - 1] > temp)
		{
			vector[j] = vector[j - 1];
			j--;
		}
		vector[j] = temp;
		i++;
  }
}

void PmergeMe::mergeVector(int left, int half, int right)
{
	std::vector<int> tmp;

	int left_index = left;
	int right_index = half;
	for (int i = left; i < right + 1; i++)
	{
		if (left_index >= half)
			tmp.push_back(vector[right_index++]);
		else if (right_index >= right)
			tmp.push_back(vector[left_index++]);
		else if (vector[left_index]>vector[right_index])
			tmp.push_back(vector[right_index++]);
		else
			tmp.push_back(vector[left_index++]);
	}
	for (int i = left; i < right + 1; i++)
		vector[i] = tmp[i-left];
}

void    PmergeMe::FoJosortDeque(int left, int right){
	if (right - left + 1 > 10)
	{
		int half = (left + right) / 2;

		FoJosortDeque(left, half);
		FoJosortDeque(half + 1, right);
		mergeDeque(left, half, right);
	}
	else
		insertionsortDeque(left, right);
}

void	PmergeMe::insertionsortDeque(int left, int right)
{
	int i =left;
	while(i < right)
	{
		int j = i + 1;
		int temp = deque[j];
  	while (j > left && deque[j - 1] > temp)
		{
			deque[j] = deque[j - 1];
			j--;
		}
		deque[j] = temp;
		i++;
  }
}

void PmergeMe::mergeDeque(int left, int half, int right)
{
	std::deque<int> tmp;

	int left_index = left;
	int right_index = half;
	for (int i = left; i < right + 1; i++)
	{
		if (left_index >= half)
			tmp.push_back(deque[right_index++]);
		else if (right_index >= right)
			tmp.push_back(deque[left_index++]);
		else if (deque[left_index]>deque[right_index])
			tmp.push_back(deque[right_index++]);
		else
			tmp.push_back(deque[left_index++]);

	}
	for (int i = left; i < right + 1; i++)
		deque[i] = tmp[i-left];
}