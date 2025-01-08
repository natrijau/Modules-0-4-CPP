#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{

	std::cout << "=== Test de la classe Weapon ===" << std::endl;
	Weapon club("une baguette magique");
	std::cout << "Type de l'arme: " << club.getType() << std::endl;
	club.setType("une banane");
	std::cout << "Nouveau type de l'arme: " << club.getType() << std::endl;

	std::cout << "\n=== Test de la classe HumanA ===" << std::endl;
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("un prout");
	bob.attack();

	std::cout << "\n=== Test de la classe HumanB ===" << std::endl;
	HumanB jim("Jim");
	// Jim n'a pas encore d'arme et attaque
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("un poison");
	jim.attack();

	return (0);
}
