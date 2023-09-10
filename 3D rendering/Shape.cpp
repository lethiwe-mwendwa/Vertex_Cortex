#include "Shape.h"
#include "Entities.h"
#include <iostream>

Shape::Shape()
{
	Entities.push_back(this);
}
