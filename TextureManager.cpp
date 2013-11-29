#include <SDL_image.h>

#include "TextureManager.h"

void TextureManager::addTexture(const std::string& fileName, const std::string& textureId,
	RendererPtr& renderer)
{
	SDL_Texture* texture = IMG_LoadTexture(renderer.get(), fileName.c_str());

	textures_[textureId] = texture;
}

void TextureManager::removeTexture(const std::string& textureId)
{
	if (textures_.find(textureId) != textures_.end())
	{
		SDL_DestroyTexture(textures_[textureId]);
		delete textures_[textureId];
		textures_.erase(textureId);
	}
}

void TextureManager::draw(const std::string& textureId, const Vector2& position, const Vector2& size,
	RendererPtr& renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w = size.getX();
	srcRect.h = destRect.h = size.getY();
	destRect.x = position.getX();
	destRect.y = position.getY();

	SDL_RenderCopyEx(renderer.get(), textures_[textureId], &srcRect, &destRect, 0, nullptr, flip);
}

void TextureManager::drawFrame(const std::string& textureId, const Vector2& position, const Vector2& size,
	int row, int frame, RendererPtr& renderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;

	srcRect.x = size.getX() * frame;
	srcRect.y = size.getY() * row;
	srcRect.w = destRect.w = size.getX();
	srcRect.h = destRect.h = size.getY();
	destRect.x = position.getX();
	destRect.y = position.getY();

	SDL_RenderCopyEx(renderer.get(), textures_[textureId], &srcRect, &destRect, 0, nullptr, flip);
}

TextureManager::~TextureManager()
{
	for (auto& pair : textures_)
	{
		SDL_DestroyTexture(pair.second);
	}

	textures_.clear();
}