#include "shape.h"

Shape::Shape(Point p1, Point p2, Point p3 , Point p4) : data{p1, p2, p3, p4} {} //constractor

void Shape::move(int direction) 
//the board is checking everything, in shape we dont check, checking is not a responsibility of shape
{
		for (auto &i : data)
		{
			i.move(direction); 
		}
}

Point* Shape::getData()
{
	return data;
}

void Shape::setData(Point* arr)
{
	for (int i=0;i< (int)gameOption::SHAPE_SIZE;i++)
	{
		data[i].setPoint(arr[i].getPoint_X(), arr[i].getPoint_Y()); //update the data aka the arr of points
	}
}

void Shape::draw(int offset) const 
{
	for (auto &i : data)
	{
		i.draw(offset);
	}
}

void Shape::del_draw(int offset)const 
{
	for (auto& i : data)
	{
		i.del_draw(offset);
	}
}

int Shape::getType()const
{
	return shapeType;
}

void Shape::setType(int type)
{
	shapeType = type;
}

int Shape::getRotation()const
{
	return rotationOps;
}

void Shape::setRotation(int rotOps)
{
	rotationOps = rotOps;
}

void Shape::rotate(int direction)
{
	if (direction == (int)charkeys::CLOCKWISE)
		rotationOps = (rotationOps + 1) % (int)gameOption::SHAPE_SIZE; //update clockwise 1 step
	else
		rotationOps = (rotationOps + 3) % (int)gameOption::SHAPE_SIZE; //update counter clockwise 1 step (because of the modulue its like 1 step left)

	switch (shapeType)
	{
	case (int)shapeTypes::S_SHAPE:
		rotateS();
		break;
	case (int)shapeTypes::PLUS_SHAPE:
		rotatePLUS();
		break;
	case (int)shapeTypes::L_SHAPE:
		rotateL();
		break;
	case (int)shapeTypes::I_SHAPE:
		rotateI();
		break;
	case (int)shapeTypes::Z_SHAPE:
		rotateZ();
		break;
	case (int)shapeTypes::J_SHAPE:
		rotateJ();
		break;
	case (int)shapeTypes::O_SHAPE:
	case (int)shapeTypes::BOMB_SHAPE:
		//do nothing
		break;
	
	default:
		break;
	}
}

void Shape::rotateL()
{	//get the center point 
	int x = data[3].getPoint_X();
	int y = data[3].getPoint_Y();
	switch (rotationOps)
	{

		//original 
	case(0):
		data[0].setPoint(x, y + 1);
		data[1].setPoint(x + 1, y);
		data[2].setPoint(x + 2, y);
		break;
	case(1): //90 degree
		data[0].setPoint(x + 1, y);
		data[1].setPoint(x, y - 1);
		data[2].setPoint(x, y - 2);
		break;

	case(2)://180 degree
		data[0].setPoint(x, y - 1);
		data[1].setPoint(x - 1, y);
		data[2].setPoint(x - 2, y);
		break;

	case(3)://270 degree
		data[0].setPoint(x - 1, y);
		data[1].setPoint(x, y + 1);
		data[2].setPoint(x, y + 2);
		break;
	default:
		break;
	}
}
void Shape::rotateS()
{	//get the center point 
	int x = data[3].getPoint_X();
	int y = data[3].getPoint_Y();
	switch (rotationOps)
	{

		//original 
	case(0):
		data[0].setPoint(x - 1, y);
		data[1].setPoint(x, y - 1);
		data[2].setPoint(x + 1, y - 1);
		break;
	case(1): //90 degree
		data[0].setPoint(x, y + 1);
		data[1].setPoint(x - 1, y);
		data[2].setPoint(x - 1, y - 1);
		break;

	case(2)://180 degree
		data[0].setPoint(x + 1, y);
		data[1].setPoint(x, y + 1);
		data[2].setPoint(x - 1, y + 1);
		break;

	case(3)://270 degree
		data[0].setPoint(x, y - 1);
		data[1].setPoint(x + 1, y);
		data[2].setPoint(x + 1, y + 1);
		break;
	default:
		break;
	}
}
void Shape::rotatePLUS()
{	//get the center point 

	int x = data[3].getPoint_X();
	int y = data[3].getPoint_Y();
	switch (rotationOps)
	{


		//original 
	case(0):
		data[0].setPoint(x - 1, y);
		data[1].setPoint(x, y - 1);
		data[2].setPoint(x + 1, y);
		break;
	case(1): //90 degree
		data[0].setPoint(x, y + 1);
		data[1].setPoint(x - 1, y);
		data[2].setPoint(x, y - 1);
		break;

	case(2)://180 degree
		data[0].setPoint(x + 1, y);
		data[1].setPoint(x, y + 1);
		data[2].setPoint(x - 1, y);
		break;

	case(3)://270 degree
		data[0].setPoint(x, y - 1);
		data[1].setPoint(x + 1, y);
		data[2].setPoint(x, y + 1);
		break;
	default:
		break;
	}
}
void Shape::rotateZ()
{
	//get the center point 
	int x = data[3].getPoint_X(); 
	int y = data[3].getPoint_Y();
	switch (rotationOps)
	{

		//original 
	case(0):
		data[0].setPoint(x - 1, y - 1);
		data[1].setPoint(x, y - 1);
		data[2].setPoint(x + 1, y);
		break;
	case(1): //90 degree
		data[0].setPoint(x - 1, y + 1);
		data[1].setPoint(x - 1, y);
		data[2].setPoint(x, y - 1);
		break;

	case(2)://180 degree
		data[0].setPoint(x + 1, y + 1);
		data[1].setPoint(x, y + 1);
		data[2].setPoint(x - 1, y);
		break;

	case(3)://270 degree
		data[0].setPoint(x + 1, y - 1);
		data[1].setPoint(x + 1, y);
		data[2].setPoint(x, y + 1);
		break;
	default:
		break;
	}
}
void Shape::rotateJ()
{	//get the center point 

	int x = data[3].getPoint_X();
	int y = data[3].getPoint_Y();
	switch (rotationOps)
	{

		//original 
	case(0):
		data[0].setPoint(x - 2, y);
		data[1].setPoint(x - 1, y);
		data[2].setPoint(x, y + 1);
		break;
	case(1): //90 degree
		data[0].setPoint(x, y + 2);
		data[1].setPoint(x, y + 1);
		data[2].setPoint(x + 1, y);
		break;

	case(2)://180 degree
		data[0].setPoint(x + 2, y);
		data[1].setPoint(x + 1, y);
		data[2].setPoint(x, y - 1);
		break;

	case(3)://270 degree
		data[0].setPoint(x, y - 2);
		data[1].setPoint(x, y - 1);
		data[2].setPoint(x - 1, y);
		break;
	default:
		break;
	}
}
void Shape::rotateI()
{	//get the center point 

	int x = data[3].getPoint_X();
	int y = data[3].getPoint_Y();
	switch (rotationOps)
	{

		//original 
	case(0):
		data[0].setPoint(x - 1, y);
		data[1].setPoint(x + 1, y);
		data[2].setPoint(x + 2, y);
		break;
	case(1): //90 degree
		data[0].setPoint(x, y + 1);
		data[1].setPoint(x, y - 1);
		data[2].setPoint(x, y - 2);
		break;

	case(2)://180 degree
		data[0].setPoint(x + 1, y);
		data[1].setPoint(x - 1, y);
		data[2].setPoint(x - 2, y);
		break;

	case(3)://270 degree
		data[0].setPoint(x, y - 1);
		data[1].setPoint(x, y + 1);
		data[2].setPoint(x, y + 2);
		break;
	default:
		break;
	}
}

int Shape::getWeight()const
{
	int sumHight = 0;

	for (int i = 0; i < 3; i++)
	{
		sumHight += data[i].getPoint_Y();
	}
	return sumHight;
}
