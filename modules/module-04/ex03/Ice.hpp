#ifndef	__ICE_HPP__
#define	__ICE_HPP__

#include	"AMateria.hpp"

class Ice : public	AMateria
{
	private:
		/* data */
	public:
		Ice();
		Ice(const Ice& copy);
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);

		Ice	&operator=(const Ice& fix);
};

#endif
