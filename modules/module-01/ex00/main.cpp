#include "Zombie.hpp"

int main(void)
{
	Zombie *zombie;

	zombie = newZombie("Batman");
	zombie->announce();
	randomChump("Robin");
	delete zombie;
	return (0);
}
