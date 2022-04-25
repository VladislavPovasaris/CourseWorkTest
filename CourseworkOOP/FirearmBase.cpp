#include "FirearmBase.h"

FirearmBase::FirearmBase()
{
	name = "No info";
	description = "No info";
	magazine_capacity = 0;
	amount_of_ammo = 0;
}
FirearmBase::FirearmBase(std::string name, std::string description, const Ammo &ammunition, int magazine_capacity, int amount_of_ammo)
{
	this->name = name;
	this->description = description;
	this->magazine_capacity = magazine_capacity;
	if (amount_of_ammo > magazine_capacity)
	{
		for (int i = 0; i < magazine_capacity; i++)
		{
			magazine.push(ammunition);
		}
		this->amount_of_ammo = amount_of_ammo - magazine_capacity;
	}
	else
	{
		for (int i = 0; i < amount_of_ammo; i++)
		{
			magazine.push(ammunition);
		}
		this->amount_of_ammo = 0;
	}
	this->ammunition = ammunition;
}
std::string FirearmBase::GetDescription()
{
	return description +"\n \n";
}

std::string FirearmBase::GetStats()
{	
	return "Name of the weapon: " + name + "\n" + "Ammo type: " + ammunition.GetAmmoName() + "\n" + "Ammo damage:" +
				std::to_string(ammunition.GetDamage()) + "\n" + "Magazine capacity: " + std::to_string(magazine_capacity) + " bullets" + "\n" +
				"Weapon condition: " + std::to_string(weapon_health) + "%" + "\n" + "\n";
}
std::string FirearmBase::Reload()
{
	if (amount_of_ammo)
	{
		int loaded = 0;
		if (amount_of_ammo > magazine_capacity)
		{
			for (int i = 0; i < magazine_capacity; i++)
			{
				magazine.push(ammunition);
				loaded++;
			}
		}
		else
		{
			for (int i = 0; i < amount_of_ammo; i++)
			{
				magazine.push(ammunition);
				loaded++;
			}
		}
		amount_of_ammo -= loaded;
		return "Reload complited \n \n";
	}
	else
	{
		return "Not enough ammo to reload \n \n";
	}
}
std::string FirearmBase::CheckMagazine()
{
	if (magazine.empty())
	{
		return "Mag is empty \n \n";
	}
	else
	{
		return "There are " + std::to_string(magazine.size()) + " rounds in the mag \n \n ";
	}
}
std::string FirearmBase::CheckAmmo()
{
	if (amount_of_ammo)
	{
		return std::to_string(amount_of_ammo) + " rounds left \n \n";
	}
	else
	{
		return "No ammo left \n \n";
	}
}
std::string FirearmBase::AddAmmo(int amount_of_ammo)
{
	this->amount_of_ammo += amount_of_ammo;
	return std::to_string(amount_of_ammo) + " rounds were added \n \n";
}

bool FirearmBase::operator==(const FirearmBase& other)
{
	if (this->name == other.name && this->ammunition == other.ammunition && this->magazine_capacity == other.magazine_capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool FirearmBase::operator >(const FirearmBase& other)
{
	Ammo temp = other.ammunition;
	if (this->ammunition.GetDamage() > temp.GetDamage() )
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool FirearmBase::operator <(const FirearmBase& other)
{
	Ammo temp = other.ammunition;
	if (this->ammunition.GetDamage() < temp.GetDamage())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool FirearmBase::comparator(const FirearmBase& other)
{
	return *this > other;
}

