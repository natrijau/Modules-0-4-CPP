#include	"MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Constructor MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	std::cout << "Constructor copy MateriaSource called" << std::endl;
    for (int i = 0; i < 4; i++)
	{
        if (copy._inventory[i])
            _inventory[i] = copy._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		delete(this->_inventory[i]);
	std::cout << "Destructor MateriaSource called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* toCopy)
{
	if (!toCopy)
		return ;	
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = toCopy;
			return ;
		}
	}
	std::cout << "Inventory full, cannot learn more Materia!" << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 3; i >= 0; i--)
	{
		if(this->_inventory[i])
		{
			if (this->_inventory[i]->getType() == type)
				return (_inventory[i]->clone());
			else
				break;
		}
	}
	return (NULL);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &fix)
{
	for (size_t i = 0; i < 4; i++)
	{
		delete(_inventory[i]);
		if (fix._inventory[i])
			_inventory[i] = fix._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return (*this);
}
