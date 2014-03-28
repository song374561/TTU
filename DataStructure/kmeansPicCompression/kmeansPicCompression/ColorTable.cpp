#include "ColorTable.h"

ColorTable::ColorTable() :next(nullptr)
{
}

ColorTable::ColorTable(unsigned char newBlue, unsigned char newGreen, unsigned char newRed, int newLocation)
{
	blue = newBlue;
	green = newGreen;
	red = newRed;
	location = newLocation;
	next = nullptr;
}

void ColorTable::setBlue(unsigned char newBlue)
{
	blue = newBlue;
}

void ColorTable::setGreen(unsigned char newGreen)
{
	green = newGreen;
}

void ColorTable::setRed(unsigned char newRed)
{
	red = newRed;
}

void ColorTable::setNext(ColorTable* newNext)
{
	next = newNext;
}
void ColorTable::setLocation(int newLocation)
{
	location = newLocation;
}
unsigned char ColorTable::getBlue(void)
{
	return blue;
}

unsigned char ColorTable::getGreen(void)
{
	return green;
}

unsigned char ColorTable::getRed(void)
{
	return red;
}

ColorTable* ColorTable::getNext(void)
{
	return next;
}

int ColorTable::getLocation(void)
{
	return location;
}