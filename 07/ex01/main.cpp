#include "iter.hpp"
#include <iostream>
#include <string.h>

int main(void) {
	
	char arr[3] = {'a', 'b', 'c'};
	iter(arr, strlen(arr), print_val);
	return 0;
}
