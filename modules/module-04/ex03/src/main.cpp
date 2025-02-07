#include	"ICharacter.hpp"
#include	"AMateria.hpp"
#include	"IMateriaSource.hpp"
#include	"MateriaSource.hpp"
#include	"Ice.hpp"
#include	"Cure.hpp"
#include	"Character.hpp"

int	main()
{
	// Materia source created
	IMateriaSource* src = new MateriaSource();
	
	//Learned Materia Ice
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());

	//News characters
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	//Init Materia
	AMateria* tmp;

	//creat Materia Ice in array inventory of class Materia
	tmp = src->createMateria("ice");
	// me equip with Materia tmp = ICE
	me->equip(tmp);
	
	//impossible to creat cure because dont have learned that
	tmp = src->createMateria("cure");
	// so impossible to equip
	me->equip(tmp);

	//Learned Materia Cure
	src->learnMateria(new Cure());

	//Not creat a fail materia type
	tmp = src->createMateria("s");
	// so impossible to equip
	me->equip(tmp);
	
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(1);
	me->use(1, *bob);

	ICharacter* test = new Character("test");

	for (size_t i = 0; i < 100; i++)
	{
		tmp = src->createMateria("ice");
		test->equip(tmp);
		test->unequip(0);
	}
	test->use(0, *me);

	delete bob;
	delete me;
	delete test;
	delete src;
	return (0);
}