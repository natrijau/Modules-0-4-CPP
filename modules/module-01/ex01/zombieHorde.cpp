#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	// (std::nothrow) in case the malloc does not work, initialize to null
	Zombie *hordeZombies = new(std::nothrow) Zombie[N];
	if(!hordeZombies)
		return (NULL);
	for(int i = 0; i < N; i++)
		hordeZombies[i].setName(name);
	return (hordeZombies);
}