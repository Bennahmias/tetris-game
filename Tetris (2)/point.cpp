#include<iostream>
#include "Point.h"
#include "general.h"
#include "key_identifier.h"


Point::Point(int _x, int _y): x(_x), y(_y) {} //the constactor 
//point need to have x and y cord 

void Point::setPoint(int _x, int _y){
	x = _x;
	y = _y;
}

int Point::getPoint_X()const {
	return x;
}
 
int Point::getPoint_Y()const {
	return y;
}

void Point::move(int direction)  
{
	switch (direction)
	{
	case (int)charkeys::RIGHT:
		++x;
		break;
	case (int)charkeys::LEFT:
		--x;
		break;
	case (int)charkeys::DOWN:
		++y; 
		break;
	default: //probebly will not happen ever 
		break;
	}
}

void Point::draw(int offset)const
{
	gotoxy(x + offset, y );
	std::cout << "#" ;
}

void Point::del_draw(int offset)const
{
	gotoxy(x + offset, y);
	std::cout << " ";
}



