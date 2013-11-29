#include "Wall.h"

const float Wall::WallSize = 20.f;

Wall::Wall(const std::string& textureId, const Vector2& position, const Vector2& size, SDL_RendererFlip flip)
: Entity(textureId, position, size, flip)
{

}

void Wall::handleInput(SDL_Event& event) {}
void Wall::update() {}

void Wall::render(RendererPtr& renderer, TextureManager& textureManager)
{
	textureManager.draw(textureId_, position_, size_, renderer, flip_);
}