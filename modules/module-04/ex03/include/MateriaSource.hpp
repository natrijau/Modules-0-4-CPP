#ifndef	__MATERIASOURCE_HPP__
#define	__MATERIASOURCE_HPP__

#include	"AMateria.hpp"
#include	"IMateriaSource.hpp"

class	MateriaSource;

class MateriaSource : public IMateriaSource
{
	private:

		AMateria* _inventory[4];

	public:
	
		MateriaSource();
		MateriaSource(const MateriaSource& copy);
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);

		MateriaSource &operator=(const MateriaSource& fix);
};

#endif