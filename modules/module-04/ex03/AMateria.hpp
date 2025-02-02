#ifndef	__AMATERIA_HPP__
#define	__AMATERIA_HPP__

#include	<iostream>

class AMateria
{
	protected:

		std::string	type;

	public:

		AMateria();
		AMateria(std::string const & type);
		~AMateria();
	
		std::string const & getType() const; //Returns the materia type

		AMateria	&operator=(const AMateria& fix);

		virtual AMateria* clone() const = 0;
		//virtual void use(ICharacter& target);
};

#endif
