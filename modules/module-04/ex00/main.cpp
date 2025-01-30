#include	"Animal.hpp"
#include	"Dog.hpp"
#include	"Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << j->getType() << " = _type" << std::endl;
	j->makeSound();
	std::cout << std::endl;
	std::cout << i->getType() << " = _type" << std::endl;
	i->makeSound(); //will output the cat sound!
	std::cout << std::endl;
	std::cout << meta->getType() << " = _type" << std::endl;
	meta->makeSound();
	std::cout << std::endl;
	const Dog* pluto = new Dog();
	std::cout << std::endl;
	std::cout << pluto->getType() << " " << std::endl;
	pluto->makeSound();
	std::cout << std::endl;
	
	delete(pluto);
	delete(meta);
	delete(j);
	delete(i);
	return (0);
}