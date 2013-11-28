#ifndef GAME_H
#define GAME_H

#include <SDL.h>

#include <memory>
#include <string>

class Game
{
public:
	Game(int width, int height, const std::string& title);

	void handleInput();
	void update();
	void render();

	bool isRunning() const;

	int getWidth() const;
	int getHeight() const;

private:
	void initSDL();

private:
	std::unique_ptr<SDL_Window, void(*)(SDL_Window*)> window_;
	std::unique_ptr<SDL_Renderer, void(*)(SDL_Renderer*)> renderer_;

	int width_;
	int height_;
	std::string title_;

	bool running_;
};

#endif