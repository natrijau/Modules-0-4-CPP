#include	"AAnimal.hpp"
#include	"Dog.hpp"
#include	"Cat.hpp"
#include	"Brain.hpp"

int	main()
{
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();
	delete j;
	delete i;

	std::cout << "Creating an array of AAnimals..." << std::endl;
	AAnimal* animals[6];

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

	//std::cout << "The Animal Class cannot be instantiated" << std::endl;
	//AAnimal animal;

	return (0);
}