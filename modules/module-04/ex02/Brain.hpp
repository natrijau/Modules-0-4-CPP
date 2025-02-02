#ifndef	__BRAIN_HPP__
#define	__BRAIN_HPP__

#include	<iostream>

class Brain
{
	private:

		std::string	ideas[100];
	
	public:

		Brain();
		Brain(const Brain& copy);
		~Brain();

		Brain	&operator=(const Brain& fix);

		const std::string getIdea(unsigned int i) const;
		void	setIdea(std::string idea);
};

#endif