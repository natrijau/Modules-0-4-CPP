#ifndef __WEAPON_H__
#define __WEAPON_H__
#include 	<string>

class Weapon
{
	private:
		std::string _weapon;
	public:
		const	std::string& getType() const;
		void	setType(const std::string& type);
		Weapon(const std::string& type);
		~Weapon();
};

#endif