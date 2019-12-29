#pragma once
#include"Game.h"
class Ghost
{
public:
	Ghost(Game* const game);
	void move(int x, int y);
	void randomDirection();
	bool testForCollision();
	void dead();
	void show();
	void hide();

	void setYInit(int yInit);
	void setXInit(int xInit);

	int getXInit();
	int getYInit();

private:

	int x_;
	int y_;
	int xInit_;
	int yInit_;
	char icon_;
	Game* game_;
};