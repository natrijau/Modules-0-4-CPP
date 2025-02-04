#ifndef	__CURE_HPP__
#define	__CURE_HPP__

#include	"AMateria.hpp"

class Cure : public	AMateria
{
	private:
		/* data */
	public:
		Cure();
		Cure(const Cure& copy);
		Cure(std::string const & type);
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
		
		Cure	&operator=(const Cure& fix);
};


#endif
