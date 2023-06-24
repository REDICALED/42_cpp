#include "PmergeMe.hpp"

int	main(int argc, char* argv[])
{
	PmergeMe	main_pmerge;

    std::clock_t vector_start;
    std::clock_t vector_end;
    std::clock_t deque_start;
    std::clock_t deque_end;

	if (argc < 2)
	{
		std::cout<<"Error: Too few arguments"<<std::endl;
		return 1;
	}

	if (main_pmerge.int_checker(argv) == false)
		return 1;

	main_pmerge.printseq("Before: ");
  vector_start = std::clock();
	main_pmerge.FoJosortVector(0, main_pmerge.getVector().size() - 1);
  vector_end = std::clock();
	deque_start = std::clock();
	main_pmerge.FoJosortDeque(0, main_pmerge.getDeque().size() - 1);
  deque_end  = std::clock();

	main_pmerge.printseq("After: ");
  std::cout<<"Time to process a range of ";
  std::cout<<main_pmerge.getVector().size();
  std::cout<<" elements with std::vector : ";
  std::cout<<vector_end - vector_start;
  std::cout<<" us"<<std::endl;

  std::cout<<"Time to process a range of ";
  std::cout<<main_pmerge.getDeque().size();
  std::cout<<" elements with std::deque : ";
  std::cout<<deque_end - deque_start;
  std::cout<<" us"<<std::endl;

	return 0;
}