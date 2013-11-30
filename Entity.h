#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>

#include <memory>
#include <vector>

#include "Vector2.h"
#include "TextureManager.h"
#include "Rectangle.h"

typedef std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> RendererPtr;

enum class EntityType
{
	Ball,
	Paddle,
	Wall
};

class Entity
{
public:
	Entity() = default;
	Entity(const std::string& textureId, const Vector2& position,
		const Vector2& size, EntityType type, SDL_RendererFlip flip = SDL_FLIP_NONE);

	virtual void handleInput(SDL_Event& event) = 0;
	virtual void update() = 0;
	virtual void render(RendererPtr& renderer, TextureManager& textureManager) = 0;
	virtual void checkCollisions(std::vector<std::unique_ptr<Entity>>& entities) = 0;

	Vector2 getPosition() const;
	Vector2 getVelocity() const;
	Vector2 getSize() const;
	EntityType getType() const;
	Rectangle getBounds() const;

protected:
	void updateBounds();

	Vector2 position_;
	Vector2 velocity_;
	Vector2 size_;

	Rectangle bounds_;

	EntityType type_;

	SDL_RendererFlip flip_;

	std::string textureId_;
};

#endif