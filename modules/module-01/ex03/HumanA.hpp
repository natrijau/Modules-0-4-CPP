#ifndef __HUMANA_H__
#define __HUMANA_H__
#include	"Weapon.hpp"
#include 	<string>
#include 	<iostream>

class HumanA
{
	private:
		std::string _name;
		Weapon& weapon;
	public:
		void	attack() const;
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();
};

#endif