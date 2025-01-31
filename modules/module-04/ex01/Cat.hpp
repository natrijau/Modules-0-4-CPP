#ifndef	__CAT_HPP__
#define	__CAT_HPP__

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:

		Brain*	_brain;

	public:

		Cat();
		Cat(const Cat& copy);
		~Cat();

		Cat	&operator=(const Cat& n);

		const	std::string getIdea(unsigned int i) const;
		
		void	makeSound() const;
		void	setIdea(std::string idea);
};

#endif