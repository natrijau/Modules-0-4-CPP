#include <iostream>

int	main()
{
	std::string brain = "Hi THIS IS BRAIN";

	/*Initialise le pointeur ptr avec l'adresse memoire de brain. */
	/* Le pointeur ptr contient maintenant l'adresse mémoire de la variable brain*/
	std::string *ptr;
	ptr = &brain;

	/*Initialise la référence ref avec brain.
	//La référence ref est maintenant un alias pour la variable brain.*/
	//Les références doivent être initialisées lors de leur déclaration
	std::string &ref = brain;

	/* Acceder a l' adresse d'une variable avec &. Ici &brain */
	std::cout << "Memory adresse of variable brain : " << &brain << std::endl;

	/* Acceder a l' adresse d'un pointeur . ptr correspond deja a l'adresse de brain */
	std::cout << "Memory adresse of string ptr : " << ptr << std::endl;

	/* Acceder a l' adresse d'une reference avec &. Ici &ref  */
	std::cout << "Memory adresse of string ref : " << &ref << std::endl;

	/* Acceder a la valeur de la variable brain */
	std::cout << "Value of string 'brain' : " << brain << std::endl;

	/* Acceder a la valeur d'un pointeur avec '*'. Ici *ptr */
	std::cout << "Value of string ptr : " << *ptr << std::endl;

	/* La reference est un alias pour une autre variable. Ici ref est un alias de la variable brain */
	std::cout << "Value of string ref : " << ref << std::endl;

	return (0);
}