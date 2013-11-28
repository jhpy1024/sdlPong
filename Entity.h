#ifndef ENTITY_H
#define ENTITY_H

#include "Game.h"
#include "Vector2.h"

class Entity
{
public:
	Entity(const std::string& textureId, const Vector2& position = Vector2());

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void render(RendererPtr& renderer) = 0;

	Vector2 getPosition() const;
	Vector2 getVelocity() const;

private:
	Vector2 position_;
	Vector2 velocity_;

	std::string textureId_;
};

#endif