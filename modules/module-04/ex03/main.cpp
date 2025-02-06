#include	"ICharacter.hpp"
#include	"AMateria.hpp"
#include	"IMateriaSource.hpp"
#include	"MateriaSource.hpp"
#include	"Ice.hpp"
#include	"Cure.hpp"
#include	"Character.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	src->learnMateria(new Cure());
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	me->use(1, *bob);

	ICharacter* test = new Character("test");
	AMateria* tmp2;

	tmp2 = src->createMateria("ice");
	for (size_t i = 0; i < 100; i++)
	{
		test->equip(tmp2);
		test->unequip(0);
	}
	
	// test->equip(tmp2);
	test->use(0, *me);

	delete bob;
	delete me;
	delete src;
	// delete test;
	return (0);
}