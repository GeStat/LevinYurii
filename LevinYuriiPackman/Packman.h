#pragma once
#include"Game.h"
#include"Constants.h"
class Packman
{
public:
	Packman(Game* const game);

	void move();
	void getDirection();//направение
	bool testForCollision();
	void printScore(); // печать очков
	void printLife(); //печать жизни
	void dead();
	void show();

	void setScore(int score);
	void setLives(int live);
	void setYInit(int y);
	void setXInit(int x);
	void setLeftFruit(int leftFruit);

	int getYInit(); 
	int getXInit();
	int getLeftFruit();

private:
	Game* game;
	int x_;
	int y_;
	int xOld_;
	int yOld_;
	int xInit_;
	int yInit_;
	int leftFruit_;
	int score_;
	int hisScore_;
	int lives_;
	char dir_;
	char dirOld_;
	char icon_;
};