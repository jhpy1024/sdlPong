#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Vector2.h"

class Rectangle
{
public:
	Rectangle(const Vector2& position = Vector2(), const Vector2& size = Vector2());

	bool intersects(const Rectangle& rect);

	Vector2 position;
	Vector2 size;
};

#endif