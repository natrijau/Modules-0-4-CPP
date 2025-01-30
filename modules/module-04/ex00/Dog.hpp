#ifndef	__DOG_HPP__
#define	__DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		/* data */
	public:

		void	makeSound() const;

		Dog();
		Dog(const Dog& copy);
		~Dog();
		Dog	&operator=(const Dog& n);
};

#endif