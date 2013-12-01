#include "Text.h"

Text::Text(RendererPtr& renderer) : renderer_(renderer), texture_(nullptr, SDL_DestroyTexture)
{

}

Text& Text::setContents(const std::string& contents)
{
	contents_ = contents;
	return *this;
}

Text& Text::setPosition(const Vector2& position)
{
	position_ = position;
	return *this;
}

Text& Text::setFont(const std::string& font)
{
	fontName_ = font;
	return *this;
}

Text& Text::setColor(SDL_Color color)
{
	color_ = color;
	return *this;
}

Text& Text::setSize(int size)
{
	size_ = size;
	return *this;
}

void Text::create()
{
	if (TTF_WasInit() == 0)
		TTF_Init();

	TTF_Font* font = TTF_OpenFont(fontName_.c_str(), size_);
	SDL_Surface* text = TTF_RenderText_Solid(font, contents_.c_str(), color_);

	texture_.reset(SDL_CreateTextureFromSurface(renderer_.get(), text));
}

void Text::render()
{
	SDL_Rect srcRect;
	srcRect.x = srcRect.y = 0;
	SDL_QueryTexture(texture_.get(), nullptr, nullptr, &srcRect.w, &srcRect.h);

	SDL_Rect dstRect = { position_.getX(), position_.getY(), srcRect.w, srcRect.h };

	SDL_RenderCopy(renderer_.get(), texture_.get(), &srcRect, &dstRect);
}

void Text::changeContents(const std::string& contents)
{
	contents_ = contents;
	create();
}

void Text::changeSize(int size)
{
	size_ = size;
	create();
}

void Text::changeColor(SDL_Color color)
{
	color_ = color;
	create();
}

void Text::changePosition(const Vector2& position)
{
	position_ = position;
	create();
}

void Text::changeFont(const std::string& font)
{
	fontName_ = font;
	create();
}