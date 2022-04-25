#pragma once
#include "FirearmBase.h"
class Automatic : public FirearmBase
{
public:
	Automatic();
	Automatic(std::string name, std::string description, const Ammo ammunition, int magazine_capacity, int amount_of_ammo);

	std::string ShootWholeMag() override;
	std::string Shoot() override;
};

