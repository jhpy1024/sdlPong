#ifndef AI_PADDLE_H
#define AI_PADDLE_H

#include "Paddle.h"

class AIPaddle : public Paddle
{
public:
	AIPaddle(const std::string& textureId, const Vector2& position, const Vector2& size,
		EntityType type, std::unique_ptr<Entity>& ball, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void handleInput(SDL_Event& event) override;
	void update() override;
	void render(RendererPtr& renderer, TextureManager& textureManager) override;
	void checkCollisions(std::vector<std::unique_ptr<Entity>>& entities) override;

private:
	std::unique_ptr<Entity>& ball_;

	float distanceToBall() const;

	const float Speed;
};

#endif