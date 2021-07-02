#include "pch.h"
#include <iostream>

struct GridObject
{
	int x=8,y=5;
	void Run(char seed)
	{
					
		if (seed == 'w' || seed == 'W')

		{
			if (y != 0)
			{
				y -= 1;
			}
		}
	
		else if (seed == 's' || seed == 'S')
		{
			if (y != 9)
			{
				y += 1;
			}
		}

		else if (seed == 'a' || seed == 'A')
		{
			if(x!=0)
			{ 
				x -= 1;
			}
		}

		else if (seed == 'd' || seed == 'D')
		{
			if (x != 14)
			{
				x += 1;
			}
		}

		else
		{
			;
		}
	}
};
struct Grid
{
	int length=10,width=15;
	void Render(GridObject player)
	{
		char gridChar = 254;
		char playerChar = 198;
		for (int i = 0; i < length; i++) 
		{
			for (int j = 0; j < width; j++)
			{
				if (j == player.x && i == player.y)
				{
					std::cout << playerChar;
				}
				else
				{
					std::cout << gridChar;
				}
			}
			std::cout << std::endl;
		}
		std::cout << "\n[W]:Up  [S]:Down  [A]:Left  [D]:Right  [Q]:Quit";

	}
};
struct Selection
{
	char GetSelect()
	{
		char select;
		std::cin >> select;
		return select;
	}
}; 

int main()
{
	char player_input;
	bool quitGame = false;

	GridObject player;
	Grid grid;
	Selection select;

	while (quitGame == false)
	{
		grid.Render(player);
		player_input = select.GetSelect();
		player.Run(player_input);

		if (player_input == 'q' || player_input == 'Q')
		{
			quitGame = true;
		}
	}
}
