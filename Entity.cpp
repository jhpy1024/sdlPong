#include "Entity.h"

Entity::Entity(const std::string& textureId, const Vector2& position, const Vector2& size)
: textureId_(textureId), position_(position), size_(size)
{

}

Vector2 Entity::getPosition() const
{
	return position_;
}

Vector2 Entity::getVelocity() const
{
	return velocity_;
}

Vector2 Entity::getSize() const
{
	return size_;
}