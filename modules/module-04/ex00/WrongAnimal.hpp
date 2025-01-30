#ifndef	__WRONGANIMAL_HPP__
#define	__WRONGANIMAL_HPP__

#include	<iostream>

class WrongAnimal
{
	protected:

		std::string _type;
	
	public:

		void	makeSound() const;
		const	std::string& getType() const;

		WrongAnimal();
		WrongAnimal(const WrongAnimal& copy);
		~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal& n);
};

#endif