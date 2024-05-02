#ifndef _POINT_H
#define _POINT_H

class Point
{
private:
	int x; int y; //cord	

public:

	Point(int _x, int _y); //constractor 

	void setPoint(int _x, int _y); // setter of point 

	//getters of the value of x and y 
	int getPoint_X()const;
	int getPoint_Y()const;

	void move(int direction); //move one point

	void draw(int offset)const; //print one point
	void del_draw(int offset)const; //delete one point

};



#endif