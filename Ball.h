#ifndef BALL_H
#define BALL_H

#include "Entity.h"

typedef std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> RendererPtr;

class Ball : public Entity
{
public:
	Ball(const std::string& textureId, const Vector2& position, const Vector2& size,
		SDL_RendererFlip flip = SDL_FLIP_NONE);

	void handleInput(SDL_Event& event) override;
	void update() override;
	void render(RendererPtr& renderer, TextureManager& textureManager) override;

private:
	Vector2 genRandomVelocity() const;
	void checkEdgeCollisions();

	static const float Speed;
};

#endif