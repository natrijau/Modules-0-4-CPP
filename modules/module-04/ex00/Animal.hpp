#ifndef	__ANIMAL_HPP__
#define	__ANIMAL_HPP__

#include	<iostream>

class Animal
{
	protected:

		std::string _type;
	
	public:

		virtual void	makeSound() const;
		const	std::string& getType() const;

		Animal();
		Animal(const Animal& copy);
		virtual	~Animal();

		Animal	&operator=(const Animal& n);
};

#endif