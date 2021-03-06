#include "pch.h"
#include <iostream>

enum class GameState
{
	MENU=1,
	GRID,
	ENEMY,
	ITEM,
	VICTORY,
	DEFEAT,
	EXIT,
};

GameState currentstate=GameState::MENU;

struct GridObject
{
	int x, y, hp, attack;
	char GetInput()
	{
		char playerInput;
		std::cin >> playerInput;
		return playerInput;
	}
	void PositionUpdate(char input)
	{
		if (input == 'z' || input == 'Z')
		{
			if(y!=0) {y -= 1;}
		}
	
		else if (input == 's' || input == 'S')
		{
			if (y != 9) { y += 1; }
		}

		else if (input == 'q' || input == 'Q')
		{
			if (x != 0) { x -= 1; }
		}

		else if (input == 'd' || input == 'D')
		{
			if (x != 9) { x += 1; }
		}
	}
	void init(GridObject &player, GridObject &enemy)
	{
		player.hp = 10;
		player.attack = 2;
		player.x = 2;
		player.y = 2;
		enemy.hp = 20;
		enemy.attack = 2;
		enemy.x = 6;
		enemy.y = 3;
	}
};

//Rendering:
struct Render
{	//The Grid
	int length, width;
	void DrawGrid(GridObject player, GridObject enemy, GridObject item)
	{
		char playerChar = 'P';
		char itemChar = 'I';
		char enemyChar = 'E';
		char gridChar=254;
		
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (i == player.y && j == player.x)
				{
					std::cout << playerChar;
				}
				else if (i == enemy.y && j == enemy.x)
				{
					std::cout << enemyChar;
				}
				else if (i == item.y && j == item.x)
				{
					std::cout << itemChar;
				}

				else
				{
					std::cout << gridChar;
				}

			}
			std::cout << std::endl;
		}
		std::cout << "\n\n[Z] : Move Up\t[S] : Move Down\t[Q] : Move Left\t[D] : Move Right\n";	
	}
	//Menu
	void DrawMenu(GridObject player)
	{
		std::cout << "\n\n\t\t\tONLY THE WORTHY SURVIVES!\n";
		std::cout << "\n\n\n\n\n\t\t\t   __ _ _   _ _ __  ___ \n";
		std::cout << "\t\t\t  / _` | | | | '_ \\/ __|\n";
		std::cout << "\t\t\t | (_| | |_| | | | \\__ \\\n";
		std::cout << "\t\t\t  \\__, |\\__,_|_| |_|___/\n";
		std::cout << "\t\t\t  |___/\n";
		std::cout << "\n\n\n\n\n  [1] : Start Game\t\t\t\t\t\t[2] : Exit\n";
	}
	//Weapon Encounter
	void DrawGun(GridObject player)
	{
		std::cout << "\n\n\t\tYOU FOUND A GLOCK ON THE GROUND!\n";
		std::cout << "\n\n\n\n\t\t\t+--^----------,--------,-----,--------^-,\n";
		std::cout << "\t\t\t| |||||||||   `--------'     |          O\n";
		std::cout << "\t\t\t`+---------------------------^----------|\n";
		std::cout << "\t\t\t  `\\_,---------,---------,--------------'\n";
		std::cout << "\t\t\t    / XXXXXX /'|       /'\n";
		std::cout << "\t\t\t   / XXXXXX /  `\\    /'\n";
		std::cout << "\t\t\t  / XXXXXX /`-------'\n";
		std::cout << "\t\t\t / XXXXXX /\n";
		std::cout << "\t\t\t/ XXXXXX /\n";
		std::cout << "\t\t\t(________(\n";
		std::cout << "\t\t\t `------' \n";
		std::cout << "\n\n\n\n[1] : Pick Up\t\t\t\t\t\t[2] : Do Nothing\n";
	}
	//Player & Enemy Healthbar(Not a game state)
	void DrawPlayerHp(GridObject player)
	{
		std::cout << "Your HP : ";
		for (int i = 0; i < player.hp; i++)
		{
			std::cout << (char)175;
		}
		std::cout << "\n";
	}
	void DrawEnemyHp(GridObject enemy)
	{
		std::cout << "Enemy HP : ";
		for (int i = 0; i < enemy.hp; i++)
		{
			std::cout << (char)175;
		}
		std::cout << "\n";
	}
	//Enemy Encounter
	void DrawEnemy(GridObject player,GridObject enemy)
	{
		std::cout << "\n\n\t\t\tA WILD SKELETON APPEARED!!!!!\n\n\n";
		std::cout << "                              _.--\"\"-._\n";
		std::cout << "  .                         .\"         \".\n";
		std::cout << " / \\    ,^.         /(     Y             |      )\\\n";
		std::cout << "/   `---. |--'\\    (  \\__..'--   -   -- -'\"\"-.-'  )\n";
		std::cout << "|        :|    `>   '.     l_..-------.._l      .'\n";
		std::cout << "|      __l;__ .'      \" - .__. || _. - 'v' - ._ || `\"--- - \"\n";
		std::cout << " \\  .-' | |  `              l._       _.'\n";
		std::cout << "  \\/    | |                   l`^^'^^'j\n";
		std::cout << "        | |                _   \\_____/     _\n";
		std::cout << "        j |               l `--__)-'(__.--' |\n";
		std::cout << "        | |               | /`---``-----'\"1 | , ---- - .\n";
		std::cout << "        | |               )/  `--' '---'   \'-'  ___  `-.\n";
		std::cout << "        | |              //  `-'  '`----'  /  ,-'   I`.  \\\n";
		std::cout << "      _ L |_            //  `-.-.'`-----' /  /  |   |  `. \\\n";
		std::cout << "     '._' / \\         _/(   `/   )- ---' ;  /__.J   L.__.\\ :\n";
		std::cout << "      `._;/7(-.......'  /        ) (     |  |            | |\n";
		std::cout << "      `._;l _'--------_/        )-'/     :  |___.    _._./ ;\n";
		std::cout << "        | |                 .__ )-'\\  __  \  \  I   1   / /\n";
		std::cout << "        `-'                /   `-\\-(-'   \ \  `.|   | ,' /\n";
		std::cout << "                           \\__  `-'    __/  `-. `---'',-'\n";
		std::cout << "                              )-._.-- (        `-----'\n";
		std::cout << "                             )(  l\\ o ('..-.\n";
		std::cout << "                       _..--' _'-' '--'.-. |\n";
		std::cout << "                __,,-'' _,,-''            \\ \\\n";
		std::cout << "               f'. _,,-'                   \\ \\\n";
		std::cout << "              ()--  |                       \\ \\\n";
		std::cout << "                \\.  |                       /  \\\n";
		std::cout << "                  \\ \\                      |._  |\n";
		std::cout << "                   \\ \\                     |  ()|\n";
		std::cout << "                    \\ \\                     \\  /\n";
		std::cout << "                     ) `-.                   | |\n";
		std::cout << "                    // .__)                  | |\n";
		std::cout << "                 _.//7'                      | |\n";
		std::cout << "               '---'                         j_| `\n";
		std::cout << "                                            (| |\n";
		std::cout << "                                             |  \\\n";
		std::cout << "                                             |lllj\n";
		std::cout << "                                             |||||\n\n\n\n";
		std::cout << "\t\t [1] : Attack\t\t [2] : Taunt!\n\n\n";
		DrawPlayerHp(player);
		std::cout << std::endl;
		DrawEnemyHp(enemy);
	}
	//Game Outcome
	void DrawDefeatScreen(GridObject player)
	{
		std::cout << "\n\n\n\t\t\t\tYOU DIED\n\n\n\n\t[1] : Retry\t\t\t\t\t[2]: Main Menu\n";
	}
	void DrawVictoryScreen(GridObject player)
	{
		std::cout << "\n\n\n\t\tYOU PROVED YOU ARE WORTHY AND SURVIVED\n\n\n\t[1] : Play Again\t\t\t[2]: Main Menu\n";
	}
};

//LOGIC
struct Logic
{//transitions
	void GridToEncounter(GridObject player, GridObject enemy,GridObject item )
	{
		if (player.x == enemy.x && player.y == enemy.y)
		{
			currentstate = GameState::ENEMY;
		} 
		else if (player.x == item.x && player.y == item .y)
		{
			currentstate = GameState::ITEM;
		}

	} 
	void ItemToGrid(char input,GridObject &player)
	{	
		
		if (input == '1')
		{
			player.attack += 5;
			currentstate = GameState::GRID;
		}
		else if (input == '2')
		{
			currentstate = GameState::GRID;
		}

	} 
	void Combat(char input, GridObject &player, GridObject &enemy)
	{
		
		
		if (input == '1')
		{
			player.hp -= enemy.attack;
			enemy.hp -= player.attack;
		}
			else if (input == '2')
		{
			enemy.attack *= 2;
			player.hp -= enemy.attack;
		}
		
	} 
	void IsCombatOver(GridObject& player, GridObject& enemy)
	{
		if (player.hp <= 0)
		{
			currentstate=GameState::DEFEAT;
		}
		else if (enemy.hp <= 0)
		{
			currentstate=GameState::VICTORY;
		}

	}
	void Menu_Grid_Exit(char input,GridObject player)
	{
		if (input == '1')
		{
			currentstate = GameState::GRID;
		}
		else if (input == '2')
		{
			currentstate = GameState::EXIT;
		}

	} 
	void DefeatToMenu(GridObject player)
	{
		char input = player.GetInput();
		if (input == '1')
		{
			currentstate = GameState::GRID;
		}
		else if (input == '2')
		{
			currentstate = GameState::MENU;
		}

	} 
	void VictoryToMenu(GridObject player)
	{
		char input = player.GetInput();
		if (input == '1')
		{
			currentstate = GameState::GRID;
		}
		else if (input == '2')
		{
			currentstate = GameState::MENU;
		}


	} 
	void Run()
	{
		GridObject player{ 2,2,10,2 }, enemy{ 6,3,20,2 }, item{ 3,8,0,0 };
		Render game{ 10,10 };
		Logic transition;

		bool gameQuit = false;
		while (gameQuit == false)
		{
			if (currentstate == GameState::MENU)
			{
				player.init(player, enemy);
				game.DrawMenu(player);
				transition.Menu_Grid_Exit(player.GetInput(), player);
			}
			else if (currentstate == GameState::GRID)
			{
				game.DrawGrid(player, enemy, item);
				player.PositionUpdate(player.GetInput());
				transition.GridToEncounter(player, enemy, item);

			}
			else if (currentstate == GameState::ENEMY)
			{
				game.DrawEnemy(player, enemy);
				transition.Combat(player.GetInput(), player, enemy);
				transition.IsCombatOver(player, enemy);
			}
			else if (currentstate == GameState::VICTORY)
			{
				player.init(player, enemy);
				game.DrawVictoryScreen(player);
				transition.VictoryToMenu(player);

			}
			else if (currentstate == GameState::DEFEAT)
			{
				player.init(player, enemy);
				game.DrawDefeatScreen(player);
				transition.DefeatToMenu(player);
			}
			else if (currentstate == GameState::ITEM)
			{
				game.DrawGun(player);
				transition.ItemToGrid(player.GetInput(), player);
			}
			else if (currentstate == GameState::EXIT)
			{
				gameQuit = true;
			}
		}
		;
	}
};

int main()
{	
	Logic game;
	game.Run();
}












	




