#include "Entity.h"

Entity::Entity(const std::string& textureId, const Vector2& position)
: textureId_(textureId), position_(position)
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