#ifndef _SHAPE_H
#define _SHAPE_H

#include "point.h"
#include "key_identifier.h"

class Shape
{
private:
	Point data[(int)gameOption::SHAPE_SIZE]; //an array of 4 point -> a certain shape
	int rotationOps = 0;
	int shapeType = 0;

public:
	
	Shape(Point p1=Point(0,0), Point p2 = Point(0, 0), Point p3 = Point(0, 0), Point p4 = Point(0, 0)); //constructor
	Point* getData();   
	void setData(Point* data);
	void move(int direction); //move one shape
	void draw(int offset)const;
	void del_draw(int offset)const ;
	int getType()const;
	void setType(int type);
	int getRotation()const;
	void setRotation(int rotOps);
	void rotate(int direction);

	//rotate function for each shape
	void rotateL();
	void rotateS();
	void rotatePLUS();
	void rotateZ();
	void rotateJ();
	void rotateI();

	int getWeight()const;

};


#endif