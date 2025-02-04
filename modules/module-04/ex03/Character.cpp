#include	"Character.hpp"

Character::Character(std::string name)
:	_name(name)
{
	std::cout << "Constructor character called" << std::endl;
}

Character::Character(const Character& copy)
{
	this->_name = copy._name;
	*this = copy;
	std::cout << "Constructor copy character called" << std::endl;
}

const	std::string &Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return;
		}
	}
		
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, Character &target)
{
	if (idx < 4 && idx >= 0)
		this->_inventory[idx]->use(target);
}

Character	&Character::operator=(const Character& fix)
{
    if (this != &fix) {
        _name = fix._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i])
				delete _inventory[i];
            _inventory[i] = fix._inventory[i] ? fix._inventory[i]->clone() : NULL;
        }
    }
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete(_inventory[i]);
	}
	std::cout << "Destructor character called" << std::endl;
}
