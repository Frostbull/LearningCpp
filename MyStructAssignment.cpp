#include "pch.h"
#include<iostream>

struct Katana
{//Simple Katana type, with a name, damage stats, range stats,enemyDistance doesn't make alot sense
//but it's a means to an end to check wether the weapon hits or not, and a simple enchant status
	char name[64] = "no name";
	int damage = 0;
	int reach = 0;
	int enemyDistance=0;
	bool isHit=false;
	bool isEnchanted = false;

	void Enchant()
	{
		//Permanently adds damage to a weapon
		std::cout << name << " is now enchanted with fire!\n";
		isEnchanted = true;
		damage += 5;
	}



	void SetEnemyDistance(int setter)
	{//Called with a parameter used to check if enemy is in range for the attack
		enemyDistance = setter;
	}
	bool IsHit()
	{//Hit or Miss i guess he doesn't miss huh!
		if (reach >= enemyDistance) {//Migoto!
			std::cout << "Hit!\n";
			return isHit = true;
		}
		else
		{//Unko!, yeah if you miss you don't deal damage, still needs a function to default damage back...
			damage *= 0;
			std::cout << "Miss!\n";
			return isHit = false;
		}
	}
	void Crit(float critical)
	{//Hits for double damage
		if (critical < 100 && critical>50&&isHit==true)
		{
			std::cout << "You landed a critical Hit!\n";
			damage *= 2;
		}
	}
	void Damage()
	{
		//called to inform how much damage was dealt, so it's only called after IsHit() gets called
		std::cout << "You have dealt " << damage << " damage\n";
		
	}

	void MakeDefault()
	{
		//called to default a weapon's damage back to normal ,so only after Crit(n) is called with 50<n<100
		damage /= 2;
	}
};



int main()
{
	Katana Ninjato{"Ninjato",70,3,0,false,false};
	Ninjato.SetEnemyDistance(2);
	Ninjato.IsHit();
	Ninjato.Crit(0);
	Ninjato.Damage();
	Ninjato.MakeDefault();


	Ninjato.Enchant();
	Ninjato.IsHit();
	Ninjato.Crit(55);
	Ninjato.Damage();
	Ninjato.MakeDefault();

	Katana Nodachi{ "Nodachi",90,5,0,false,false };
	Nodachi.Enchant();
	Nodachi.SetEnemyDistance(5);
	Nodachi.IsHit();
	Nodachi.Crit(83);
	Nodachi.Damage();
	Nodachi.MakeDefault();

	Nodachi.IsHit();
	Nodachi.Crit(40);
	Nodachi.Damage();

	bool outtahere;
	std::cin >> outtahere;
}


