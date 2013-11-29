#ifndef ENTITY_H
#define ENTITY_H

#include <SDL.h>

#include <memory>

#include "Vector2.h"
#include "TextureManager.h"

typedef std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> RendererPtr;

class Entity
{
public:
	Entity(const std::string& textureId, const Vector2& position,
		const Vector2& size);

	virtual void handleInput() = 0;
	virtual void update() = 0;
	virtual void render(RendererPtr& renderer, TextureManager& textureManager) = 0;

	Vector2 getPosition() const;
	Vector2 getVelocity() const;
	Vector2 getSize() const;

protected:
	Vector2 position_;
	Vector2 velocity_;
	Vector2 size_;

	std::string textureId_;
};

#endif