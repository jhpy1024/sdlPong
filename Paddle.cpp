#include "Paddle.h"
#include "Wall.h"
#include "Game.h"

Paddle::Paddle(const std::string& textureId, const Vector2& position, const Vector2& size,
	EntityType type, SDL_RendererFlip flip)
: Entity(textureId, position, size, type, flip), upPressed_(false), downPressed_(false)
{

}

void Paddle::handleInput(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		SDL_Keycode key = event.key.keysym.sym;

		switch (key)
		{
		case SDLK_UP:
			upPressed_ = true;
			break;
		case SDLK_DOWN:
			downPressed_ = true;
			break;
		default:
			break;
		}
	}
	else if (event.type == SDL_KEYUP)
	{
		SDL_Keycode key = event.key.keysym.sym;

		switch (key)
		{
		case SDLK_UP:
			upPressed_ = false;
			break;
		case SDLK_DOWN:
			downPressed_ = false;
			break;
		default:
			break;
		}
	}
}

void Paddle::update()
{
	if (position_.getY() < Wall::WallSize)
		position_.setY(Wall::WallSize);
	if (position_.getY() > Game::Height - Wall::WallSize - size_.getY())
		position_.setY(Game::Height - Wall::WallSize - size_.getY());

	if (upPressed_)
		velocity_.setY(-SPEED);
	else if (downPressed_)
		velocity_.setY(SPEED);
	else
		velocity_.setY(0);

	position_ += velocity_;
}

void Paddle::render(RendererPtr& renderer, TextureManager& textureManager)
{
	textureManager.draw(textureId_, position_, size_, renderer, flip_);
}

void Paddle::checkCollisions(std::vector<std::unique_ptr<Entity>>& entities)
{
	updateBounds();
}