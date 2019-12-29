#include"Packman.h"
#include<Windows.h>
#include<conio.h>
#include<iostream>

void Packman::show()
{
	COORD cursor = { x_, y_ + 3 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
	std::cout << icon_;
}

void Packman::setScore(int score)
{
	score_ = score;
}

void Packman::setLives(int lives)
{
	lives_ = lives;
}

void Packman::setXInit(int xInit) 
{
	xInit_ = xInit;
}
void Packman::setYInit(int yInit)
{
	yInit_ = yInit;
}
void Packman::setLeftFruit(int leftFruit)
{
	leftFruit_ = leftFruit;
}

int Packman::getXInit()
{
	return xInit_;
}
int Packman::getYInit()
{
	return yInit_;
}

int Packman::getLeftFruit()
{
	return leftFruit_; 
}

Packman::Packman() 
{
	hisScore_ = 0;
}

void Packman::move()
{
	getDirection();
	if (testForCollision() == false)
	{
		COORD cursor = { xOld_, yOld_ + 3 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
		std::cout << game->getField(yOld_, xOld_);
		
		if (game->getField(y_, x_) != ' ')
		{
			int score;
			if (game->getField(y_, x_) == 'o')
			{
				score = 50;

			}
			else
			{
				score = 10;
			}
			game->eatPellet(y_, x_, ' ');
			--leftFruit_;
		}
		show();
		dirOld_ = dir_;
	}
}

void Packman::getDirection()
{
	dir_ = 'x';
	if (_kbhit())
	{
		dir_ = tolower(_getch());
	}
	if (!strchr(ALL_BUTTONS, dir_))
	{
		dir_ = dirOld_;
	}
}

bool Packman::testForCollision()
{
	xOld_ = x_;
	yOld_ = y_;
	switch (dir_)
	{
	case 'a':
		if (x_ == 0)
		{
			x_ = FIELD_WIDTH - 1;
			icon_ = PACKMAN_ICONS[1];

		}
		else if (strchr(NO_COLLISION_TILES, game->getField(y_, x_ - 1))) 
		{
			--x_;
			icon_ = PACKMAN_ICONS[1];
		}
		break;
	case 'd':
		if (x_ == FIELD_HEIGHT - 1)
		{
			x_ = 0;
			icon_ = PACKMAN_ICONS[3];
		}
		else if (strchr(NO_COLLISION_TILES, game->getField(y_, x_ + 1)))
		{
			++x_;
			icon_ = PACKMAN_ICONS[3];
		}
		break;
	case 'w':
		if (strchr(NO_COLLISION_TILES, game->getField(y_ - 1, x_))) {
			--y_;
			icon_ = PACKMAN_ICONS[0];
		}
		break;
	case 's':
		if (strchr(NO_COLLISION_TILES, game->getField(y_ + 1, x_))) {
			++y_;
			icon_ = PACKMAN_ICONS[2];
		}
	default:
		break;
	}
	if (x_ == xOld_ && y_ == yOld_) {
		return true;
	}
	return false;
}
