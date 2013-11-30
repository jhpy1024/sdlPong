#ifndef BALL_H
#define BALL_H

#include "Entity.h"

typedef std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> RendererPtr;

class Ball : public Entity
{
public:
	Ball(const std::string& textureId, const Vector2& position, const Vector2& size,
		EntityType type, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void handleInput(SDL_Event& event) override;
	void update() override;
	void render(RendererPtr& renderer, TextureManager& textureManager) override;
	void checkCollisions(std::vector<std::unique_ptr<Entity>>& entities) override;

	int getHitLeftCount() const;
	int getHitRightCount() const;

private:
	Vector2 genRandomVelocity() const;
	void checkEdgeCollisions();

	int hitRightCount_;
	int hitLeftCount_;

	static const float Speed;
};

#endif