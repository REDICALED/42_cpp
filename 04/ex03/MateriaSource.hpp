#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
	AMateria* memory[4];
public:
	virtual ~MateriaSource();
	MateriaSource();
	MateriaSource(MateriaSource& materiaSource);
	MateriaSource& operator=(MateriaSource& materiaSource);

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
};
