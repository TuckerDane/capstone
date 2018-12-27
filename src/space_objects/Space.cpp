/* ..............................................
  @file Space.cpp
  @author Tucker Walker (tuckerdwalker@gmail.com)
  @brief 
  @date 2018-12-26
  
  
.............................................. */
#include "Space.h"
#include <ctime>

using std::cout;
using std::endl;
using std::cin;

/* ..............................................
  @brief Construct a new Space:: Space object
  
.............................................. */
Space::Space()
{
	spaceName = "DEFAULT ROOM";

	setSpSize(21, 21);										// create a matrix of size 10x10

	space = new Object**[getSpSizeRow()];					// create an array (row sizeRow) of rows with pointers to Objects
	for (int i = 0; i < getSpSizeRow(); i++)				// fill array with columns (sizeColumn) of pointers to Objects
		space[i] = new Object*[getSpSizeCol()];

	// fill matrix with NULL values
	for (int i = 0; i < getSpSizeRow(); i++)				// i indicates the row
	{
		for (int j = 0; j < getSpSizeCol(); j++)			// j indicates the column
		{
			setSpPos(NULL, i, j);							// the object position at [sizeRow][sizeColumn] is set to NULL
		}
	}

	setDoors(false, false, false, false);
	setSpacePtrs(NULL, NULL, NULL, NULL);
}

/* ..............................................
  @brief Construct a new Space:: Space object
  
  @param sizeRow 
  @param sizeCol 
.............................................. */
Space::Space(int sizeRow, int sizeCol)
{
	setSpSize(sizeRow, sizeCol);						// Set Default Matrix Size

														// Allocate memory for the Matrix
	space = new Object**[getSpSizeRow()];				// create an array (row sizeRow) of rows with pointers to objects
	for (int i = 0; i < getSpSizeRow(); i++)			// fill array with columns (sizeColumn) of pointers to objects
		space[i] = new Object*[getSpSizeCol()];

	// Fill Default Matrix with NULL values
	for (int i = 0; i < getSpSizeRow(); i++)			// i indicates the row
	{
		for (int j = 0; j < getSpSizeCol(); j++)		// j indicates the column
		{
			setSpPos(NULL, i, j);						// the matrix position at [sizeRow][sizeColumn] is set to NULL
		}
	}
}

/* ..............................................
  @brief Destroy the Space:: Space object
  
.............................................. */
Space::~Space()
{

	for (int i = 0; i < spSizeRow; i++)					// destroys the values stored within the rows of matrix
	{
		for (int j = 0; j < spSizeCol; j++)				// destroys the values pointed to in each columnar position of a single row
		{
			if (space[i][j] == NULL)
			{
				delete space[i][j];						// destruction of the individual column value
			}
		}
		delete[] space[i];								// destruction of the row
	}
	delete space;										// destruction of the matrix itself

}

/* ..............................................
  @brief 
  
  @param sRow 
  @param sCol 
.............................................. */
void Space::setSpSize(int sRow, int sCol)
{
	spSizeRow = sRow;
	spSizeCol = sCol;
}

/* ..............................................
  @brief 
  
  @param o 
  @param row 
  @param col 
.............................................. */
void Space::setSpPos(Object *o, int row, int col)
{
	space[row][col] = o;
}

/* ..............................................
  @brief 
  
  @param leftD 
  @param rightD 
  @param topD 
  @param bottomD 
.............................................. */
void Space::setDoors(bool leftD, bool rightD, bool topD, bool bottomD)
{
	if (leftD == true)
	{
		// set left door
		leftDoor.setRowPos(this->getSpSizeRow() / 2);
		leftDoor.setColPos(0);
		setSpPos(&leftDoor, leftDoor.getRowPos(), leftDoor.getColPos());
	}

	if (rightD == true)
	{
		// set right door
		rightDoor.setRowPos(this->getSpSizeRow() / 2);
		rightDoor.setColPos(this->getSpSizeCol());
		setSpPos(&rightDoor, rightDoor.getRowPos(), rightDoor.getColPos() - 1);
	}

	if (topD == true)
	{
		// set top door
		topDoor.setRowPos(0);
		topDoor.setColPos(this->getSpSizeCol() / 2);
		setSpPos(&topDoor, topDoor.getRowPos(), topDoor.getColPos());
	}

	if (bottomD == true)
	{
		// set bottom door
		bottomDoor.setRowPos(this->getSpSizeRow());
		bottomDoor.setColPos(this->getSpSizeCol() / 2);
		setSpPos(&bottomDoor, bottomDoor.getRowPos() - 1, bottomDoor.getColPos());
	}
}

/* ..............................................
  @brief 
  
  @param t 
  @param b 
  @param l 
  @param r 
.............................................. */
void Space::setSpacePtrs(Space* t, Space* b, Space* l, Space* r)
{
	top = t;
	bottom = b;
	left = l;
	right = r;
}

/* ..............................................
  @brief 
  
  @param sn 
  @param p 
  @param l 
  @param r 
  @param t 
  @param b 
  @param o 
  @param num 
.............................................. */
void Space::setSpace(string sn, Player *p, Space *l, Space *r, Space *t, Space *b, Object *o, int num)
{
	spaceName = sn;
	spaceNum = num;
	spaceType = "DEFAULT";
	player = p;
	setDoors(!(l == NULL), !(r == NULL), !(t == NULL), !(b == NULL));
	top = t;
	bottom = b;
	left = l;
	right = r;
}

/* ..............................................
  @brief 
  
  @param d 
  @return Door* 
.............................................. */
Door* Space::getDoor(string d)
{
	if (d == "left")
	{
		return &leftDoor;
	}
	else if (d == "right")
	{
		return &rightDoor;
	}
	else if (d == "top")
	{
		return &topDoor;
	}
	else if (d == "bottom")
	{
		return &bottomDoor;
	}
	else
	{
		return NULL;
	}
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Space::getSpSizeRow()
{
	return spSizeRow;
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Space::getSpSizeCol()
{
	return spSizeCol;
}

/* ..............................................
  @brief 
  
  @return string 
.............................................. */
string Space::getSpaceName()
{
	return spaceName;
}

/* ..............................................
  @brief 
  
  @return int 
.............................................. */
int Space::getSpaceNum()
{
	return spaceNum;
}

/* ..............................................
  @brief 
  
  @return string 
.............................................. */
string Space::getSpaceType()
{
	return spaceType;
}

/* ..............................................
  @brief 
  
  @param row 
  @param col 
  @return Object* 
.............................................. */
Object* Space::getSpPos(int row, int col)
{
	if (space[row][col] == NULL)
	{
		return NULL;
	}
	else
		return space[row][col];		// return a pointer to the object at row, col
}

/* ..............................................
  @brief 
  
.............................................. */
void Space::printSpace()
{
	cout << endl << endl << endl;
	cout << "\t \t \t \t" << this->getSpaceName() << ": " << this->getSpaceType();
	cout << endl << endl << endl;

	for (int i = 0; i < getSpSizeRow(); i++)													// i indicates the row
	{
		cout << "\t \t \t";
		for (int j = 0; j < getSpSizeCol(); j++)												// j indicates the column
		{
			cout << " ";
			if (player->getColPos() == j && player->getRowPos() == i)								// if the player is there
			{
				cout << player->getSymbol();													// print the player
			}
			else if (getSpPos(i, j) != NULL)													// if there is an object
			{
				cout << this->space[i][j]->getSymbol();											// Print out the object's symbol
			}
			else if ((i == 0 && j == 0) || (i == getSpSizeRow()-1 && j == getSpSizeCol()-1))	// if top left corner wall or bottom right corner wall
			{
				cout << '+';																	// print "/"
			}
			else if ((i == 0 && j == getSpSizeCol()-1) || (i == getSpSizeRow()-1 && j == 0))	// if top right corner wall or bottom left corner wall
			{
				cout << '+';																	// print "\"
			}
			else if (i == 0 || i == getSpSizeRow()-1)											// if top wall or bottom wall
			{
				cout << '-';																	// print "-"
			}
			else if (j == 0 || j == getSpSizeCol()-1)											// if left wall or right wall
			{
				cout << '|';																	// print "|"
			}
			else if (getSpPos(i, j) == NULL)													// if cell is empty
				cout << ' ';																	// print " "
			else																				// else there is an error
				cout << '!';																	// print error symbol
		}
		cout << endl;
	}

	cout << endl << endl << endl;
}

/* ..............................................
  @brief 
  
  @param dir 
  @return true 
  @return false 
.............................................. */
bool Space::movePlayer(char dir)
{
		if (dir == 'w' || dir == 'W')										// move tucker up
		{
			if (enterDoorway(dir) == false)
			{
				if (player->getRowPos() - 1 != 0)							// if tucker doesn't run into a wall
				{
					player->setRowPos((player->getRowPos() - 1));			// move tucker up
				}
				player->setSymbol('^');
			}
		}
		else if (dir == 's' || dir == 'S')									// move tucker down
		{
			if (enterDoorway(dir) == false)
			{
				if ((player->getRowPos() + 1) != this->getSpSizeRow() - 1)	// if tucker doesn't run into a wall
				{
					player->setRowPos((player->getRowPos() + 1));			// move tucker down
				}
				player->setSymbol('v');
			}
		}
		else if (dir == 'a' || dir == 'A')									// move tucker left
		{
			if (enterDoorway(dir) == false)
			{
				if ((player->getColPos() - 1) != 0)							// if tucker doesn't run into a wall
				{
					player->setColPos((player->getColPos() - 1));			// move tucker left
				}
				player->setSymbol('<');
			}
		}
		else if (dir == 'd' || dir == 'D')									// move tucker right
		{
			if (enterDoorway(dir) == false)
			{
				if ((player->getColPos() + 1) != this->getSpSizeCol() - 1)	// if tucker doesn't run into a wall
				{
					player->setColPos((player->getColPos() + 1));			// move tucker right
				}
				player->setSymbol('>');
			}
		}
		return true;
}

/* ..............................................
  @brief 
  
  @param dir 
  @return true 
  @return false 
.............................................. */
bool Space::enterDoorway(char dir)
{
	if (dir == 'w' || dir == 'W')																		// if tucker moves up
	{
		if (this->getSpPos(player->getRowPos() - 1, player->getColPos()) != NULL)						// and if tucker encounters an open door
		{
			if (this->getSpPos(player->getRowPos() - 1, player->getColPos())->getSymbol() == ' ')
			{
				player->setPlayerRoom(top->getSpaceName(), top->getSpaceNum());							// change rooms
				player->setRowPos(top->getSpSizeRow()-2);
				player->setColPos(top->getSpSizeCol()/2);
				player->setSymbol('^');
				return true;
			}
		}
	}
	else if (dir == 's' || dir == 'S')																	// if tucker moves down
	{
		if (this->getSpPos(player->getRowPos() + 1, player->getColPos()) != NULL)						// and if tucker encounters an open door
		{
			if (this->getSpPos(player->getRowPos() + 1, player->getColPos())->getSymbol() == ' ')
			{
				player->setPlayerRoom(bottom->getSpaceName(), bottom->getSpaceNum());					// change rooms
				player->setRowPos(1);
				player->setColPos(bottom->getSpSizeCol() / 2);
				player->setSymbol('v');
				return true;
			}
		}
	}
	else if (dir == 'a' || dir == 'A')																	// if tucker moves left
	{
		if (this->getSpPos(player->getRowPos(), player->getColPos() - 1) != NULL)						// and if tucker encounters an open door
		{
			if (this->getSpPos(player->getRowPos(), player->getColPos()-1)->getSymbol() == ' ')
			{
				player->setPlayerRoom(left->getSpaceName(), left->getSpaceNum());						// change rooms
				player->setRowPos(left->getSpSizeRow()/2);
				player->setColPos(left->getSpSizeCol() - 2);
				player->setSymbol('<');
				return true;
			}
		}
	}
	else if (dir == 'd' || dir == 'D')																	// if tucker moves right
	{
		if (this->getSpPos(player->getRowPos(), player->getColPos() + 1) != NULL)						// and if tucker encounters an open door
		{
			if (this->getSpPos(player->getRowPos(), player->getColPos()+1)->getSymbol() == ' ')
			{
				player->setPlayerRoom(right->getSpaceName(), right->getSpaceNum());						// change rooms
				player->setRowPos(right->getSpSizeRow() / 2);
				player->setColPos(1);
				player->setSymbol('>');
				return true;
			}
		}
	}

	return false;
}
