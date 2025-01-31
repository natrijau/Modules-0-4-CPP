#include	"Animal.hpp"
#include	"Dog.hpp"
#include	"Cat.hpp"
#include	"Brain.hpp"

int	main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;

	std::cout << "Creating an array of Animals..." << std::endl;
	Animal* animals[6];

	for (int i = 0; i < 3; ++i)
		animals[i] = new Dog();

	for (int i = 3; i < 6; ++i)
		animals[i] = new Cat();

	std::cout << "Deleting the array of Animals..." << std::endl;
	for (int i = 0; i < 6; ++i)
		delete animals[i];

	Dog* test = new Dog();

	test->setIdea("IDEA");
	Dog* second = new Dog(*test);
	second->setIdea("BAAAAA");

	std::cout << "the second idea(" << second->getIdea(1) << ") of 'second' its not the same idea(" << test->getIdea(1) << ") of 'test'" << std::endl;

	delete(test);
	delete(second);

	return (0);
}