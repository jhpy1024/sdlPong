#include "Rectangle.h"

Rectangle::Rectangle(const Vector2& position_, const Vector2& size_)
: position(position_), size(size_)
{

}

bool Rectangle::intersects(const Rectangle& rect)
{
	return !(rect.position.getX() > position.getX() + size.getX() ||
		rect.position.getX() + rect.size.getX() < position.getX() ||
		rect.position.getY() > position.getY() + size.getY()	  ||
		rect.position.getY() + rect.size.getY() < position.getX());
}