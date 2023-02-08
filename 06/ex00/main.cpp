#include "Scala.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <cmath>
#include <errno.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "인자 하나만 넣어주세요 오홍홍"<<std::endl;
	}
	else {
		Scala s(argv[1]);
	}
	return 0;
}

// 됨 .0/ 0./ 0.f/ 00000.f/ .0f

// 안됨 .f/ 0f/