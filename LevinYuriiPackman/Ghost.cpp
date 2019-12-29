#include"Ghost.h"

void Ghost::setYInit(int yInit)
{
	yInit_ = yInit;
}

void Ghost::setXInit(int xInit)
{
	xInit_ = xInit;
}

int Ghost::getYInit()
{
	return yInit_;
}

int Ghost::getXInit()
{
	return xInit_;
}

Ghost::Ghost(Game* const game): game_(game) 
{

}
