#include "stdafx.h"
#include "Box.h"


Box::Box()
{
	srand(time(NULL));
	shape = rand() % 7;
	
}


Box::~Box()
{
}
