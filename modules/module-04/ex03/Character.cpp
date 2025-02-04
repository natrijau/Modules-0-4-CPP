#include	"Character.hpp"

Character::Character(std::string name)
:	_name(name)
{
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (size_t i = 0; i < 100; i++)
		_floor[i] = NULL;
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
			if(m == NULL)
			{
				std::cout << "Impossible to equip because Materia dont exist" << std::endl;
				return ;
			}
			this->_inventory[i] = m;
			std::cout << "equip successfull of " << m->getType() <<  std::endl; 
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 4 && idx >= 0)
	{
		for(int i = 0; i < 100 ; i++)
		{
			if(_floor[i] == NULL)
			{
				_floor[i] = this->_inventory[idx];
				break;
			}
		}
	}
	if (idx < 4 && idx >= 0)
		this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && idx >= 0 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "Impossible to use because not Materia at index " << idx <<  std::endl;
}

Character	&Character::operator=(const Character& fix)
{
    if (this != &fix) {
        _name = fix._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i])
				delete _inventory[i];
            _inventory[i] = fix._inventory[i]->clone();
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
	for(int i = 0; i < 100 ; i++)
	{
		if(_floor[i])
			delete(_floor[i]);
	}
	std::cout << "Destructor character called" << std::endl;
}
