#include	"Character.hpp"

Character::Character()
{
	_name = "default";
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (size_t i = 0; i < 100; i++)	
		_floor[i] = NULL;
	// std::cout << "Constructor default character called" << std::endl;
}

Character::Character(std::string name)
{
	_name = name;
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (size_t i = 0; i < 100; i++)
		_floor[i] = NULL;
	// std::cout << "Constructor character called" << std::endl;
}

Character::Character(const Character& copy)
{
	this->_name = copy._name;
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = copy._inventory[i] ? copy._inventory[i] : NULL;
	// std::cout << "Constructor copy character called" << std::endl;
}

const	std::string &Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (this->_inventory[3])
	{
		std::cout << this->getName() << ": Inventory is full" << std::endl;
		return ;
	}
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			if(m == NULL)
			{
				std::cout << this->_name << ": Impossible to equip because the Materia does not exist" << std::endl;
				return ;
			}
			this->_inventory[i] = m->clone();
			std::cout << this->_name << ": Equip successfull of " << m->getType() <<  std::endl; 
			delete m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && !this->_inventory[idx])
	{
		std::cout << "Impossible to unequip because Materia at index " << idx << " does not exist" << std::endl;
		return ;
	}
	if (idx > 3 || idx < 0)
	{
		std::cout << "Impossible to unequip because Index its false" << std::endl;
		return ;
	}
	if (_floor[99] != NULL)
	{
		std::cout << _name << ": array _floor is full. Impossible to unequip " << this->_inventory[idx] << std::endl;
		return ;
	}
	for(int i = 0; i < 100 ; i++)
	{
		if(_floor[i] == NULL)
		{
			_floor[i] = this->_inventory[idx];
			std::cout << _name << ": "<< _inventory[idx]->getType() << " is successfully unequipped" << std::endl;
			this->_inventory[idx] = NULL;
			break;
		}
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 4 && idx >= 0 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << this->_name << ": Impossible to use because not Materia at index " << idx <<  std::endl;
}

Character	&Character::operator=(const Character& fix)
{
    if (this != &fix) {
        _name = fix._name;
        for (int i = 0; i < 4; i++)
		{
			delete _inventory[i];
            _inventory[i] = fix._inventory[i] ? fix._inventory[i]->clone() : NULL;
        }
        for (int i = 0; i < 4; i++)
		{
			delete _floor[i];
            _floor[i] = fix._floor[i] ? fix._floor[i]->clone() : NULL;
        }		
    }
	return (*this);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			std::cout << _name << ": delete _inventory " << _inventory[i]->getType() << std::endl;
			delete(_inventory[i]);
		}
	}
	for(int i = 0; i < 100 ; i++)
	{
		if(_floor[i])
		{
			std::cout << _name << ": delete _floor " << _floor[i]->getType() << std::endl;
			delete(_floor[i]);
		}
	}
	// std::cout << "Destructor character called" << std::endl;
}
