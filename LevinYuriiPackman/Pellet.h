#pragma once
#include"Game.h"
class Pellet
{
public:
	Pellet(Game* const game);
	void print();

	void setX(int x);
	void setY(int y);


private:
	Game* game_;
	int x_;
	int y_;
};