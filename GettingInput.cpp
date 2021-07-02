#include "pch.h"
#include <iostream>

struct Friends
{
	char name[16]="111-1111-1111";
	char phoneNumber[16]="111-1111-1111";
	void AddFriend(int seed, Friends friendList[])
	{
		std::cout << "enter your friend's name\n";
		std::cin >> friendList[seed].name;
		std::cout << std::endl;
		std::cout << "enter your friend's phone number\n";
		std::cin >> friendList[seed].phoneNumber;
		std::cout << std::endl;
	}
	void ShowFriendList(int seed, Friends friendList[])
	{
		std::cout << friendList[seed].name << " : " << friendList[seed].phoneNumber << std::endl;
	}
};

int main()
{
	Friends friend1, friend2, friend3, friend4, friend5;
	Friends friendList[]{ friend1,friend2,friend3,friend4,friend5 };
	for (int i = 0; i < 5; i++)
	{
		friendList->AddFriend(i, friendList);
	}
	for (int i = 0; i < 5; i++)
	{
		friendList->ShowFriendList(i, friendList);
	}
}
