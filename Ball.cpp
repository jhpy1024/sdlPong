#include <ctime>
#include <random>

#include "Ball.h"
#include "Game.h"
#include "Wall.h"

const float Ball::Speed = 3.f;

Ball::Ball(const std::string& textureId, const Vector2& position, const Vector2& size,
	EntityType type, SDL_RendererFlip flip)
: Entity(textureId, position, size, type, flip)
{
	velocity_ = genRandomVelocity();
}

void Ball::handleInput(SDL_Event& event) {}

void Ball::checkEdgeCollisions()
{
	if (position_.getX() <= Wall::WallSize)
		velocity_.setX(-velocity_.getX());
	if (position_.getX() >= Game::Width - Wall::WallSize - size_.getX())
		velocity_.setX(-velocity_.getX());
	if (position_.getY() <= Wall::WallSize)
		velocity_.setY(-velocity_.getY());
	if (position_.getY() >= Game::Height - Wall::WallSize - size_.getY())
		velocity_.setY(-velocity_.getY());
}

void Ball::checkCollisions(std::vector<std::unique_ptr<Entity>>& entities)
{

}

void Ball::update()
{
	checkEdgeCollisions();

	position_ += velocity_ * Speed;
}

void Ball::render(RendererPtr& renderer, TextureManager& textureManager)
{
	textureManager.draw(textureId_, position_, size_, renderer, flip_);
}

Vector2 Ball::genRandomVelocity() const
{
	Vector2 vec;

	static std::default_random_engine engine;
	engine.seed(time(nullptr));
	static std::bernoulli_distribution distribution;

	vec.setX(distribution(engine) ? 1 : -1);
	vec.setY(distribution(engine) ? 1 : -1);

	return vec;
}