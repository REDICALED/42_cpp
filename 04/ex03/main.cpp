#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main( void ){

	int size = 10;
	Animal* ani[size];
	Dog dogo;
	int i = -1;
	while (++i <size)
	{
		if (i < size / 2)
			ani[i] = new Dog;
		else
			ani[i] = new Cat;
	}

	std::cout<<"--------------------"<<std::endl;

	dogo.set_brain("오 안녕하세요. 저는 강아지 박사 존 이라고 합니다..");
	dogo.set_brain("혹시 '강아지 이론 물리학'에 대해서 들어보신적 있으신가요?");
	dogo.set_brain("자 이제 인간중심적인 사고에 벗어난 새로운 물리학의 세계를 보여드리도록 하죠.");
	dogo.print_brain(3);
	dogo.makeSound();
	std::cout<<"--------------------"<<std::endl;

	Dog son;
	son = dogo;
	son.set_brain( "껌 먹고 싶다!");
	dogo.print_brain(4); //복사 생성자를 지워서 디폴트로 호출하거나 대입 연산자를 바꿔보면?
	std::cout<<"--------------------"<<std::endl;
	son.print_brain(4);
	std::cout<<"--------------------"<<std::endl;


	ani[0]->makeSound();
	ani[5]->makeSound();

	std::cout<<"--------------------"<<std::endl;
	i = -1;
	while (++i < size)
		delete ani[i];
	return 0;
}