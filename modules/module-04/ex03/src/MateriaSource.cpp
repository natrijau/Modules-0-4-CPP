#include	"MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(size_t i = 0; i < 4; i++)
		_inventory[i] = NULL;
	// std::cout << "Constructor MateriaSource called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	// std::cout << "Constructor copy MateriaSource called" << std::endl;
    for (int i = 0; i < 4; i++)
		_inventory[i] = copy._inventory[i] ? copy._inventory[i]->clone() : NULL;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if(this->_inventory[i])
			delete(this->_inventory[i]);
	}
	// std::cout << "Destructor MateriaSource called" << std::endl;
}

void	MateriaSource::learnMateria(AMateria* toCopy)
{
	if (!toCopy)
		return ;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			std::cout << "Materia " << toCopy->getType() << " learned" << std::endl;
			this->_inventory[i] = toCopy->clone();
			delete toCopy;
			return ;
		}
	}
	delete toCopy;
	std::cout << "Inventory full, cannot learn more Materia!" << std::endl;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	if (type != "cure" && type != "ice")
	{
		std::cout << "Impossible to creat Materia " << type << " because this Materia type does not exist" << std::endl;
		return (NULL);
	}
	for (int i = 3; i >= 0; i--)
	{
		if(this->_inventory[i])
		{
			if (this->_inventory[i]->getType() == type)
			{
				std::cout << "Materia " << type << " created" << std::endl;
				return (_inventory[i]->clone());
			}
		}
	}
	if (type == "cure" || type == "ice")
		std::cout << "Impossible to creat Materia " << type << " because this Materia is not learned or _inventory is full" << std::endl;
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
