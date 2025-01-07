#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;
    zombie = newZombie("batman");
    zombie->announce();
    delete zombie;
    return (0);
}
