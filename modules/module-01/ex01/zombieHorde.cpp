#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	Zombie *hordeZombies = new Zombie[N];
	for(int i = 0; i < N; i++)
		hordeZombies[i].setName(name);
	return (hordeZombies);
}