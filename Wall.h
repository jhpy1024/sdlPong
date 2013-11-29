#ifndef WALL_H
#define WALL_H

#include "Entity.h"

typedef std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> RendererPtr;

class Wall : public Entity
{
public:
	Wall() = default;
	Wall(const std::string& textureId, const Vector2& position, const Vector2& size,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void handleInput(SDL_Event& event) override;
	void update() override;
	void render(RendererPtr& renderer, TextureManager& textureManager) override;

	static const float WallSize;
};

#endif