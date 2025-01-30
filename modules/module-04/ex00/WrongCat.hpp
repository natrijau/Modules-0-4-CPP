#ifndef	__WRONGCAT_HPP__
#define	__WRONGCAT_HPP__

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		/* data */
	public:

		void	makeSound() const;

		WrongCat();
		WrongCat(const WrongCat& copy);
		~WrongCat();

		WrongCat	&operator=(const WrongCat& n);
};

#endif