#include "pch.h"
#include <iostream>

//Simple Weapon type
struct Sword
{
	char name[64] = "no name";
	float attack = 0;
	int enchantCharges = 0;
	int durability = 0;
	bool isEnchanted = false;
	
	
	//happens on a trigger(like a press of a button)
	void Enchant()
	{
		IsEnchanted();
		std::cout << name << " is now enchanted with fire\n";
		enchantCharges = 5;
	}
	//Happens everytime an attack or enchant happens
	void IsEnchanted()
	{
		if (enchantCharges > 0)
		{
			isEnchanted = true;
		}
		else
		{
			isEnchanted = false;
		}
	}


	//happen on a trigger(like a button press), should involve some rng 
	void DoubleDamage()
	{
		if(durability>0)
		{ 
			IsEnchanted();
			if (isEnchanted)
			{ 
				std::cout << "your strike dealt double damage and additional fire damage! " << (attack + 5) * 2 << std::endl;
				enchantCharges--;
				durability--;
				std::cout << name << "'s durability went down!\n";
				Durability();
			}
			else
			{
				std::cout << "your strike dealt double damage! " << attack * 2 << std::endl;
				durability--;
				std::cout << name << "'s durability went down!\n";
				Durability();

			}
		}
		else
		{
			std::cout << "you can't attack; your weapon is blunt! damage dealt " << attack * 0 << std::endl;
		}
	}
	void NormalDamage()
	{
		if(durability>0)
			{ 
			IsEnchanted();
			if (isEnchanted)
		{
			std::cout << "you landed a hit and additional fire damage! " << attack+5<< std::endl;
			enchantCharges--;
			durability--;
			std::cout << name << "'s durability went down!\n";
			Durability();

		}
			else
			{
				std::cout << "you landed a hit! " << attack << std::endl;
				durability--;
				std::cout << name << "'s durability went down!\n";
				Durability();

			}
		}
		else
		{
			std::cout << "you can't attack; your weapon is blunt! damage dealt " << attack * 0 << std::endl;

		}
	}
	void Whiff()
	{
		if(durability>0)
			{ 
			IsEnchanted();
			std::cout << "your attack whiffed " << attack * 0 << std::endl;
			if(enchantCharges>0)
			{
				enchantCharges--;
			}
		}
		else
		{
			std::cout << "you can't attack; your weapon is blunt! damage dealt " << attack * 0 << std::endl;

		}
	}

	//part of the game loop and should always be displayed ;it goes down on each attack that lands
	void Durability()
	{
		char box = 254;
		std::cout << "Durability : ";
		for (int i=durability;i>0;i--)
		{
			std::cout << box;
		}
		std::cout << std::endl;
	}
	//a function that sets durability back up
	void Sharpen()
	{
		durability = 5;
		std::cout << "you sharpened " << name << " durability up!\n";
		Durability();
	}
	
};


int main()
{	//creating Gladius
	Sword Gladius{ "Gladius",50,0,3,false };

	//enchanting it
	Gladius.Enchant();
	Gladius.Durability();

	//attack enough times to consume the enchant and durability
	Gladius.DoubleDamage();
	Gladius.Whiff();
	Gladius.NormalDamage();
	Gladius.NormalDamage();
	Gladius.Whiff();
	
	std::cout << "\n\n\n";

	//checking the difference in dammage
	Gladius.NormalDamage();
	Gladius.DoubleDamage();
	//Sharpen call
	Gladius.Sharpen();
	Gladius.NormalDamage();

}