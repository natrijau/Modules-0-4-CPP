#ifndef	__CAT_HPP__
#define	__CAT_HPP__

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		/* data */
	public:

		void	makeSound() const;

		Cat();
		Cat(const Cat& copy);
		~Cat();

		Cat	&operator=(const Cat& n);
};

#endif