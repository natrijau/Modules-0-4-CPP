#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;
	Zombie *hordeZombie;

	zombie = newZombie("Batman");
	zombie->announce();
	randomChump("Robin");
	hordeZombie = zombieHorde(7, "Joker");
	for(int i = 0; i < 7; i++)
		hordeZombie[i].announce();
	delete zombie;
	delete [] hordeZombie;

	return (0);
}
