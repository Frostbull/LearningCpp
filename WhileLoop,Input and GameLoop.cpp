#include "pch.h"
#include <iostream>

struct Selection
{
	char GetSelection()
	{
		char choice;
		std::cout << "\n[W] Go Up\n[S] Go Down\n[A] Go Left\n[D] Go Right\n[Q] Quit\nPlease select: ";
		std::cin >> choice;

		return choice;
	}
};
struct Update
{
	int x = 0, y = 0;
	void Run(char choice)
	{
		if (choice == 'w' || choice=='W')
		{
			y+= 1;
			std::cout << "*** MOVE NORTH ***\nx:" << x << " y:" << y << std::endl;
			
		}
	
		else if (choice == 's' || choice=='S')
		{
			y -= 1;
			std::cout << "*** MOVE SOUTH ***\nx:" << x << " y:" << y << std::endl;

		}

		else if (choice == 'a' || choice=='A')
		{
			x -= 1;
			std::cout << "*** MOVE WEST ***\nx:" << x << " y:" << y << std::endl;

		}

		else if (choice == 'd' || choice=='D')
		{
			x += 1;
			std::cout << "*** MOVE EAST ***\nx:" << x << " y:" << y << std::endl;

		}

		else if (choice == 'q' || choice=='Q')
		{
			std::cout << "See you next time!";
		}

		else
		{
			std::cout << "*** INVALID ***\nx:" << x << " y:" << y << std::endl;
		}
	}
};

int main()
{
	char c;
	bool gameQuit = false;
	Selection sel;
	Update update;

	while (gameQuit == false)
	{
		c = sel.GetSelection();
		update.Run(c);

		if (c=='q' ||c=='Q')
		{
			gameQuit = true;
		}
	}
}