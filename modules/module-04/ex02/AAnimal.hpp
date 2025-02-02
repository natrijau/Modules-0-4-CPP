#ifndef	__AANIMAL_HPP__
#define	__AANIMAL_HPP__

#include	<iostream>

class AAnimal
{
	protected:

		std::string _type;
	
	public:

		// method virtual pure
		virtual void	makeSound() const = 0;
		const	std::string& getType() const;

		AAnimal();
		AAnimal(const AAnimal& copy);
		virtual	~AAnimal();

		AAnimal	&operator=(const AAnimal& n);
};

#endif