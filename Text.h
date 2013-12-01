#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include <SDL_ttf.h>

#include <string>
#include <memory>

#include "Vector2.h"

typedef std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> RendererPtr;

class Text
{
public:
	Text(RendererPtr& renderer);

	Text& setContents(const std::string& contents);
	Text& setPosition(const Vector2& position);
	Text& setFont(const std::string& font);
	Text& setColor(SDL_Color color);
	Text& setSize(int size);
	void create();

	void render();

private:
	RendererPtr& renderer_;

	std::unique_ptr<SDL_Texture, void(*)(SDL_Texture*)> texture_;

	std::string contents_;
	std::string fontName_;

	SDL_Color color_;

	int size_;

	Vector2 position_;
};

#endif