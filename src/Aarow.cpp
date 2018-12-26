/*
	Name:			Tucker Dane Walker
	Date:			09 December 2016
	Description:	The Aarow Class
*/

#include "Aarow.h"

/* 
	default constructor for Aarow
*/
Aarow::Aarow() : Object(':', "Silver", 3, 3, "Aarow")
{
	this->weight = 2;
}

/*
	constructor for Aarow initializing rowPos and colPos
*/
Aarow::Aarow(int row, int col) : Object(':', "Generic", row, col, "Aarow")
{
	weight = 2;
}

/*
	deconstructor for Aarow
*/
Aarow::~Aarow()
{
}

/*
	sets its position
*/
void Aarow::setPosition(int row, int col)
{
	this->setRowPos(row);
	this->setColPos(col);
}

/*
	returns the weight of the object
*/
int Aarow::getWeight()
{
	return weight;
}

/*
	returns the name of the Object
*/
string Aarow::getName()
{
	return name;
}

/*
	returns the weight of the object
*/
void Aarow::setWeight(int w)
{
	weight = w;
}