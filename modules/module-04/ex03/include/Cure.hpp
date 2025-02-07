#ifndef	__CURE_HPP__
#define	__CURE_HPP__

#include	"AMateria.hpp"

class	ICharacter;

class Cure : public	AMateria
{
	private:
		/* data */
	public:
		Cure();
		Cure(const Cure& copy);
		Cure(std::string const & type);
		virtual ~Cure();

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
		
		Cure	&operator=(const Cure& fix);
};


#endif
