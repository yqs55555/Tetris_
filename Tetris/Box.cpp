#include "stdafx.h"
#include "Box.h"


Box::Box(int type)
{
	srand(time(NULL));
	
}


Box::~Box()
{

}

//---
void Box::Make_1()
{
	_data[1][0] = _data[1][1] = _data[1][2] = _data[1][3] = 1;
}

//[ ]
void Box::Make_2()
{
	_data[1][1] = _data[1][2] = _data[2][1] = _data[2][2] = 1;
}
// p
void Box::Make_3()
{
	_data[1][1] = _data[1][2] = _data[2][1] = _data[3][1] = 1;
}
// q
void Box::Make_4()
{
	_data[1][0] = _data[1][1] = _data[2][1] = _data[3][1] = 1;
}
// Z
void Box::Make_5()
{
	_data[1][0] = _data[1][1] = _data[2][1] = _data[2][2] = 1;
}
// op_z
void Box::Make_6()
{
	_data[2][0] = _data[2][1] = _data[1][1] = _data[1][2] = 1;
}

void Box::Make_7()
{
	_data[2][0] = _data[2][1] = _data[2][2] = _data[1][1] = 1;
}
