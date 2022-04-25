#pragma once
#include "Iweapon.h"
#include "Ammo.h"
#include <string>
#include <iostream>
#include <stack>
class FirearmBase : public Iweapon
{
protected:
	std::string name;
	std::string description;
	Ammo ammunition;
	int magazine_capacity;
	std::stack<Ammo> magazine;
	int amount_of_ammo;
	double weapon_health = 100.0;

public:
	FirearmBase();
	FirearmBase(std::string name, std::string description, const Ammo &ammunition, int magazine_capacity, int amount_of_ammo);
	std::string GetDescription() override;
	std::string GetStats() override;
	virtual std::string ShootWholeMag() = 0;
	virtual std::string Shoot() = 0;
	std::string Reload();
	std::string CheckMagazine();
	std::string CheckAmmo();
	std::string AddAmmo(int amount_of_ammo);
	bool operator ==(const FirearmBase &other);
	bool operator >(const FirearmBase& other);// according to the power of the ammunition 
	bool operator <(const FirearmBase& other);// according to the power of the ammunition
	bool comparator(const FirearmBase& other);// decides which one is more powerfull
};

