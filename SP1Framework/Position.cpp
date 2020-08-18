#include "Position.h"

Position::Position(){
	x = 1;
	y = 1;
}

Position::~Position()
{

}

int Position::getX()
{
	return x;
}

int Position::getY()
{
	return y;
}

void Position::setX(int newX)
{
	x = newX;
}

void Position::setY(int newY)
{
	y = newY;
}