#include <iostream>
#include <stdint.h>

struct Data
{
    int number;
};

uintptr_t serialize(Data* ptr){
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw){
	return(reinterpret_cast<Data *>(raw));
}


int main(void) {
	Data data;
	Data *data_set;
	uintptr_t ptr;

	data.number = 1004;

	ptr = serialize(&data);
	std::cout << "ptr : " << ptr << std::endl;

	data_set = deserialize(ptr);
	std::cout << "next : " << data_set->number << std::endl;

	return (0);
}
