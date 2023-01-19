#include "MateriaSource.hpp"

MateriaSource::~MateriaSource(){
	int i = -1;
	while(++i < 4) {
		if (memory[i])
		{
			delete memory[i];
			memory[i] = NULL;
		}
	}
}

MateriaSource::MateriaSource(){
	int i = -1;
	while(++i < 4)
		this->memory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource& materiaSource){
	int i = -1;
	while(++i < 4)
	{
		this->memory[i] = NULL;
		this->memory[i] = materiaSource.memory[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource& materiaSource){
	if (this == &materiaSource)
		return *this;
	int i = -1;
	while(++i < 4)
	{
		if (this->memory[i] != NULL)
			delete this->memory[i];
		this->memory[i] = NULL;
		this->memory[i] = materiaSource.memory[i]->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* m){
	int i = -1;
	while(++i < 4)
	{
		if (this->memory[i] == NULL)
		{
			this->memory[i] = m;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	int i = -1;
	while(++i < 4)
	{
		if (this->memory[i] != NULL && this->memory[i]->getType() == type)
		{
			AMateria* ret = this->memory[i]->clone();
			return ret;
		}
	}
	return 0;
}
