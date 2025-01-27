#ifndef	__DOG_HPP__
#define	__DOG_HPP__

#include "Animal.hpp"

class Dog : public Animal
{
	private:
		/* data */
	public:

		void	makeSound();

		Dog();
		~Dog();
};

#endif