#include "Paddle.h"

Paddle::Paddle(const std::string& textureId, const Vector2& position, const Vector2& size, SDL_RendererFlip flip)
: Entity(textureId, position, size, flip), upPressed_(false), downPressed_(false)
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