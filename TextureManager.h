#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SDL.h>

#include <string>
#include <map>
#include <memory>

#include "Vector2.h"

typedef std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> WindowPtr;
typedef std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> RendererPtr;

class TextureManager
{
public:
	void addTexture(const std::string& fileName, const std::string& textureId,
		RendererPtr& renderer);
	void removeTexture(const std::string& textureId);

	void draw(const std::string& textureId, const Vector2& position, const Vector2& size,
		RendererPtr& renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(const std::string& textureId, const Vector2& position, const Vector2& size,
		int row, int frame, RendererPtr& renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	~TextureManager();

private:
	std::map<std::string, SDL_Texture*> textures_;
};

#endif