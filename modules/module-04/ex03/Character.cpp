#include	"Character.hpp"

Character::Character()
: 	ICharacter()
{
	_name = "default";
	for (size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (size_t i = 0; i < 100; i++)	
		_floor[i] = NULL;
	// std::cout << "Constructor default character called" << std::endl;
}

Character::Character(std::string name) : ICharacter()
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
	*this = copy;
	// std::cout << "Constructor copy character called" << std::endl;
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
				std::cout << this->_name << ": Impossible to equip because the Materia does not exist" << std::endl;
				return ;
			}
			this->_inventory[i] = m;
			std::cout << this->_name << ": Equip successfull of " << m->getType() <<  std::endl; 
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << "Impossible to unequip because Index its false" << std::endl;
		return ;
	}
	for(int i = 0; i < 100 ; i++)
	{
		if(_floor[i] == NULL)
		{
			_floor[i] = this->_inventory[idx];
			std::cout << _name << ": "<< _inventory[idx]->getType() << " is successfully unequipped" << std::endl;
			break;
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
		std::cout << this->_name << ": Impossible to use because not Materia at index " << idx <<  std::endl;
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
        for (int i = 0; i < 4; i++) {
            if (_floor[i])
				delete _floor[i];
            _floor[i] = fix._floor[i]->clone();
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
