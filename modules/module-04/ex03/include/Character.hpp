#ifndef	__CHARACTER_HPP__
#define	__CHARACTER_HPP__

#include	"ICharacter.hpp"
#include	"AMateria.hpp"

class	AMateria;

class Character : public ICharacter
{
	private :

		std::string	_name;
		AMateria* 	_inventory[4];
		AMateria*	_floor[100];

	public:

		Character();
		Character(std::string name);
		Character(const Character& copy);
		virtual ~Character();

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

		Character	&operator=(const Character& fix);
};

#endif