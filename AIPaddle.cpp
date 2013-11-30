#include "AIPaddle.h"
#include "Game.h"

AIPaddle::AIPaddle(const std::string& textureId, const Vector2& position, const Vector2& size,
	EntityType type, std::unique_ptr<Entity>& ball, SDL_RendererFlip flip)
	: Paddle(textureId, position, size, type, flip), ball_(ball), Speed(2.f)
{

}

float AIPaddle::distanceToBall() const
{
	return sqrt((ball_->getPosition().getX() - position_.getX())*(ball_->getPosition().getX() - position_.getX())
		+ (ball_->getPosition().getY() - position_.getY())*(ball_->getPosition().getY() - position_.getY()));
}

void AIPaddle::handleInput(SDL_Event& event)
{

}

void AIPaddle::update()
{
	if (distanceToBall() <= Game::Width / 2)
	{
		std::cout << "In range" << std::endl;
		if (ball_->getPosition().getY() > position_.getY())
			velocity_.setY(Speed);
		else if (ball_->getPosition().getY() < position_.getY())
			velocity_.setY(-Speed);
	}

	position_ += velocity_;
}

void AIPaddle::render(RendererPtr& renderer, TextureManager& textureManager)
{
	Paddle::render(renderer, textureManager);
}

void AIPaddle::checkCollisions(std::vector<std::unique_ptr<Entity>>& entities)
{
	Paddle::checkCollisions(entities);
}