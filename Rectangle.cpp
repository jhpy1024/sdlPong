#include "Rectangle.h"

Rectangle::Rectangle(const Vector2& position_, const Vector2& size_)
: position(position_), size(size_)
{

}

bool Rectangle::intersects(const Rectangle& rect)
{
	return (abs(position.getX() - rect.position.getX()) * 2 <= (size.getX() + rect.size.getX()) &&
			(abs(position.getY() - rect.position.getY()) * 2 < (size.getY() + rect.size.getY())));
}