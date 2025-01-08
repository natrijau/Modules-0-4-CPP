#ifndef __ZOMBIE_H__
#define __ZOMBIE_H__
#include <iostream>

class Zombie
{
	private:
		std::string _name; 
	public:
		void	announce(void);
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void setName(std::string name);
};

Zombie *newZombie( std::string name );
Zombie *zombieHorde( int N, std::string name );
void 	randomChump( std::string name );

#endif