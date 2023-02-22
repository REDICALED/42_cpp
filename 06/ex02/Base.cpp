#include "Base.hpp"
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <exception>

A::A(){
    std::cout<<"A generated!"<<std::endl;
}

B::B(){
    std::cout<<"B generated!"<<std::endl;
}

C::C(){
    std::cout<<"C generated!"<<std::endl;
}

Base * generate(void){
	int num = rand();
    if (num % 3 == 0)
        return new A();
    else if (num % 3 == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p){
    if (dynamic_cast<A*>(p) != NULL)
        std::cout<<"pointer is A"<<std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout<<"pointer is B"<<std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout<<"pointer is C"<<std::endl;
}

void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout<<"pointer is A"<<std::endl;
    }
    catch(std::exception &e){}
    try{
        (void)dynamic_cast<B&>(p);
        std::cout<<"pointer is B"<<std::endl;
    }
    catch(std::exception &e){}
    try{
        (void)dynamic_cast<C&>(p);
        std::cout<<"pointer is C"<<std::endl;
    }
    catch(std::exception &e){}
    
}