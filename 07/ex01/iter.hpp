#pragma once
#include <iostream>

template <typename T>
void iter (T *array, size_t length, void (*fn)(const T&))
{
	for (size_t i = 0; i < length; i++)
	{
		fn(array[i]);
	}
}

template <typename T>
void print_val(T& n1)
{
    std::cout<<n1<<std::endl;
}