#ifndef PADDLE_H
#define PADDLE_H

#include "Entity.h"

typedef std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> RendererPtr;

class Paddle : public Entity
{
public:
	Paddle() = default;
	Paddle(const std::string& textureId, const Vector2& position, const Vector2& size,
		EntityType type, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void handleInput(SDL_Event& event) override;
	void update() override;
	void render(RendererPtr& renderer, TextureManager& textureManager) override;

private:
	bool upPressed_;
	bool downPressed_;

	const float SPEED = 2.f;
};

#endif