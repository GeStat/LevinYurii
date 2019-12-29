#include"Game.h"
#include<iostream>

Game::Game()
{
	packman = new Packman();
	/*for (int i = 0; i < 4; ++i)
	{
		ghost[i] = new Ghost(this);
		pellet[i] = new Pellet(this);
	}*/
}
Game::~Game()
{
	delete packman;
	for (int i = 0; i < 4; ++i)
	{
		delete ghost[i];
		delete pellet[i];
	}
}
void Game::start()
{
	while (true)
	{
		startLoop();
	}
}

void Game::startLoop()
{
	packman->setScore(0);
	packman->setLives(3);
	bool gameOver = false;
	loadField();

}

void Game::loadField()
{
	char fieldMap[FIELD_WIDTH][FIELD_HEIGHT] = {
	"+*****************************+",
	"| $$       $$$$$$$     $$$$   |",
	"|     1                       |",
	"|$$$ $$$$$$$$$$ $$   $$$$$$$$$|",
	"|   |                         |",
	"| | |$$$ |  |           | 2   |",
	"| |      |  | |$$$  |   |  |  |",
	"| | $$$$$|  | | M    $$ |     |",
	"| |           |$$$  |      |  |",
	"| |$$$$$ $$$         $$       |",
	"|   3      $$$$$$  $$$$$$$ $$$|",
	"|                             |",
	"|$ $$$ $$$$      $$$   $$$$$$$|",
	"|  $      $$$           4     |",
	"|             $$$             |",
	"| $$          X       $$$$$$$ |",
	"|       $$                    |",
	"+*****************************+"
	};

	char currentChar;

	for (int y = 0; y < FIELD_HEIGHT; ++y)
	{
		for (int x = 0; x < FIELD_WIDTH; ++x)
		{
			currentChar = fieldMap[x][y];

			switch (currentChar)
			{
			case '+':
				field_[y][x] = '+';
				break;
			case 'X':
				packman->setYInit(y);
				packman->setXInit(x);
				field_[y][x] = ' ';
				break;
			case '*':
				field_[y][x] = '*';
				break;
			case 'M':
				ghost[0]->setYInit(y);
				ghost[0]->setXInit(x);
				field_[y][x] = ' ';
				break;
			case '1':
				pellet[0]->setY(y);
				pellet[0]->setX(x);
				field_[y][x] = 'o';
				packman->setLeftFruit(packman->getLeftFruit() + 1);
				break;
			case '2':
				pellet[1]->setY(y);
				pellet[1]->setX(x);
				field_[y][x] = 'o';
				packman->setLeftFruit(packman->getLeftFruit() + 1);
				break;
			case '3':
				pellet[2]->setY(y);
				pellet[2]->setX(x);
				field_[y][x] = 'o';
				packman->setLeftFruit(packman->getLeftFruit() + 1);
				break;
			case '4':
				pellet[3]->setY(y);
				pellet[3]->setX(x);
				field_[y][x] = 'o';
				packman->setLeftFruit(packman->getLeftFruit() + 1);
				break;
			case '|':
				field_[y][x] = '|';
				break;
			case '$':
				field_[y][x] = '$';
				break;
			default:
				break;
			}
		}
	}

	for (int y = 0; y < FIELD_HEIGHT; ++y)
	{
		for (int x = 0; x < FIELD_WIDTH; ++x)
		{
			std::cout << fieldMap[x][y] << " ";
		}
	}
}

char Game::getField(int y, int x)
{
	return field_[y][x];
}