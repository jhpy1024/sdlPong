#include "Paddle.h"

Paddle::Paddle(const std::string& textureId, const Vector2& position, const Vector2& size)
: Entity(textureId, position, size)
{

}

void Paddle::handleInput()
{

}

void Paddle::update()
{
	
}

void Paddle::render(RendererPtr& renderer, TextureManager& textureManager)
{
	textureManager.draw(textureId_, position_, size_, renderer, SDL_FLIP_NONE);
}