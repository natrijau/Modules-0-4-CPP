#include	"Brain.hpp"

Brain::Brain()
{
	std::cout << "Constructor Brain called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor Brain called" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Copy constructor Brain called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

Brain	&Brain::operator=(const Brain& fix)
{
	std::cout << "operator '='" << std::endl;
	if (this == &fix)
		return (*this);
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = fix.ideas[i];
	return (*this);
}

const	std::string Brain::getIdea(unsigned int i) const
{
	if (i > 99)
	{
		std::cout << "non valid id of idea" << std::endl;
		return (NULL);
	}
	return (this->ideas[i]);
}

void	Brain::setIdea(std::string	idea)
{
	for (size_t i = 0; i < 100; i++)
	{
		if (this->ideas[i].empty())
		{
			this->ideas[i] = idea;
			std::cout << "You add an idea" << std::endl;
			break ;
		}
		if (i == 99 && this->ideas[i].empty())
		{
			std::cout << "Brain is full !!!!" << std::endl;
			break ;
		}
	}
}
