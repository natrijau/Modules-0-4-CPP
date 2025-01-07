#include "Zombie.hpp"
#include <memory>   

Zombie *newZombie(std::string name)
{
    Zombie *zombie;
    zombie = new Zombie(name);
    // std::cout << "Address: " << zombie << std::endl;
    // std::cout << "(value ptr)zombie created" << name;
    return (zombie);
}
