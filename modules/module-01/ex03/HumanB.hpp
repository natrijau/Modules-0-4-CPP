#ifndef __HUMANB_H__
#define __HUMANB_H__
#include	"Weapon.hpp"
#include 	<string>
#include 	<iostream>

class HumanB
{
	private:
		std::string _name;
		Weapon* weapon;
	public:
		void attack() const;
		void setWeapon(Weapon& weapon);
		HumanB(const std::string& name);
		~HumanB();
};

#endif