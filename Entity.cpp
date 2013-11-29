#include "Entity.h"

Entity::Entity(const std::string& textureId, const Vector2& position, const Vector2& size,
	EntityType type, SDL_RendererFlip flip)
: textureId_(textureId), position_(position), size_(size), type_(type), flip_(flip)
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

EntityType Entity::getType() const
{
	return type_;
}