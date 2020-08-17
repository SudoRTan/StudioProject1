#pragma once
class Position
{
public:
	int getX();
	int getY();
	void setX(int newX);
	void setY(int newY);
private:
	int x;
	int y;
};