#include "Handgun.h"

Handgun::Handgun() : NonAutomatic()
{
}

Handgun::Handgun(std::string name, std::string description, const Ammo ammunition, int magazine_capacity, int amount_of_ammo) : NonAutomatic(name, description, ammunition, magazine_capacity, amount_of_ammo)
{
}

std::string Handgun::ShootWholeMag()
{
	if (weapon_health > 0 && magazine.size() > 0)
	{
		double total_damage = 0;
		int size = magazine.size();
		for (int i = 0; i < size - 1; i++)
		{
			total_damage += ammunition.GetDamage();
			std::cout << "Boom *pause* ";
			weapon_health -= ammunition.GetDamageToWeapon() * 0.1;
			magazine.pop();
		}
		total_damage += ammunition.GetDamage();
		std::cout << "Boom" << std::endl << std::endl;
		magazine.pop();
		return std::to_string(total_damage) + " damage done\n \n";
	}
	else if (weapon_health <= 0)
	{
		return "Weapon is broken \n \n";
	}
	else if (magazine.size() == 0)
	{
		return "No ammo in magazine \n \n";
	}
}

