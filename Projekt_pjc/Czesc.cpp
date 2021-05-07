#include "Czesc.h"

Czesc::Czesc()
{
	this->pozycja_x = 0;
	this->pozycja_y = 0;
}

Czesc::~Czesc()
{
}

void Czesc::set_Position(float x, float y)
{
	this->pozycja_x = x;
	this->pozycja_y = y;
}

float Czesc::get_Position_x() const
{
	return this->pozycja_x;
}

float Czesc::get_Position_y() const
{
	return this->pozycja_y;
}

