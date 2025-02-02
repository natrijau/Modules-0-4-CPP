#ifndef	__DOG_HPP__
#define	__DOG_HPP__

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:

		Brain* _brain;
	
	public:

		Dog();
		Dog(const Dog& copy);
		~Dog();

		Dog	&operator=(const Dog& n);

		const	std::string getIdea(unsigned int i) const;

		void	makeSound() const ;
		void	setIdea(std::string idea);
};

#endif