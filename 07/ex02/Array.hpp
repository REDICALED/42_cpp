#include <exception>
#include <iostream>
#include <time.h>
#include <stdlib.h>

template<typename T>
class Array{
private:
	unsigned int ar_size;
	T *ar_array;
public:
	class IndexOut: public std::exception {
   	public:
    	const char* what(void) const throw(){
        	return "its index is out of bounds";
		}
	};

	Array(void): ar_size(0), ar_array(NULL){
	};

	Array(unsigned int n): ar_size(n), ar_array(NULL){
		if (ar_size)
      		ar_array = new T[ar_size];
	};
	Array& operator=(const Array& array){
		if (*this == array)
			return *this;
		if (ar_size) {
			delete[] ar_array;
			ar_array = NULL;
			ar_size = 0;
		}
		ar_size = array.size();
		if (ar_size)
			ar_array = new T[ar_size];
		int i = -1;
		while (++i < ar_size)
			ar_array[i] = array[i];
	}

	Array(const Array& array): ar_size(array.size()), ar_array(NULL){
		if (ar_size)
      		ar_array = new T[ar_size];
    for (std::size_t i = 0 ; i < ar_size ; ++i)
    	ar_array[i] = array[i];
	}

	~Array(void){if (ar_size) {
      delete[] ar_array;
      ar_array = NULL;
      ar_size = 0;
    }
  };

	unsigned int size(void) const{
		return (ar_size);
	}

	T& operator[] (std::size_t i){
		if (i >= ar_size)
			throw IndexOut();
		return ar_array[i];
	}
	const T& operator[] (std::size_t i) const{
		if (i >= ar_size)
			throw IndexOut();
		return ar_array[i];
	}

};
