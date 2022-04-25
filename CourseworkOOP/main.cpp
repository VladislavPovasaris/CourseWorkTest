#include <iostream>
#include <string>
#include "Ammo.h"
#include "AutomaticRifle.h"
#include "Handgun.h"
using namespace std;

int main()
{
	Ammo* ammo9x19 = new Ammo("9x19", 11.3, 0.001);
	Handgun Glock17("Glock17", "That's a handgun", *ammo9x19, 10, 23);
	cout << Glock17.GetStats();
	cout << Glock17.ShootWholeMag();
	cout << Glock17.CheckAmmo();
	cout << Glock17.Reload();
	cout << Glock17.CheckAmmo();
	cout << Glock17.Shoot();
	cout << Glock17.CheckMagazine();
	cout << Glock17.GetStats();
	cout << Glock17.Shoot() << Glock17.Shoot();
	cout << Glock17.CheckMagazine();
	cout << Glock17.ShootWholeMag();
	cout << Glock17.CheckAmmo();
	cout << Glock17.CheckMagazine();
	cout << Glock17.Reload();
	cout << Glock17.ShootWholeMag();
	cout << Glock17.CheckMagazine();
	cout << Glock17.CheckAmmo();
	cout << Glock17.Shoot();
	cout << Glock17.ShootWholeMag();
	cout << Glock17.Reload();
	cout << "---------------------------------------------------------------------------------------------------------------" << endl << endl;
	Ammo* ammo5x56 = new Ammo("5,56x45 ", 20, 0.01);
	AutomaticRifle HK("HK416", "Gun", *ammo5x56, 30, 20);
	cout << HK.Shoot();
	cout << HK.CheckMagazine();
	cout << HK.GetStats();
	cout << HK.ShootWholeMag();
	cout << HK.Reload();
	cout << HK.CheckMagazine();
	cout << HK.CheckAmmo();
	cout << HK.AddAmmo(3);
	cout << HK.CheckMagazine();
	cout << HK.CheckAmmo();
	cout << HK.Reload();
	cout << HK.CheckMagazine();
	cout << HK.Shoot();
	cout << HK.CheckMagazine();
	cout << HK.ShootWholeMag();
	cout << HK.GetStats();
	cout << HK.CheckAmmo();
	cout << HK.Reload();

}